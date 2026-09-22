#include "rate_limiter.h"

RateLimiter::RateLimiter(int capacity) {
    this->capacity = capacity;
    this->tokens = capacity;
    this->lastRefill = std::chrono::steady_clock::now();
}

bool RateLimiter::allowRequest() {
    auto currentTime = std::chrono::steady_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(
        currentTime - lastRefill
    ).count();

    if (elapsed >= 1 && tokens < capacity) {
        tokens += static_cast<int>(elapsed);

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