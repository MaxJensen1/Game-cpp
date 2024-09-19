#pragma once
#include <chrono>
#include <iostream>
#include <iomanip> // For std::setw
#include <algorithm> // For std::max
#include "ColorsAndCursor.h"

class CountdownTimer: public ColorsAndCursor
{
public:
    CountdownTimer(int initialTimeInSeconds): timeInSeconds(initialTimeInSeconds), running(false) 
    {
        // Initialize the stopwatch
        start = std::chrono::high_resolution_clock::now();
    }

    void Start(); // Starts the timer
    void Stop(); // Stops the timer
    void UpdateTimer(int hiscore);
    int timeInSeconds;

private:
    bool running;
    std::chrono::high_resolution_clock::time_point start;

    void DrawTimer(int hiscore);
};
