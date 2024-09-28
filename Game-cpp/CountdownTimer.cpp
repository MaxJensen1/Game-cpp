#include "CountdownTimer.h"

void CountdownTimer::Start() // Starts the timer
{
    if (!running)
    {
        running = true;
        start = std::chrono::high_resolution_clock::now(); // Start stopwatch
    }
}

void CountdownTimer::Restart()
{
    running = true;
    start = std::chrono::high_resolution_clock::now(); // Restart stopwatch
}

void CountdownTimer::Stop() // Stops the timer
{
    running = false;
}

float CountdownTimer::UpdateTimer(int hiscore, float seconds, bool drawTimer)
{
    if (drawTimer)
    {
        DrawTimer(hiscore, UpdateTimer(seconds), seconds); // Draw the timer after updating
    }

    return UpdateTimer(seconds);
}

float CountdownTimer::UpdateTimer(float seconds)
{
    auto now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = now - start;
    return elapsed.count();
}

void CountdownTimer::DrawTimer(int hiscore, double countdown, int secondsPerLevel)
{
    SetCursorPosition(0, 0);
    SetColor(3);
    std::cout << "HI-Score: ";
    SetColor(7);
    std::cout << hiscore;

    SetCursorPosition(ScreenWidth() - 22, 0);
    int timerSeconds = std::abs(static_cast<int>(std::round(countdown) - secondsPerLevel));
    SetColor(3);
    std::cout << "Time remaining: ";
    SetColor(7);
    std::cout << timerSeconds << " s";
}