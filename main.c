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

void calculateMedicalInsurance(double *grossSalary, double *medical) {
    *medical = *grossSalary * 0.05;
}

void calculateMaternityLeave(double *grossSalary, double *maternity) {
    *maternity = *grossSalary * 0.003;
}

void calculateSocialSecurity(double *grossSalary, double *social) {
    *social = *grossSalary * 0.03;
}