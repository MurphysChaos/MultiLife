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

#include <critter_rule.h>

class Life
{
    Life();
    Life(int x, int y);
    Life(Life& oldLife);	// Semi-deep copy of rules. New field is empty.
    ~Life();
    void advance();					  // Advances to next generation by peforming testCell(
                                                          // on all cells in array.
    void testCell( int x, int y );			  // Examines a given cell. If populated, tests for 
    							  // destruction. If unpopulated, tests for creation.
    void populateCell( int x, int y, CritterRule& type );
    void unpopulateCell( int x, int y );
private:
    CritterRule *field[][];	// Array of critters. Each critter is specified by a CritterRule.
    CritterRule *first;		// List of rule sets
    Life *nextGeneration;	// Used by advancement methods to write into a "clean slate." Semi-deep constructor
                                // should be used to create next generation.
    int width;			// Width of array
    int height;			// Height of array
}

#endif
