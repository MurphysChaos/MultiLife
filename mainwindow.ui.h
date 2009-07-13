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

void mainWindow::closeEvent( QCloseEvent * )
{
    fileExit();
}

void mainWindow::fileExit()
{
    delete framePaint;
    framePaint = NULL;
    QDialog::done( 0 );
}

void mainWindow::setMouseDown()
{
    
}

void mainWindow::setMouseUp()
{
    mouseXValue->setText(QString(""));
    mouseYValue->setText(QString(""));
}

void mainWindow::setMouseXY( int x, int y )
{
    mouseXValue->setText(QString("%1").arg(x));
    mouseYValue->setText(QString("%1").arg(y));
}
