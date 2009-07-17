/**
  * critter_rule.h
  * Class to handle the behavior of a particular type of critter.
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

#ifndef CRITTER_H
#define CRITTER_H

#include <qcolor.h>

class CritterRule
{
    CritterRule();
    CritterRule( QColor& color );
    ~CritterRule();
private:
    CritterRule *next;	// Maintains linked list of CritterRules.
    QColor& color;	// 
    char *observe;	// 7x7 bit array of whether or not a nearby cell
                        // is examined for creation / destruction test
}

#endif
