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

    printf("===!!! NET SALARY CALCULATOR !!!!===\n");
    printf("Enter your gross salary: $");
    scanf("%lf", &grossSalary);

    calculateNetSalary(&grossSalary, &netSalary);

    printf("Gross Salary: $%.2f\n", grossSalary);
    printf("Net Salary: $%.2f\n", netSalary);

}

// ============================================
// QUESTION 2: NAME SORTING
// ============================================

// ASCENDING ORDER Declaring of two persons names so they can be compared comparitively.
int compare_asc(const char *name1, const char *name2) {
    return strcmp(name1, name2);
}

// DESCENDING ORDER DECLARATION OF CONSTS
int compare_desc(const char *name1, const char *name2) {
    return strcmp(name2, name1); // Swap arguments for descending order
}

void bubble_sort(char names[][100], int count, int (*compare)(const char *, const char *)) {
    char temp[100]; // Temp holder for sorting names

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            // compare func used via func pointer
            if (compare(names[j], names[j + 1]) > 0) {
                // Swap the names for comparison
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

void runNameSorting() {
    char names[20][100]; //Array stores 20+ chars
    int num_names = 20;
    char order[5]; //To store "ASCEND" or "DESCEND"

    printf("=== NAME SORTING ===\n");
    printf("Please enter 20 full names:\n");

    //Taking names from the user and taking care of line endings
    //Clear the input buffer before reading strings with fgets
    while (getchar() != '\n');
    for (int i = 0; i < num_names; i++) {
        printf("Enter name %d: ", i + 1);
        fgets(names[i], sizeof(names[i]), stdin);
        // Remove trailing newline character from fgets
        names[i][strcspn(names[i], "\n")] = 0;
    }

    printf("\nEnter sorting order 'asc' for ascending OR 'desc' for descending: ");
    scanf("%s", order);

    // Function pointer to hold declared function
    int (*compare_func_ptr)(const char *, const char *);

    // Assigned appropriate func based on user input
    if (strcmp(order, "asc") == 0) {
        compare_func_ptr = compare_asc;
        printf("\nSort names in ascending order:\n");
    } else if (strcmp(order, "desc") == 0) {
        compare_func_ptr = compare_desc;
        printf("\nSort names in descending order:\n");
    } else {
        printf("Invalid order. Please enter 'asc' or 'desc'.\n");
        return; //Exiting if invalid input
    }

    // Calling bubble sort to do it's thing
    bubble_sort(names, num_names, compare_func_ptr);

    // Print all the sorted names
    for (int i = 0; i < num_names; i++) {
        printf("%s\n", names[i]);
    }
}

// ============================================
// QUESTION 3: MEMORY MANAGEMENT (Tejiri)
// ============================================

void runMemoryManagement() {
    int num_students = 10;
    char **emails;

    printf("=== MEMORY MANAGEMENT ===\n");

    // Allocate memory for 10 students (array of char pointers)
    emails = (char **)malloc(num_students * sizeof(char *));
    if (emails == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Input emails - clear buffer before reading strings
    while (getchar() != '\n');
    for (int i = 0; i < num_students; i++) {
        emails[i] = (char *)malloc(50 * sizeof(char)); // Allocate space for each email string
        if (emails[i] == NULL) {
            printf("Memory allocation for email failed at student %d!\n", i + 1);
            // Free previously allocated memory before exiting
            for (int j = 0; j < i; j++) {
                free(emails[j]);
            }
            free(emails);
            return;
        }
        printf("Enter email for student %d: ", i + 1);
        fgets(emails[i], 50, stdin);
        emails[i][strcspn(emails[i], "\n")] = 0;
    }

    printf("\n--- Emails Entered ---\n");
    for (int i = 0; i < num_students; i++) {
        printf("%d: %s\n", i + 1, emails[i]);
    }

    // Shrink the array to 6 students
    printf("\nShrinking the array to 6 students...\n");
    int original_num_students = num_students; // Store original count for robust freeing if realloc fails
    char **temp_emails = (char **)realloc(emails, 6 * sizeof(char *));

    if (temp_emails == NULL) {
        printf("Memory reallocation failed! Keeping original size and data.\n");
        // If realloc fails, 'emails' still points to the original memory block.
        // We need to free all 'original_num_students' emails first, then 'emails'.
        for (int i = 0; i < original_num_students; i++) {
            free(emails[i]);
        }
        free(emails);
        return;
    } else {
        emails = temp_emails;
        num_students = 6;
    }

    printf("\n--- Emails after shrinking ---\n");
    for (int i = 0; i < num_students; i++) {
        printf("%d: %s\n", i + 1, emails[i]);
    }


    //Free memory
    printf("\nFreeing allocated memory...\n");
    for (int i = 0; i < num_students; i++) {
        free(emails[i]);
    }
    free(emails);

    printf("Memory cleaned up successfully!\n");
}

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
                runNameSorting();
                break;
            case 3:
                runMemoryManagement();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}