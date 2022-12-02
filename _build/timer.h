#pragma once
#include "raylib.h"



class Timer {
public:
    Timer(double startTime, double lifeTime);
    void startTimer(Timer* timer, double lifetime);
    bool timerDone(Timer timer);
    double getElapsed(Timer timer);
    double startTime;
    double lifeTime;
};

Timer::Timer(double startTime, double lifeTime) {
    this->startTime = startTime;
    this->lifeTime = lifeTime;
}

void Timer::startTimer(Timer* timer, double lifetime)
{
    timer->startTime = GetTime();
    timer->lifeTime = lifetime;
}

bool Timer::timerDone(Timer timer)
{
    return GetTime() - timer.startTime >= timer.lifeTime;
}

double Timer::getElapsed(Timer timer)
{
    return GetTime() - timer.startTime;
}