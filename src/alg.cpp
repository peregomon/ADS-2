// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0)
        return 1;
    double valueSave = value;
    for (int i = 1; i < n; i++) {
        value *= valueSave;
    }
    return value;

}

uint64_t fact(uint16_t n) {
    if (n <= 1) {
        return 1;
    }
    else {
        return n * fact(n - 1);
    }

}

double calcItem(double x, uint16_t n) {
    return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
    double e = 1;
    for (int i = 1; i <= count; i++) {
        e += calcItem(x, i);
    }
    return e;
}

double sinn(double x, uint16_t count) {
    double new_x = x;
    for (int i = 2; i < count; i++) {
        new_x += pown(-1, i - 1) * calcItem(x, (2 * i) - 1);
    }
    return new_x;
}

double cosn(double x, uint16_t count) {
    double new_x = 1;
    for (int i = 2; i < count; i++) {
        new_x += pown(-1, i - 1) * calcItem(x, (2 * i) - 2);
    }
    return new_x;

}
