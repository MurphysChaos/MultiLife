/**
  * critter_rule.cpp
  * Class to represent the behavior of a particular type of critter.
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

#include <critter_rule.h>

CritterRule::CritterRule()
{
    CritterRule( QColor(0,0,0) );
}

CritterRule::CritterRule( QColor newcolor );
{
    next = NULL;
    color = newcolor;
    observe = new char[7];
}

CritterRule::~CritterRule()
{
    if (next != NULL) {
        delete next;
        next = NULL;
    }
    
    delete color;
    delete observe;
}
