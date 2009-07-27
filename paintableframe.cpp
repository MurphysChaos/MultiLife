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
    painter = new QPainter(this);
}

PaintableFrame::~PaintableFrame()
{
    delete painter;
    painter = NULL;
}

void PaintableFrame::paint( int x, int y )
{
    QColor pen = QColor::QColor( Qt::black );
    painter->fillRect( x*8+1, y*8+1, 6, 6, pen );
}

void PaintableFrame::paint( int x, int y, QColor& color )
{
    QColor pen = QColor::QColor( color );
    painter->fillRect( x*8+1, y*8+1, 6, 6, pen );
}

void PaintableFrame::erase( int x, int y )
{
    QColor pen = QColor::QColor( colorGroup().midlight() );
    painter->fillRect( x*8+1, y*8+1, 6, 6, pen );
}

void PaintableFrame::paintEvent( QPaintEvent * e )
{
    QBrush brush( colorGroup().midlight() );
    for (int j=0;j<480;j+=8)
        for (int i=0;i<480;i+=8)
            qDrawShadePanel( painter, i, j, 8, 8, colorGroup(), true, 1, 0 );
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
