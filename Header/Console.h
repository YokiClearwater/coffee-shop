// header for console operation
#include <cstdlib>
#include <chrono>
#include <thread>
using namespace std;

void clearScreen()
{
    #ifdef WINDOWS
        std::system("cls");
    #else
        std::system ("clear");
    #endif
}

void sleepTime(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
