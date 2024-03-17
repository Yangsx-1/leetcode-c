// finished in 2024.3.11
#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;
class ZeroEvenOdd {
private:
    int n;
    mutex mu;
    condition_variable cv;
    int flag = 0;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; ++i) {
            unique_lock<mutex> lock(mu);
            cv.wait(lock, [&](){return flag == 0;});
            printNumber(0);
            if (i % 2 == 0) {
                flag = 2;
            } else {
                flag = 1;
            }
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i+=2) {
            unique_lock<mutex> lock(mu);
            cv.wait(lock, [&](){return flag == 2;});
            printNumber(i);
            flag = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i+=2) {
            unique_lock<mutex> lock(mu);
            cv.wait(lock, [&](){return flag == 1;});
            printNumber(i);
            flag = 0;
            cv.notify_all();
        }
    }
};