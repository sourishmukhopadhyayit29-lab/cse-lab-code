#include <stdio.h>
#include <string.h>

struct student {
    int roll;
    char name[50];
    float marksInPhysics;
    float marksInChemistry;
    float marksInMathematics;
    float total;
};

void calculateTotal(struct student *s) {
    s->total = s->marksInPhysics + s->marksInChemistry + s->marksInMathematics;
}

int main() {
    struct student s[100], temp;
    int n, i, j;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);

        printf("Roll No             : ");
        scanf("%d", &s[i].roll);

        printf("Name                : ");
        scanf("%s", s[i].name);

        printf("Marks in Physics    : ");
        scanf("%f", &s[i].marksInPhysics);

        printf("Marks in Chemistry  : ");
        scanf("%f", &s[i].marksInChemistry);

        printf("Marks in Mathematics: ");
        scanf("%f", &s[i].marksInMathematics);

        calculateTotal(&s[i]);
    }

    // Bubble sort descending order
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].total < s[j + 1].total) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    // Display sorted list
    printf("\n============================================================\n");
    printf("    STUDENT LIST IN DESCENDING ORDER OF TOTAL MARKS\n");
    printf("============================================================\n");
    printf("%-5s %-15s %-10s %-10s %-10s %-10s\n",
           "Roll", "Name", "Physics", "Chemistry", "Maths", "Total");
    printf("------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-5d %-15s %-10.2f %-10.2f %-10.2f %-10.2f\n",
               s[i].roll,
               s[i].name,
               s[i].marksInPhysics,
               s[i].marksInChemistry,
               s[i].marksInMathematics,
               s[i].total);
    }
    printf("============================================================\n");

    return 0;
}
