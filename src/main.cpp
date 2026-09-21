#include <iostream>
#include "rate_limiter.h"

using namespace std;

int main() {

    RateLimiter limiter(5);

    for (int i = 1; i <= 7; i++) {

        if (limiter.allowRequest()) {
            cout << "Request " << i << " Allowed\n";
        }
        else {
            cout << "Request " << i << " Blocked\n";
        }
    }

    return 0;
}