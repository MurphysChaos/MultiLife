/**
  * lifefield.h
  * A custom widget that displays the field of critters.
  */

/**
  * Multilife
  * A Multi-species variant of Conway's Game of Life
  * 
  * Copyright (C) 2009 Joel Murphy, Ba Nguyen
  * All rights reserved
  * Licensed under the GNU Public License, v2. Full text of license can be found in gpl2.txt.
  */

#include <qwidget.h>

class LifeField : public QWidget
{
    Q_OBJECT
public:
    LifeField( QWidget *parent = 0, const char *name = 0 );;
    ~LifeField() {}
signals:
}
