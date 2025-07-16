/*
 * File: KarelGoesHome.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Karel Goes Home
 * warmup problem for Assignment #3.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "console.h"
#include "set.h"
using namespace std;

/* Given a street number and avenue number, which are 1-indexed,
 * returns the number of paths Karel can take back home that only
 * moves left or down.
 */
void numPathsHomeRecursion(int street, int avenue, int& path_num) {
    if (street < 1 || avenue < 1) return;

    else if (street == 1 && avenue == 1) {
        path_num++;
        return;
    }

    cout << street << avenue << endl;

    //pair<int, int> neighbour1 = make_pair(street - 1, avenue); // left
    //pair<int, int> neighbour2 = make_pair(street, avenue - 1); // down

    //Vector<pair<int, int>> neighbours;
    //neighbours.add(neighbour1);
    //neighbours.add(neighbour2);

    //for (pair<int, int> neighbour : neighbours) {
    //    if (neighbour.first > 0 && neighbour.second > 0 ) {
    //        numPathsHomeRecursion(neighbour.first, neighbour.second, path_num);
    //    }
    //}

    numPathsHomeRecursion(street - 1, avenue, path_num); // left

    numPathsHomeRecursion(street, avenue - 1, path_num); // down
}

int numPathsHome(int street, int avenue) {
    // street-- => left
    // avenue-- => bottom
    // goal street = 1, avenue = 1;
    // use DFS!

    int path_num = 0;

    numPathsHomeRecursion(street, avenue, path_num);

    return path_num;
}

int numPathsHome2(int street, int avenue) {
    /* Base case 1: If we're not on the map, there's no way back. */
    if (street < 1 || avenue < 1) {
        return 0;
    }
    /* Base case 2: If we're home, there's exactly one path back. */
    else if (street == 1 && avenue == 1) {
        return 1;
    }
    /* Recursive step: Take a step in each direction and sum up the
     * number of paths.
     */
    else {
        return numPathsHome(street - 1, avenue) + numPathsHome(street, avenue - 1);
    }
}

int main() {
    cout << numPathsHome(3, 2) << endl;

    return 0;
}
