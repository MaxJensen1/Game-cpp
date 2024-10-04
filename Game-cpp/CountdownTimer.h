#pragma once
#include <chrono>
#include <iostream>
#include <iomanip> // For std::setw
#include <algorithm> // For std::max
#include "ConsoleGraphics.h"

class CountdownTimer: public ConsoleGraphics
{
public:
    CountdownTimer(int seconds): timeInSeconds(seconds), running(false) 
    {
        // Initialize the stopwatch
        start = std::chrono::high_resolution_clock::now();
    }

    void Start(); // Starts the timer
    void Restart();
    void Stop(); // Stops the timer
    float UpdateTimer(uint16_t hiscore, float secondsPerLevel, bool drawTimer);
    float UpdateTimer(float secondsPerLevel);
    int timeInSeconds;

private:
    bool running;
    std::chrono::high_resolution_clock::time_point start;

    void DrawTimer(uint16_t hiscore, float countdown, uint8_t secondsPerLevel);
};