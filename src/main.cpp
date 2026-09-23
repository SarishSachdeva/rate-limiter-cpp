#include <iostream>
#include "rate_limiter.h"
#include <windows.h>

int main() {

    RateLimiter limiter(5,2);

    for (int i = 1; i <= 7; i++) {

        if (limiter.allowRequest()) {
            std::cout << "Request " << i << " Allowed\n";
        }
        else {
            std::cout << "Request " << i << " Blocked\n";
        }
        
    }
Sleep(5000);

    for (int i = 8; i <= 12; i++) {

    if (limiter.allowRequest()) {
        std::cout << "Request " << i << " Allowed\n";
    }
    else {
        std::cout << "Request " << i << " Blocked\n";
    }
}

    return 0;
}