/**
  * critter_type.cpp
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

#include <critter_type.h>

CritterType::CritterType()
{
    observe = new char[7];
}

CritterType::~CritterType()
{
    delete [] observe;
}
