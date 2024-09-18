#include "CountdownTimer.h"
#include <iostream>
#include <iomanip> // For std::setw

CountdownTimer::CountdownTimer(int initialTimeInSeconds)
    : timeInSeconds(initialTimeInSeconds), running(false)
{
    // Initialize the stopwatch
    start = std::chrono::high_resolution_clock::now();
}

void CountdownTimer::Start() // Starts the timer
{
    running = true;
    start = std::chrono::high_resolution_clock::now(); // Restart stopwatch
    TimerThread = std::thread(&CountdownTimer::Run, this);
}

void CountdownTimer::Stop() // Stops the timer
{
    running = false;
    if (TimerThread.joinable())
    {
        TimerThread.join();
    }
}

void CountdownTimer::UpdateTimer(int hiscore)
{
    if (timeInSeconds <= 0)
    {
        timeInSeconds = 16; // Restart timer
    }

    auto now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = now - start;

    if (elapsed.count() >= 1.0) // 1 second passed
    {
        timeInSeconds--;
        start = std::chrono::high_resolution_clock::now(); // Restart stopwatch
    }

    DrawTimer(hiscore); // Draws the timer every time the time updates
}

void CountdownTimer::DrawTimer(int hiscore)
{
    // Clear the console line
    std::cout << "\r" << std::setw(20) << std::left << "HI-Score: " << hiscore << " \t\t\t\tTime remaining: " << std::max(0, timeInSeconds) << " s";
    std::cout.flush(); // Make sure the output is immediately visible
}

void CountdownTimer::Run()
{
    while (running)
    {
        UpdateTimer(0); // For demonstration, pass 0 as hi-score
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Update every 100 ms
    }
}
