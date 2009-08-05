/**
  * mainWindow.ui.h
  * Operation code for the main display form.
  */

/**
  * Multilife
  * A Multi-species variant of Conway's Game of Life
  * 
  * Copyright (C) 2009 Joel Murphy, Ba Nguyen
  * All rights reserved
  * Licensed under the GNU Public License, v2. Full text of license can be found
  * in gpl-2.0.txt.
  */

#ifndef MAINWINDOW_UI_H
#define MAINWINDOW_UI_H

void mainWindow::init()
{
    this->engine = new Life(60, 60);
    this->selectedCritterType = &this->engine->getCritterType(0);
    this->checkOn = QColor::QColor(255,127,0);
    this->checkOff = observeCheck1->paletteBackgroundColor();
    this->updateTools();
    timer = new LifeTimer(this);
    running = false;
    ageLabel1 = new QLabel("Age", this);
    ageLabel1->setGeometry(510, 365, 30, 30);
    ageLabel2 = new QLabel("0", this);
    ageLabel2->setGeometry(545, 365, 40, 30); 
    slider = new QSlider(100, 400, 10, 300, QSlider::Horizontal, this);
    slider->setGeometry(500, 400, 100, 30);
    connect(timer, SIGNAL(timeout()), this, SLOT(ageSlot())); //activates ageslot upon selectio
    connect( slider, SIGNAL(valueChanged(int)), timer,  SLOT(setSpeed(int)) );

    //cursor->initialize();
    //framePaint->setCursor(IbeamCursor);
    /*
    QBitmap  cb = QBitmap(cb_width, cb_height, cb_bits, TRUE);
    QBitmap  cm = QBitmap(cm_width, cm_height, cm_bits, TRUE);
    QCursor cursor = QCursor(cb,32,32);
    framePaint->setCursor(cursor);  */
    
    QImage img(pen_xpm);
    QPixmap pixmap;
    pixmap.convertFromImage(img); //loading in image pixmap
    QCursor cursor = QCursor(pixmap,0,32);
    framePaint->setCursor(cursor);
    
     //pixmap.convertFromImage(image, OrderedAlphaDither);
    
}

void mainWindow::closeEvent( QCloseEvent * )
{
    fileExit();
}

void mainWindow::fileExit()
{
    delete engine;
    engine = NULL;
    delete framePaint;
    framePaint = NULL;
    delete slider;
    delete timer;
    delete ageLabel1;
    delete ageLabel2;
    //delete cursor;
    QDialog::done( 0 );
}
void mainWindow::clearSlot()
{
    if (!running){
	engine->clear();   //clears the influence of the next generation
	for (int y=0 ; y< 480 ; y++)
	{
	    for(int x=0 ; x<480 ; x++)
	    {
		engine->unpopulateCell(x/8 , y/8);
		emit eraseCell(x/8, y/8);
		this->paintMode = false;
	    }		
	 }
    ageLabel2->setNum(engine->getAge());
    repaintFrame();	
    }
}
void mainWindow::setMouseDown( int x, int y )
{
    int cellX = x / 8;
    int cellY = y / 8;
    
    if (x > 0 && x < 480 && y > 0 && y < 480) 
    {
        if (engine->getCell( cellX, cellY ) == -1 || 
            engine->getCell( cellX, cellY ) != colorGroupBox->selectedId() )
        {
            engine->populateCell( cellX, cellY, colorGroupBox->selectedId() );
            emit paintCell( cellX, cellY, selectedCritterType->getColor() );
            this->paintMode = true;
        } else {
            engine->unpopulateCell( cellX, cellY );
            emit eraseCell( cellX, cellY );
            this->paintMode = false;
        }
    }
    this->lastX = cellX;
    this->lastY = cellY;
}

void mainWindow::setMouseUp()
{
    // Reserved  
}

void mainWindow::setMouseXY( int x, int y )
{
    int cellX = x / 8;
    int cellY = y / 8;
    // Only perform update if mouse has moved to new playfield cell
    if ((this->lastX != cellX) || (this->lastY != cellY)) 
    {
        if (this->paintMode)
        {
            engine->populateCell( cellX, cellY, colorGroupBox->selectedId() );
            emit paintCell( cellX, cellY, selectedCritterType->getColor() );
        } else {
            engine->unpopulateCell( cellX, cellY );
            emit eraseCell( cellX, cellY );
        }
    }
    this->lastX = cellX;
    this->lastY = cellY;
}

void mainWindow::repaintFrame()
{
    int cellX, cellY;
    int width = engine->getWidth(), height = engine->getHeight();
    CritterType* targetCritter;
    
    framePaint->repaint();
    
    for (cellY=0;cellY<height;cellY++)
    {
        for (cellX=0;cellX<width;cellX++)
        {
            if (this->engine->getCell( cellX, cellY ) != -1) 
            {
                targetCritter = &this->engine->getCritterType( cellX, cellY );
                emit paintCell( cellX, cellY, targetCritter->getColor() );
            }
        }
    }
}

void mainWindow::colorGroupBox_clicked( int critter )
{
    // Skip slot execution if colorActive is clicked.
    if (critter>=0 && critter<=7)        
    {
        selectedCritterType = &this->engine->getCritterType(critter);
        this->updateTools();
        
        // Update tools to current selectedCritterType
        QString debugAppend;
        debugAppend.sprintf("SELECTED: critterType[%d]",critter);
        debugOutput->append( debugAppend );
    }
}

void mainWindow::colorActive_clicked() // Show Color Picker
{
    QColor newColor = QColorDialog::getColor(colorActive->paletteBackgroundColor());
    selectedCritterType->setColor( newColor );
    colorActive->setPaletteBackgroundColor( selectedCritterType->getColor() );
    colorGroupBox->selected()->setPaletteBackgroundColor( selectedCritterType->getColor() );
    repaintFrame();
    
    QString debugAppend;
    debugAppend.sprintf("CHANGED: color");
    debugOutput->append( debugAppend );
}

void mainWindow::observeCheckGroup_clicked( int buttonClicked )
{
    int offX, offY;
    QPushButton *targetButton = (QPushButton*) observeCheckGroup->find(buttonClicked);
    bool newValue = targetButton->isOn();
    
    offX = (buttonClicked % 7) - 3;
    offY = (buttonClicked / 7) - 3;
    selectedCritterType->setObserveCell(offX,offY,newValue);
    
    if (selectedCritterType->getObserveCell(offX,offY))
    {
        targetButton->setPaletteBackgroundColor(this->checkOn);
    }
    else
    {
        targetButton->setPaletteBackgroundColor(this->checkOff);
    }
    
    QString debugAppend;
    debugAppend.sprintf("SELECTED: observeCheckGroup[%d]",buttonClicked);
    debugOutput->append( debugAppend );
}

void mainWindow::spinMinCreate_valueChanged( int value )
{
    selectedCritterType->setMinCreate( value );
    if (selectedCritterType->getMaxCreate() < value)
    {
        spinMaxCreate->setValue( value );
    }
    
    QString debugAppend;
    debugAppend.sprintf("CHANGED: spinMinCreate(%d)",value);
    debugOutput->append( debugAppend );
}

void mainWindow::spinMaxCreate_valueChanged( int value )
{
    selectedCritterType->setMaxCreate( value );
    if (selectedCritterType->getMinCreate() < value)
    {
        spinMinCreate->setValue( value );
    }
    
    QString debugAppend;
    debugAppend.sprintf("CHANGED: spinMaxCreate(%d)",value);
    debugOutput->append( debugAppend );
}

void mainWindow::spinMinSurvive_valueChanged( int value )
{
    selectedCritterType->setMinSurvive( value );
    if (selectedCritterType->getMaxSurvive() < value)
    {
        spinMaxSurvive->setValue( value );
    }
    
    QString debugAppend;
    debugAppend.sprintf("CHANGED: spinMinSurvive(%d)",value);
    debugOutput->append( debugAppend );
}

void mainWindow::spinMaxSurvive_valueChanged( int value )
{
    selectedCritterType->setMaxSurvive( value );
    if (selectedCritterType->getMinSurvive() > value)
    {
        spinMinSurvive->setValue( value );
    }
    
    QString debugAppend;
    debugAppend.sprintf("CHANGED: spinMaxSurvive(%d)",value);
    debugOutput->append( debugAppend );
}

void mainWindow::checkAllowPushOut_toggled( bool value )
{
    selectedCritterType->setPushOut( value );
    
    QString debugAppend;
    debugAppend.sprintf("TOGGLED: checkAllowPushOut(%d)",value ? 1 : 0);
    debugOutput->append( debugAppend );
}

void mainWindow::checkObserveNonsimilar_toggled( bool value )
{
    selectedCritterType->setObserveOthers( value );
    
    QString debugAppend;
    debugAppend.sprintf("TOGGLED: checkObserveNonsimilar(%d)",value ? 1 : 0);
    debugOutput->append( debugAppend );
}


void mainWindow::updateTools()
{
    int i;
    QPushButton* targetButton;
    CritterType* targetType;
    for (i=0;i<8;i++)
    {
        targetButton = (QPushButton*) colorGroupBox->find(i);
        targetType = &this->engine->getCritterType(i);
        targetButton->setPaletteBackgroundColor( targetType->getColor() );
    }
    colorActive->setPaletteBackgroundColor( selectedCritterType->getColor() );
    for (i=0;i<49;i++)
    {
        targetButton = (QPushButton*) observeCheckGroup->find(i);
        if(selectedCritterType->getObserveCell( (i%7)-3, (i/7)-3 ))
        {
            targetButton->setOn(true);
            targetButton->setPaletteBackgroundColor( checkOn );
        } else {
            targetButton->setOn(false);
            targetButton->setPaletteBackgroundColor( checkOff );
        }
    }
    this->spinMinCreate->setValue(selectedCritterType->getMinCreate());
    this->spinMaxCreate->setValue(selectedCritterType->getMaxCreate());
    this->spinMinSurvive->setValue(selectedCritterType->getMinSurvive());
    this->spinMaxSurvive->setValue(selectedCritterType->getMaxSurvive());
    this->checkAllowPushOut->setChecked(selectedCritterType->getPushOut());
    this->checkObserveNonsimilar->setChecked(selectedCritterType->getObserveOthers());
}

void mainWindow::paintEvent( QPaintEvent *e )
{
    repaintFrame();
}

#endif


void mainWindow::startSlot()
{
    running = !running;
    timer->pause(!running);
    if (running){
	start_button->setText("Stop");
    }
    else{
	start_button->setText("Start");
    }
}

void mainWindow::buttonStep_clicked()
{
    //engine->nextGeneration();
    //repaintFrame();
    ageSlot();
}

void mainWindow::ageSlot()
{
    engine->setAge(engine->getAge() + 1);
    ageLabel2->setNum(engine->getAge());
    engine->nextGeneration();
    repaintFrame();
}



