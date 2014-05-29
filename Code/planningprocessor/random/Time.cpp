#include <random/Time.h>

Time::Time(){}

void Time::waitTime(float time)
{
    int sec = time;
    float dec = time - sec;

    struct timespec timeSec, tiempoNSec;
    tiempoSec.tv_sec = sec;
    tiempoNSec.tv_nsec = dec * 1000 * 1000 * 1000;

    while (true)
    {
        if ( nanosleep(&tiempoSec, &tiempoNSec) >= 0 )
            break;
    }
}

float Time::getTime()
{
    clock_t tclock = clock();
    float time = tclock / (float)CLOCKS_PER_SEC;
    return time;
}
