/*
 * File: UniversalHealthCoverage.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the UniversalHealthCoverage problem
 * on Assignment #3.
 * [TODO: extend the documentation]
 */
#include <iostream>
#include <string>
#include "set.h"
#include "vector.h"
#include "console.h"
using namespace std;

bool canOfferUniversalCoverageRecursion(Set<string>& coveredCities,
    const Set<string>& cities,
    Vector<Set<string>>& locations,
    int numHospitals,
    int locIndex,
    Vector<Set<string>>& result){

    // If all cities were reached
    if (coveredCities == cities) return true;

    // If ran out of Hospitals or locations
    if (numHospitals <= 0 || locIndex >= locations.size()) return false;

    // 1. Add current hospital location's cities
    Set<string> updatedCoverage = coveredCities;
    for (string city : locations[locIndex]) {
        updatedCoverage.add(city);
    }

    // Save current location
    result.add(locations[locIndex]); 

    // Go to other locations from here
    if (canOfferUniversalCoverageRecursion(updatedCoverage, cities, locations, numHospitals - 1, locIndex + 1, result)) {
        return true;
    }

    // Backtrack
    result.remove(result.size() - 1);


    // 2. If previous didn't work, skip current location, try with other ones
    if (canOfferUniversalCoverageRecursion(coveredCities, cities, locations, numHospitals, locIndex + 1, result)) {
        return true;
    }

    // If none of them worked, return false
    return false;
}

/* Function: canOfferUniversalCoverage(Set<string>& cities,
 *                                     Vector< Set<string> >& locations,
 *                                     int numHospitals,
 *                                     Vector< Set<string> >& result);
 * Usage: if (canOfferUniversalCoverage(cities, locations, 4, result)
 * ==================================================================
 * Given a set of cities, a list of what cities various hospitals can
 * cover, and a number of hospitals, returns whether or not it's
 * possible to provide coverage to all cities with the given number of
 * hospitals.  If so, one specific way to do this is handed back in the
 * result parameter.
 */
bool canOfferUniversalCoverage(Set<string>& cities,
    Vector< Set<string> >& locations,
    int numHospitals,
    Vector< Set<string> >& result) {

    Set<string> coveredCities;

    int locIndex = 0;
    
    return canOfferUniversalCoverageRecursion(coveredCities, cities, locations, numHospitals, locIndex, result);
}


int main() {
    // Test case 1
    /*Set<string> cities;
    cities += "A", "B", "C", "D", "E", "F";

    Vector <Set<string>> locations;
    Vector <Set<string>> result;

    Set<string> loc1;
    loc1 += "A", "B", "C";

    Set<string> loc2;
    loc2 += "A", "C", "D";

    Set<string> loc3;
    loc3 += "B", "F";

    Set<string> loc4;
    loc4 += "C", "E", "F";

    locations += loc1, loc2, loc3, loc4;

    int numHospitals = 3;

    cout << (canOfferUniversalCoverage(cities, locations, numHospitals, result) ? "YES" : "NO") << endl;*/


    // Test case 2
    /*Set<string> cities;
    cities += "A", "B", "C", "D", "E", "F", "G";

    Vector<Set<string>> locations;
    Vector <Set<string>> result;

    Set<string> loc1;
    loc1 += "A", "B";

    Set<string> loc2;
    loc2 += "C", "D";

    Set<string> loc3;
    loc3 += "E", "F";

    Set<string> loc4;
    loc4 += "B", "C", "E";

    Set<string> loc5;
    loc5 += "D", "F", "G";

    Set<string> loc6;
    loc6 += "A", "G";

    locations += loc1, loc2, loc3, loc4, loc5, loc6;

    int numHospitals = 3;

    cout << (canOfferUniversalCoverage(cities, locations, numHospitals, result) ? "YES" : "NO") << endl;*/

    return 0;
}
