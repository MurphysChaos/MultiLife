/**
  * life.h
  * Object to handle the MultiLife logic.
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

#ifndef LIFE_H
#define LIFE_H

#include <critter.h>

class Life
{
    Life();
    Life(int x, int y);
    ~Life();
    void advance();
    void populateCell( int x, int y, Critter& type );
private:
    Critter* field[][];	// Array of critters, dimensions defined by constructor.
    int width;
    int height;
}

#endif
