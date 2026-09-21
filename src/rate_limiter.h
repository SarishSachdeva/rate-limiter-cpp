class RateLimiter {
private:
    int tokens;
    int capacity;

public:
    RateLimiter(int capacity);
    bool allowRequest();
};