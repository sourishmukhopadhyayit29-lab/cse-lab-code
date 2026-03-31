#include <stdio.h>
#include<math.h>
int main() {
    int marks;
    char grade;

    printf("Enter marks: ");
    scanf("%d", &marks);

    grade = (marks >= 90) ? 'O' :
            (marks >= 80) ? 'E' :
            (marks >= 70) ? 'A' :
            (marks >= 60) ? 'B' :
            (marks >= 50) ? 'C' :
            (marks >= 40) ? 'D' : 'F';

    printf("Grade = %c\n", grade);

    return 0;
}