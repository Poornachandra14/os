#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int emp_id;
    char emp_name[50];
    float emp_salary;
};

int main() {
    struct Employee emp;

    // Writing employee details to the file
    FILE *file_write = fopen("employee_details.bin", "wb");
    if (file_write == NULL) {
        printf("Error opening file for writing!\n");
        exit(1);
    }

    emp.emp_id = 1;
    sprintf(emp.emp_name, "John");
    emp.emp_salary = 50000.0;
    fwrite(&emp, sizeof(struct Employee), 1, file_write);

    emp.emp_id = 2;
    sprintf(emp.emp_name, "Alice");
    emp.emp_salary = 60000.0;
    fwrite(&emp, sizeof(struct Employee), 1, file_write);

    fclose(file_write);

    // Reading and printing employee details from the file
    FILE *file_read = fopen("employee_details.bin", "rb");
    if (file_read == NULL) {
        printf("Error opening file for reading!\n");
        exit(1);
    }

    printf("Employee details:\n");
    printf("ID\tName\tSalary\n");
    printf("------------------------\n");
    while (fread(&emp, sizeof(struct Employee), 1, file_read)) {
        printf("%d\t%s\t%.2f\n", emp.emp_id, emp.emp_name, emp.emp_salary);
    }

    fclose(file_read);

    return 0;
}

