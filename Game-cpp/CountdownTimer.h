#pragma once
#include <chrono>
#include <iostream>
#include <iomanip> // For std::setw
#include <algorithm> // For std::max
#include "ColorsAndCursor.h"

class CountdownTimer: public ColorsAndCursor
{
public:
    CountdownTimer(int secondsPerLevel): timeInSeconds(secondsPerLevel), running(false) 
    {
        // Initialize the stopwatch
        start = std::chrono::high_resolution_clock::now();
    }

    void StartAndRestart(); // Starts the timer
    void Stop(); // Stops the timer
    double UpdateTimer(int hiscore, int secondsPerLevel);
    int timeInSeconds;

private:
    bool running;
    std::chrono::high_resolution_clock::time_point start;

    void DrawTimer(int hiscore, double countdown, int secondsPerLevel);
};
