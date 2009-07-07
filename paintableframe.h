/**
  * paintableframe.h
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

#ifndef PAINTABLEFRAME_H
#define PAINTABLEFRAME_H

#include <qwidget.h>
#include <qevent.h>

class PaintableFrame : public QWidget
{
    Q_OBJECT
public:
    PaintableFrame( QWidget *parent = 0, const char *name = 0 );
    ~PaintableFrame() { }
    QPainter *painter;
protected:
    void paintEvent( QPaintEvent *e );
    void mousePressEvent( QMouseEvent *e );
    void mouseReleaseEvent( QMouseEvent *e );
    void mouseMoveEvent( QMouseEvent *e );
public slots:
    //void paint( int x, int y );    
signals:
    void pressed();
    void released();
    void mousemove( int x, int y );
};

#endif
