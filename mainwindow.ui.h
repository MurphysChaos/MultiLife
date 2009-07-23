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
    this->selectedCritterType = &this->engine->getCritterType(1);
    this->checkOn = green;
    this->checkOff = observeCheck1->paletteBackgroundColor();
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
    QDialog::done( 0 );
}

void mainWindow::setMouseDown( int x, int y )
{
    int cellX = x / 8;
    int cellY = y / 8;
    
    if (x > 0 && x < 480 && y > 0 && y < 480) 
    {
        if (engine->getCell( cellX, cellY ) == -1)
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
        if (engine->getCell( cellX, cellY ) == -1)
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

}

void mainWindow::colorGroupBox_clicked( int critter )
{
    // Skip slot execution if colorActive is clicked.
    if (critter>=0 && critter<=7)        
    {
        selectedCritterType = &this->engine->getCritterType(critter);
        colorActive->setPaletteBackgroundColor( selectedCritterType->getColor() );
    
        QString debugAppend;
        debugAppend.sprintf("SELECTED: critterType[%d]",critter);
        debugOutput->append( debugAppend );
    }
}

void mainWindow::showColorPicker()
{
    QColor newColor = QColorDialog::getColor();
    selectedCritterType->setColor( newColor );
    colorActive->setPaletteBackgroundColor( selectedCritterType->getColor() );
    colorGroupBox->selected()->setPaletteBackgroundColor( selectedCritterType->getColor() );
    
    QString debugAppend;
    debugAppend.sprintf("CHANGED: color");
    debugOutput->append( debugAppend );
}

void mainWindow::observeCheckGroup_clicked( int buttonClicked )
{
    int offX, offY;
    bool newValue;
        
    newValue = (this->observeCheckGroup.find( buttonClicked )).isOn();
    std::cerr << "observeCheckGroup["<<buttonClicked<<"] clicked\n";
    std::cerr << "    newValue = ";
    if (newValue)
        std::cerr << "true\n";
    else
        std::cerr << "false\n";
    
    offX = observeCheckGroup->selectedId() % 7;
    offY = observeCheckGroup->selectedId() / 7;
    selectedCritterType->setObserveCell( offX, offY, newValue );
    
    QString debugAppend;
    debugAppend.sprintf("SELECTED: observeCheckGroup[%d]",buttonClicked);
    debugOutput->append( debugAppend );
}

void mainWindow::spinMinCreate_valueChanged( int value )
{
    QString debugAppend;
    debugAppend.sprintf("CHANGED: spinMinCreate(%d)",value);
    debugOutput->append( debugAppend );
}

void mainWindow::spinMaxCreate_valueChanged( int value )
{
    QString debugAppend;
    debugAppend.sprintf("CHANGED: spinMaxCreate(%d)",value);
    debugOutput->append( debugAppend );
}

void mainWindow::spinMinSurvive_valueChanged( int value )
{
    QString debugAppend;
    debugAppend.sprintf("CHANGED: spinMinSurvive(%d)",value);
    debugOutput->append( debugAppend );
}

void mainWindow::spinMaxSurvive_valueChanged( int value )
{
    QString debugAppend;
    debugAppend.sprintf("CHANGED: spinMaxSurvive(%d)",value);
    debugOutput->append( debugAppend );
}

void mainWindow::checkAllowPushOut_toggled( bool value )
{
    QString debugAppend;
    debugAppend.sprintf("TOGGLED: checkAllowPushOut(%d)",value ? 1 : 0);
    debugOutput->append( debugAppend );
}

void mainWindow::checkObserveNonsimilar_toggled( bool value )
{
    QString debugAppend;
    debugAppend.sprintf("TOGGLED: checkObserveNonsimilar(%d)",value ? 1 : 0);
    debugOutput->append( debugAppend );
}

void mainWindow::buttonStep_clicked()
{

}

#endif
