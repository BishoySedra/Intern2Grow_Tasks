// make header class for the calculator class

#pragma once
#ifndef CALC_H
#define CALC_H

class Calculator
{
public:
    // function to add two numbers
    double add(double num1, double num2);

    // function to subtract two numbers
    double subtract(double num1, double num2);

    // function to multiply two numbers
    double multiply(double num1, double num2);

    // function to divide two numbers
    double divide(double num1, double num2);
};

#endif