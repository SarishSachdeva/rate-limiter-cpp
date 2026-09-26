#include <iostream>
#include "rate_limiter.h"
#include <windows.h>
#include <stdexcept>
int main() {

    try {
        RateLimiter limiter(5, 1);

        for (int i = 1; i <= 7; i++) {

        if (limiter.allowRequest()) {
            std::cout << "Request " << i << " Allowed\n";
        }
        else {
            std::cout << "Request " << i << " Blocked\n";
        }
        
    }
    std::cout << "Capacity: " << limiter.getCapacity() << "\n";
    std::cout << "Remaining tokens: " << limiter.getTokens() << "\n";
    Sleep(5000);
    
    for (int i = 8; i <= 12; i++) {
        
        if (limiter.allowRequest()) {
            
            std::cout << "Request " << i << " Allowed\n";
        }
        else {
            std::cout << "Request " << i << " Blocked\n";
        }
    }
    std::cout << "Remaining tokens: " << limiter.getTokens() << "\n";

    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    

    return 0;
}