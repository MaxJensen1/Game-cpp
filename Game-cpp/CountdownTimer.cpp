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

float CountdownTimer::UpdateTimer(uint16_t hiscore, float seconds, bool drawTimer)
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

void CountdownTimer::DrawTimer(uint16_t hiscore, float countdown, uint8_t secondsPerLevel)
{
    SetCursorPosition(0, 0);
    SetColor(AQUA);
    std::cout << "HI-Score: ";
    SetColor(BRIGHT_WHITE);
    std::cout << hiscore;

    SetCursorPosition(GetConsoleWidth() - 22, 0);
    int timerSeconds = std::abs(static_cast<int>(std::round(countdown) - secondsPerLevel));
    SetColor(AQUA);
    std::cout << "Time remaining: ";
    SetColor(BRIGHT_WHITE);
    if (timerSeconds < 10)
    {
        std::cout << "0" << timerSeconds << " s";
        return;
    }

    std::cout << timerSeconds << " s";
}