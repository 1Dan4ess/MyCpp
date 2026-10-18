#pragma once
#include "People.h"
#include "Queue.h"
using namespace std;
#include<iostream>

class Stop
{
    Queue<People> people;

    int maxPeople;
    double allTime;
    int leftPeople;
    static void addMinute(People& p);

public:
    Stop();

    void start();
    void addPeople();
    void Bus();
    int findInterval(int totalTime, int nextPeople, int N);
};

void Stop::addMinute(People& p)
{
    p.addWaitTime();
}

Stop::Stop()
{
    allTime = 0;
    leftPeople = 0;
    maxPeople = 0;
}

void Stop::start()
{
    int nextPeople, nextBus, totalTime, N;
    cout << "Next human in: ";
    cin >> nextPeople;
    cout << "Next bus in: ";
    cin >> nextBus;
    cout << "Total time: ";
    cin >> totalTime;
    cout << "Max people on stop: ";
    cin >> N;
    for (size_t i = 1; i <= totalTime; i++)
    {
        people.for_each(addMinute);
        if (i % nextPeople == 0)
        {
            addPeople();
            cout << "+1" << endl;
        }
        if (i % nextBus == 0)
        {
            int before = leftPeople;
            Bus();
            cout << "-" << leftPeople - before << endl;
        }
    }
    cout << "Average waitTime: " << allTime / leftPeople << endl;
    cout << "Correct bus interval before N people on stop: " << findInterval(totalTime, nextPeople, N) << endl;
}

void Stop::addPeople()
{
    People p;
    people.enqueue(p);
    if (people.getSize() > maxPeople)
    {
        maxPeople = people.getSize();
    }
}

void Stop::Bus()
{
    int seats = rand() % 6;
    while (seats > 0 and people.getSize() > 0)
    {
        allTime += people.peek().getWaitTime();
        people.dequeue();
        leftPeople++;
        seats--;
    }
}

int Stop::findInterval(int totalTime, int nextPeople, int N)
{
    int result = 0;
    for (size_t i = 1; i <= totalTime; i++)
    {
        Stop temp;
        for (size_t j = 1; j <= totalTime; j++)
        {
            if (j % nextPeople == 0)
            {
                temp.addPeople();
            }
            if (j % i == 0)
            {
                temp.Bus();
            }
            temp.people.for_each(addMinute);
        }
        if (temp.maxPeople <= N)
        {
            result = i;
        }
    }
    return result;
}
