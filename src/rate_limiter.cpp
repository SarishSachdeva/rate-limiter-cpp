#include "rate_limiter.h"
#include <stdexcept>

RateLimiter::RateLimiter(int capacity, int refillRate) {
    if(capacity <= 0 || refillRate <= 0) {
        throw std::invalid_argument("Capacity and refill rate must be positive integers.");
    }
    this->capacity = capacity;
    this->tokens = capacity;
    this->refillRate = refillRate;
    this->lastRefill = std::chrono::steady_clock::now();
    
}

bool RateLimiter::allowRequest() {
    auto currentTime = std::chrono::steady_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(
        currentTime - lastRefill
    ).count();

    if (elapsed >= 1 && tokens < capacity) {
        tokens += static_cast<int>(elapsed) * refillRate;

        if (tokens > capacity) {
            tokens = capacity;
        }
        lastRefill = currentTime;
    }

    if (tokens > 0) {
        tokens--;
        return true;
    }

    return false;
}
int RateLimiter::getTokens() {
    return tokens;
}
int RateLimiter::getCapacity() {
    return capacity;
}