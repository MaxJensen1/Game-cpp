#include "CountdownTimer.h"

void CountdownTimer::Start() // Starts the timer
{
    if (running) { return; } // Prevent starting a new thread if it's already running

    running = true;
    start = std::chrono::high_resolution_clock::now(); // Restart stopwatch
}

void CountdownTimer::Stop() // Stops the timer
{
    running = false;
}

void CountdownTimer::UpdateTimer(int hiscore)
{
    auto now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = now - start;

    if (elapsed.count() >= 1.0) // 1 second has passed
    {
        timeInSeconds--;
        start = std::chrono::high_resolution_clock::now(); // Restart stopwatch
        DrawTimer(hiscore); // Draw the timer after updating
    }
}

void CountdownTimer::DrawTimer(int hiscore)
{
    SetCursorPosition(0, 0);
    std::cout << "HI-Score: " << hiscore;

    SetCursorPosition(ScreenWidth() - 22, 0);
    std::cout << "Time remaining: " << timeInSeconds << " s";

    std::cout.flush(); // Make sure the output is immediately visible
}