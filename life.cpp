/**
  * life.cpp
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

#include <life.h>

Life::Life(int x, int y)
{
    int i, j;
    width = x;
    height = y;
    field = new CritterRule *[width*height];
    
    for (j=0;j<height;j++)
        for (i=0;i<width;i++)
            field[ j*width + i ] = NULL;
}


