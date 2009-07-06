/**
  * formMain.ui.h
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

void formMain::fileNew()
{

}

void formMain::fileOpen()
{

}

void formMain::fileSave()
{

}

void formMain::fileSaveAs()
{

}

void formMain::filePrint()
{

}

void formMain::closeEvent( QCloseEvent * )
{
    fileExit();
}

void formMain::fileExit()
{
    QApplication::exit( 0 );
}

void formMain::helpIndex()
{

}

void formMain::helpContents()
{

}

void formMain::helpAbout()
{

}

void formMain::setMouseXY( int x, int y )
{
    mouseXValue->setCaption(QString("%d").arg(x));
    mouseYValue->setCaption(QString("%d").arg(y));
}
