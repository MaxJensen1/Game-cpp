#pragma once
#include <chrono>
#include <iostream>
#include <thread>
#include <iomanip> // For std::setw
#include <algorithm> // For std::max
#include "ColorsAndCursor.h"

class CountdownTimer: public ColorsAndCursor
{
public:
    CountdownTimer(int initialTimeInSeconds);
    void Start(); // Starts the timer
    void Stop(); // Stops the timer
    void UpdateTimer(int hiscore);
    int timeInSeconds;

private:
    bool running;
    std::chrono::high_resolution_clock::time_point start;
    std::thread TimerThread;

    void DrawTimer(int hiscore);
    void Run();
};
