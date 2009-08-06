/**
  * paintableframe.cpp
  * A simple widget that receives mouse input, sends it to a handler, and
  * allows that handler to send paint instructions to the frame. This class
  * should not be confused with QFrame as it inherits directly from QWidget.
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

#include "paintableframe.h"

PaintableFrame::PaintableFrame( QWidget *parent, const char *name )
    : QWidget(parent, name)
{
    int i,j;
    
    buffer = QPixmap::QPixmap( IMAGE_WIDTH, IMAGE_HEIGHT );
    buffer.fill( colorGroup().midlight() );
    QPainter bufferPainter(&buffer);
    
    QBrush brush( colorGroup().midlight() );
    for (j=0;j<480;j+=8)
        for (i=0;i<480;i+=8)
            qDrawShadePanel( &bufferPainter, i, j, 8, 8, colorGroup(), true, 1, 0 );
}

PaintableFrame::~PaintableFrame()
{
    /*
    delete framePainter;
    delete bufferPainter;
    delete buffer;
    bufferPainter = NULL;
    */
}

void PaintableFrame::paint( int x, int y )
{
    QPainter bufferPainter(&buffer);
    QPainter framePainter(this);
    QColor pen = QColor::QColor( Qt::black );
    bufferPainter.fillRect( x*8+1, y*8+1, 6, 6, pen );
    framePainter.fillRect( x*8+1, y*8+1, 6, 6, pen );
}

void PaintableFrame::paint( int x, int y, QColor& color )
{
    QPainter bufferPainter(&buffer);
    QPainter framePainter(this);
    QColor pen = QColor::QColor( color );
    bufferPainter.fillRect( x*8+1, y*8+1, 6, 6, pen );
    framePainter.fillRect( x*8+1, y*8+1, 6, 6, pen );
}

void PaintableFrame::erase( int x, int y )
{
    QPainter bufferPainter(&buffer);
    QPainter framePainter(this);
    QColor pen = QColor::QColor( colorGroup().midlight() );
    bufferPainter.fillRect( x*8+1, y*8+1, 6, 6, pen );
    framePainter.fillRect( x*8+1, y*8+1, 6, 6, pen );
}

void PaintableFrame::paintEvent( QPaintEvent * e )
{
    QPainter framePainter(this);
    framePainter.drawPixmap(0, 0, buffer);
}

void PaintableFrame::mousePressEvent( QMouseEvent * e )
{
    if ( e->button() == QMouseEvent::LeftButton )
	emit pressed( e->x(), e->y() );
}

void PaintableFrame::mouseReleaseEvent( QMouseEvent * e )
{
    if ( e->button() == QMouseEvent::LeftButton )
	emit released();
}

void PaintableFrame::mouseMoveEvent( QMouseEvent * e )
{
    emit mousemove( e->x(), e->y() );
}
