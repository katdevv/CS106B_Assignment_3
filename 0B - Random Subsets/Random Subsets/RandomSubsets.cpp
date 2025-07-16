/*
 * File: RandomSubsets.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Random Subsets problem
 * on Assignment #3.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "set.h"
#include "random.h"
#include "console.h"
using namespace std;

/* Given a set of integers, returns a uniformly-random subset of that
 * set.
 */

Set<int> randomSubsetOf(Set<int>& s) {
    if (s.isEmpty()) return s;

    int x = s.first();
    
    s -= x;

    Set<int> result = randomSubsetOf(s);

    s += x;

    return randomChance(0.5) ? result : result + x;
}

int main() {
    Set<int> testSet;
    testSet += 1, 2, 3, 4, 5, 6, 7, 8, 9, 10;
    cout << randomSubsetOf(testSet) << endl;

    return 0;
}
