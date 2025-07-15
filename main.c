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

void calculateNetSalary(double *grossSalary, double *netSalary) {
    double tax, medical, maternity, social;
    
    calculateTax(grossSalary, &tax);
    calculateMedicalInsurance(grossSalary, &medical);
    calculateMaternityLeave(grossSalary, &maternity);
    calculateSocialSecurity(grossSalary, &social);
    
    *netSalary = *grossSalary - tax - medical - maternity - social;
}

void runSalaryCalculator() {
    double grossSalary, netSalary;
    
    printf("=== NET SALARY CALCULATOR ===\n");
    printf("Enter gross salary: $");
    scanf("%lf", &grossSalary);
    
    calculateNetSalary(&grossSalary, &netSalary);
    
    printf("Gross Salary: $%.2f\n", grossSalary);
    printf("Net Salary: $%.2f\n", netSalary);
    
}