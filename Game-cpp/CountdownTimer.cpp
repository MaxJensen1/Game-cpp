#include "CountdownTimer.h"

CountdownTimer::CountdownTimer(int initialTimeInSeconds)
    : timeInSeconds(initialTimeInSeconds), running(false)
{
    // Initialize the stopwatch
    start = std::chrono::high_resolution_clock::now();
}

void CountdownTimer::Start() // Starts the timer
{
    if (running) { return; } // Prevent starting a new thread if it's already running

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
    // Clear the console line
    std::cout << "HI-Score: " << hiscore << " \t\t\t\tTime remaining: " << timeInSeconds << " s";
    SetCursorPosition(0, 1); // So it doesn't cover up the text
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