#pragma once

#include <chrono>
#include <thread>

class CountdownTimer
{
public:
    CountdownTimer(int initialTimeInSeconds);
    void Start(); // Starts the timer
    void Stop(); // Stops the timer
    void UpdateTimer(int hiscore);

private:
    int timeInSeconds;
    bool running;
    std::chrono::high_resolution_clock::time_point start;
    std::thread TimerThread;

    void DrawTimer(int hiscore);
    void Run();
};
