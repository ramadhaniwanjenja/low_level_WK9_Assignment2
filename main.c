#include <stdio.h>
#include <stdlib.h>

// ============================================
// QUESTION 1: NET SALARY CALCULATOR 
// ============================================

void calculateTax(double *grossSalary, double *tax) {
    if (*grossSalary <= 100) {
        *tax = 0;
    } else if (*grossSalary <= 300) {
        *tax = *grossSalary * 0.20;
    } else {
        *tax = *grossSalary * 0.28;
    }
}