#pragma once


class People
{
    int waitTime;


public:
    People();
    int getWaitTime();
    void addWaitTime();

};

People::People()
{
    waitTime = 0;
}

int People::getWaitTime()
{
    return waitTime;
}

void People::addWaitTime()
{
    waitTime++;
}