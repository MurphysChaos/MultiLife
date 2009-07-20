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
    this->engine = new Life(80, 80);
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
    delete framePaint;
    framePaint = NULL;
    QDialog::done( 0 );
}

void mainWindow::setMouseDown( int x, int y )
{
    QColor paintColor( colorActive->paletteBackgroundColor() );
    if (x > 0 && x < 480 && y > 0 && y < 480)
	emit paintCell( x / 8, y / 8, paintColor );
}

void mainWindow::setMouseUp()
{
    
}

void mainWindow::setMouseXY( int x, int y )
{	
    QColor paintColor( colorActive->paletteBackgroundColor() );
    if (x > 0 && x < 480 && y > 0 && y < 480)
	emit paintCell( x / 8, y / 8, paintColor );
}

void mainWindow::observeCheckGroup_clicked( int buttonClicked )
{
    QCheckBox *targetButton = (QCheckBox*) observeCheckGroup->find( buttonClicked );
    if ( targetButton->isChecked() ) {
	targetButton->setPaletteBackgroundColor( checkOn );
    } else {
	targetButton->setPaletteBackgroundColor( checkOff );
    }
    debugOutput->setText( QString::number( buttonClicked ) );
}

void mainWindow::showColorPicker()
{
    QColor newColor = QColorDialog::getColor();
    colorActive->setPaletteBackgroundColor( newColor );
    colorGroupBox->selected()->setPaletteBackgroundColor( newColor );
}

#endif
