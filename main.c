#include <stdio.h>
#include <stdlib.h>
#include <string.h> //need this for string manipulation

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

// Forward declarations for other team members' functions
void runNameSorting();
void runMemoryManagement();

int main() {
    int choice;
    
    while (1) {
        printf("\n=== PROJECT MENU ===\n");
        printf("1. Net Salary Calculator\n");
        printf("2. Name Sorting\n");
        printf("3. Memory Management\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                runSalaryCalculator();
                break;
            case 2:
                printf("Name Sorting - To be implemented by Sipho\n");
                break;
            case 3:
                printf("Memory Management - To be implemented by Tejiri\n");
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // ============================================
        // QUESTION 2: NAME SORTINGGGGGGGGG
        // ============================================
        //ASCENDING ORDER Declaring of two persons names so they can be compared comparitively.
        int compare_asc(const char *name1, const char *name2) {
            return strcmp(name1, name2);
        }

        //DESCENDING ORDER DECLARATION OF CONSTS
        int compare_desc(const char *name1, const char *name2) {
            return strcmp(name2, name1); // Swap arguments for descending order
        }

        void bubble_sort(char names[][100], int count, int (*compare)(const char *, const char *)) {
            char temp[100]; // Temp holder for sorting names

            for (int i = 0; i < count - 1; i++) {
                for (int j = 0; j < count - i - 1; j++) {
                    //compare func used via func pointer
                    if (compare(names[j], names[j+1]) > 0) {
                        //Swap the names for comparison
                        strcpy(temp, names[j]);
                        strcpy(names[j], names[j+1]);
                        strcpy(names[j+1], temp);
                    }
                }
            }
        }


    }
    
    return 0;
}