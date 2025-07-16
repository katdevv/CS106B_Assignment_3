/*
 * File: Subsequences.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Subsequences problem
 * on Assignment #3.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
using namespace std;

/* Given two strings, returns whether the second string is a
 * subsequence of the first string.
 */
bool isSubsequence(string text, string subsequence) {
    // If subsequence is an empty string, return true
    if (subsequence.size() == 0) return true;

    // If text is an empty string or is shorter than the subsequence, return false
    if (text.size() == 0 || subsequence.size() > text.size() ) return false;

    // If the first characters match, move to the next character in both strings
    if (text[0] == subsequence[0]) {
        return isSubsequence(text.substr(1), subsequence.substr(1));
    }
    
    // If the first characters don’t match, continue searching in text
    return isSubsequence(text.substr(1), subsequence);
    
};

int main() {
    cout << (isSubsequence("programming", "pin") ? "yes" : "no") << endl;

    return 0;
}
