#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define FILENAME "employee_records.dat"
struct Employee {
    int id;
    char name[MAX_NAME_LENGTH];
    float salary;
};
void addEmployee();
void displayAllEmployees();
void updateEmployee();
void deleteEmployee();

int main() {
    int choice;

    while (1) {
        printf("\nEmployee Record Management System\n");
        printf("1. Add New Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Update Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAllEmployees();
                break;
            case 3:
                updateEmployee();
                break;
            case 4:
                deleteEmployee();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

void addEmployee() {
    struct Employee emp;
    FILE *file;

    file = fopen(FILENAME, "ab");
    if (file == NULL) {
        printf("Error opening file!\n"
