// Purpose: Implementation of the Area class functions.

#include "area.h"

// function to calculate the area of a rectangle
double Area::rectangleArea(double length, double width)
{
    return length * width;
}

// function to calculate the area of a circle
double Area::circleArea(double radius)
{
    return 3.14159 * radius * radius;
}

// function to calculate the area of a square
double Area::SquareArea(double side)
{
    return side * side;
}