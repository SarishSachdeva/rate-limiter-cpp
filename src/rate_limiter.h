#include <chrono>
class RateLimiter {
private:
    int tokens;
    int capacity;
    int refillRate;
    std::chrono::steady_clock::time_point lastRefill;

public:
    RateLimiter(int capacity, int refillRate);
    bool allowRequest();
    int getTokens();
};