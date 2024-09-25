#include "CountdownTimer.h"

void CountdownTimer::StartAndRestart() // Starts the timer
{
    running = true;
    start = std::chrono::high_resolution_clock::now(); // Restart stopwatch
}

void CountdownTimer::Stop() // Stops the timer
{
    running = false;
}

double CountdownTimer::UpdateTimer(int hiscore, int secondsPerLevel)
{
    auto now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = now - start;
    DrawTimer(hiscore, elapsed.count(), secondsPerLevel); // Draw the timer after updating

    return elapsed.count();
}

void CountdownTimer::DrawTimer(int hiscore, double countdown, int secondsPerLevel)
{
    SetCursorPosition(0, 0);
    std::cout << "HI-Score: " << hiscore;

    SetCursorPosition(ScreenWidth() - 22, 0);
    int timerSeconds = std::abs(static_cast<int>(std::round(countdown) - secondsPerLevel));
    std::cout << "Time remaining: " << timerSeconds << " s";

}