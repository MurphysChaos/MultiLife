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
#include <qpainter.h>

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

void PaintableFrame::paint( int x, int y, QColor& color )
{
    QPen gridpen(color, 1);
    
    painter->setPen(gridpen);
    painter->drawRect( x*5+1, y*5+1, 4, 4 );
}

void PaintableFrame::paintEvent( QPaintEvent * e )
{
    QPen gridpen(qRgb(85, 85, 85), 1);
    
    painter->setPen(gridpen);
    for (int i=0;i<501;i+=5)
    {
	painter->drawLine(i,0,i,501);
	painter->drawLine(0,i,501,i);
    }
}

void PaintableFrame::mousePressEvent( QMouseEvent * e )
{
    if ( e->button() == QMouseEvent::LeftButton )
	emit pressed();
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
