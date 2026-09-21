#include <chrono>
class RateLimiter {
private:
    int tokens;
    int capacity;
    std::chrono::steady_clock::time_point lastRefill;

public:
    RateLimiter(int capacity);
    bool allowRequest();
};