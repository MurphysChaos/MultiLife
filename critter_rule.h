/**
  * critter_rule.h
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

#ifndef CRITTER_RULE_H
#define CRITTER_RULE_H

#include <qcolor.h>

class CritterRule
{
public:
    CritterRule();
    CritterRule( QColor color );
    ~CritterRule();
private:
    CritterRule *next;	// For linked list of CritterRules.
    QColor& color;	// Color to paint on paintableframe.
    char observe[];	// 7x7 bit array of whether or not a nearby cell
                        // is examined for creation / destruction test
};

#endif
