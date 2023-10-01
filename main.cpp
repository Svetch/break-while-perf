#include <iostream>
#include <chrono>

const int END = 1000000;
const int F = 1000;

void test_while() {
    bool t = true;
    int i = 0;
    while (t) {
        i++;
        if (i >= END) {
            t = false;
        }
    }
}

void test_do_while() {
    bool t = true;
    int i = 0;
    do {
        if (i >= END) {
            t = false;
        }
        i++;
    } while (t);
}

void test_break() {
    int i = 0;
    while (true) {
        i++;
        if (i >= END) {
            break;
        }
    }
}

int main() {
    auto break_start = std::chrono::high_resolution_clock::now();
    for (int x = 0; x < F; x++) {
        test_break();
    }
    auto break_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> break_duration = break_end - break_start;
    std::cout << "break: " << break_duration.count() << " seconds" << std::endl;

    auto while_start = std::chrono::high_resolution_clock::now();
    for (int x = 0; x < F; x++) {
        test_while();
    }
    auto while_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> while_duration = while_end - while_start;
    std::cout << "while: " << while_duration.count() << " seconds" << std::endl;

    auto do_while_start = std::chrono::high_resolution_clock::now();
    for (int x = 0; x < F; x++) {
        test_do_while();
    }
    auto do_while_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> do_while_duration = do_while_end - do_while_start;
    std::cout << "dowhile : " << do_while_duration.count() << " seconds" << std::endl;

    return 0;
}