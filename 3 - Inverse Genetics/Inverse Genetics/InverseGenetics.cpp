/*
 * File: InverseGenetics.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Inverse Genetics problem
 * on Assignment #3.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include <string>
#include <fstream>
#include "set.h"
#include "map.h"
#include "console.h"
#include "simpio.h"
#include "queue.h"
using namespace std;

void listAllRNAStrandsForRecursive(Vector<string>& curr_rna, string protein, Map<char, Set<string> >& codons) {
    // If the last acid of protein is reached, print the result
    if (protein.size() == 0) {
        for (string s : curr_rna) cout << s;
        cout << endl;
    }

    // Get first acid of protein
    char acid = protein[0];

    // Get codons of that acid
    Set<string> cods = codons[acid];

    for (string c : cods) {
        // Add codon to the current DNA
        curr_rna.push_back(c);

        // Add next codons
        listAllRNAStrandsForRecursive(curr_rna, protein.substr(1), codons);

        // Remove last codon from the current DNA
        curr_rna.remove(curr_rna.size() - 1);
    }

    return;
};

/* Function: listAllRNAStrandsFor(string protein,
 *                                Map<char, Set<string> >& codons);
 * Usage: listAllRNAStrandsFor("PARTY", codons);
 * ==================================================================
 * Given a protein and a map from amino acid codes to the codons for
 * that code, lists all possible RNA strands that could generate
 * that protein
 */
void listAllRNAStrandsFor(string protein, Map<char, Set<string> >& codons) {
    // Current DNA
    Vector<string> curr_rna;

    listAllRNAStrandsForRecursive(curr_rna, protein, codons);
};

/* Function: loadCodonMap();
 * Usage: Map<char, Lexicon> codonMap = loadCodonMap();
 * ==================================================================
 * Loads the codon mapping table from a file.
 */
Map<char, Set<string> > loadCodonMap();

int main() {
    /* Load the codon map. */
    Map<char, Set<string> > codons = loadCodonMap();

    string protein = getLine("enter protein: ");

    listAllRNAStrandsFor(protein, codons);

    /* [TODO: Implement this!] */
    return 0;
}

/* You do not need to change this function. */
Map<char, Set<string> > loadCodonMap() {
    ifstream input("codons.txt");
    Map<char, Set<string> > result;

    /* The current codon / protein combination. */
    string codon;
    char protein;

    /* Continuously pull data from the file until all data has been
     * read.
     */
    while (input >> codon >> protein) {
        result[protein] += codon;
    }

    return result;
}
