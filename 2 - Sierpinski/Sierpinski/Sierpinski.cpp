/*
 * File: Sierpinski.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Sierpinski problem
 * on Assignment #3.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "gwindow.h"
#include "simpio.h"
using namespace std;

// PROBLEM: slight cdomilebebi

void drawOneTriangle(GWindow& gw, GPoint start, int length) {
    // (x,y) are coords of the left bottom corner
    GPoint p1 = gw.drawPolarLine(start, length, 0);
    GPoint p2 = gw.drawPolarLine(p1, length, 120);
    GPoint p3 = gw.drawPolarLine(p2, length, -120);
}

void drawSierpinskiTriangleRec(GWindow& gw, GPoint start, int length, int order) {
    if (order == 0) {
        drawOneTriangle(gw, start, length);
        return;
    }
    
    // Triangle 1 of the current order
    drawSierpinskiTriangleRec(gw, start, length / 2.0, order - 1);

    // Triangle 2 of the current order
    GPoint p2(start.getX() + length / 4.0, start.getY() - length * sqrt(3) / 4.0);
    drawSierpinskiTriangleRec(gw, p2, length / 2.0, order - 1);
    
    // Triangle 3 of the current order
    GPoint p3(start.getX() + length / 2.0, start.getY());
    drawSierpinskiTriangleRec(gw, p3, length / 2.0, order - 1);
}

void drawSierpinskiTriangle(GWindow& gw, int length, int order) {
    // Edge case
    if (order < 0 || length < 0) return;

    // Bottom left corner of the first triangle in the center of the window
    GPoint start((gw.getWidth() - length) / 2.0, (gw.getHeight() + length * sqrt(3) / 2.0) / 2.0);

    drawSierpinskiTriangleRec(gw, start, length, order);
}

int main() {
    int length = getInteger("enter length: ");
    int order = getInteger("enter order: ");

    GWindow gw;
    
    drawSierpinskiTriangle(gw, length, order);
    
    return 0;
}

