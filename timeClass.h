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
#include <qtimer.h>
#include <qwidget.h>
const int MAXSPEED = 400;

class LifeTimer : public QTimer
{
    Q_OBJECT
public:
    LifeTimer( QWidget * parent );
    void	pause( bool );

public slots:
    void	setSpeed( int speed );
    
private:
    int		interval;
};
