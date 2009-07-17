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
    QColor paintColor( colorActive->foregroundColor() );
    if (x > 0 && x < 480 && y > 0 && y < 480)
        emit paintCell( x / 8, y / 8, paintColor );
    mouseXValue->setText(QString("%1").arg(x));
    mouseYValue->setText(QString("%1").arg(y));
}

void mainWindow::colorWhite_clicked()
{
    QColor newcolor( white );
    colorActive->setPaletteForegroundColor( newcolor );
}


void mainWindow::colorRed_clicked()
{
    QColor newcolor( red );
    colorActive->setPaletteForegroundColor( newcolor );
}


void mainWindow::colorGreen_clicked()
{
    QColor newcolor( green );
    colorActive->setPaletteForegroundColor( newcolor );
}


void mainWindow::colorBlue_clicked()
{
    QColor newcolor( blue );
    colorActive->setPaletteForegroundColor( newcolor );
}


void mainWindow::colorBlack_clicked()
{
    QColor newcolor( black );
    colorActive->setPaletteForegroundColor( newcolor );
}


void mainWindow::colorCyan_clicked()
{
    QColor newcolor( cyan );
    colorActive->setPaletteForegroundColor( newcolor );
}


void mainWindow::colorMagenta_clicked()
{
    QColor newcolor( magenta );
    colorActive->setPaletteForegroundColor( newcolor );
}


void mainWindow::colorYellow_clicked()
{
    QColor newcolor( yellow );
    colorActive->setPaletteForegroundColor( newcolor );
}
