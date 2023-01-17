#include <stdio.h>
int main(void) {
    int grade;
    printf("Enter a numerical grade: ");
    scanf("%d", &grade);
    int result=grade/10;
    if (grade >= 100 || grade <= 0)
    {
        switch (grade)
        {
        case 100:
            printf("A");
            break;
        case 0:
            printf("F");
            break;
        default:
            printf("Error: the grade is smaller than 0 or greater than 100");
            break;
        }
    }
    else 
    {
        switch (result)
        {
        case 9:
            printf("A");
            break;
        case 8:
            printf("B");
            break;
        case 7:
            printf("C");
            break;
        case 6:
            printf("D");
            break;
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
            printf("F");
            break;
        }
    }
return 0;
}