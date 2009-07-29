#include "timeClass.h"

LifeTimer::LifeTimer( QWidget * parent ) : QTimer( parent ), interval( 100 )
{

}


void LifeTimer::pause( bool stopIt )
{
    if ( stopIt ) //if arg is true stop
	stop();
    else	   //if arg is false then don't need to pause, actually start
	start( interval );     //go at interval speed
}

void LifeTimer::setSpeed( int speed )
{
    interval = (speed < 380) ? MAXSPEED - speed : 20; 
    if ( isActive() )
	changeInterval( interval );
}
