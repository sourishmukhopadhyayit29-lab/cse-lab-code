#include <stdio.h>
#include <string.h>

struct employee {
    int empNo;
    char name[50];
    char department[50];
    float basicPay;
    float DA;
    float HRA;
    float grossSalary;
};

void calculateSalary(struct employee *emp) {
    emp->DA  = 0.40 * emp->basicPay;
    emp->HRA = 0.20 * emp->basicPay;
    emp->grossSalary = emp->basicPay + emp->DA + emp->HRA;
}

int main() {
    FILE *fin, *fout;
    struct employee emp[100], highest;
    int count = 0, i;

    // Open input file
    fin = fopen("I_P.txt", "r");
    if (fin == NULL) {
        printf("Error: Cannot open I_P.txt\n");
        return 1;
    }

    // Open output file
    fout = fopen("O_P.txt", "w");
    if (fout == NULL) {
        printf("Error: Cannot open O_P.txt\n");
        fclose(fin);
        return 1;
    }

    // Read all employees from file
    while (fscanf(fin, "%d %s %s %f",
                  &emp[count].empNo,
                  emp[count].name,
                  emp[count].department,
                  &emp[count].basicPay) == 4) {
        calculateSalary(&emp[count]);
        count++;
    }
    fclose(fin);

    // Find highest gross salary
    highest = emp[0];
    for (i = 1; i < count; i++) {
        if (emp[i].grossSalary > highest.grossSalary) {
            highest = emp[i];
        }
    }

    // Print all employees to output file
    fprintf(fout, "========================================\n");
    fprintf(fout, "         ALL EMPLOYEE DETAILS          \n");
    fprintf(fout, "========================================\n");

    for (i = 0; i < count; i++) {
        fprintf(fout, "Employee No   : %d\n",   emp[i].empNo);
        fprintf(fout, "Name          : %s\n",   emp[i].name);
        fprintf(fout, "Department    : %s\n",   emp[i].department);
        fprintf(fout, "Basic Pay     : %.2f\n", emp[i].basicPay);
        fprintf(fout, "DA (40%%)      : %.2f\n", emp[i].DA);
        fprintf(fout, "HRA (20%%)     : %.2f\n", emp[i].HRA);
        fprintf(fout, "Gross Salary  : %.2f\n", emp[i].grossSalary);
        fprintf(fout, "----------------------------------------\n");
    }

    // Print highest gross salary employee
    fprintf(fout, "\n========================================\n");
    fprintf(fout, "  EMPLOYEE WITH HIGHEST GROSS SALARY   \n");
    fprintf(fout, "========================================\n");
    fprintf(fout, "Employee No   : %d\n",   highest.empNo);
    fprintf(fout, "Name          : %s\n",   highest.name);
    fprintf(fout, "Department    : %s\n",   highest.department);
    fprintf(fout, "Basic Pay     : %.2f\n", highest.basicPay);
    fprintf(fout, "DA (40%%)      : %.2f\n", highest.DA);
    fprintf(fout, "HRA (20%%)     : %.2f\n", highest.HRA);
    fprintf(fout, "Gross Salary  : %.2f\n", highest.grossSalary);
    fprintf(fout, "========================================\n");

    fclose(fout);

    printf("Output written to O_P.txt\n");
    return 0;
}
