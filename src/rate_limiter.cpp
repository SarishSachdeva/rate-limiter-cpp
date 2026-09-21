#include "rate_limiter.h"

RateLimiter::RateLimiter(int capacity) {
    this->capacity = capacity;
    this->tokens = capacity;
}

bool RateLimiter::allowRequest() {
    if (tokens > 0) {
        tokens--;
        return true;
    }

    return false;
}