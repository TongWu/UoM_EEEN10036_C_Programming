#include <stdio.h>
int main(void) {
    int a; 
    int b;
    if (a!=0) {
        printf("Statement 0");
    }
    if (a>5){
        if (b>10) {
            printf("Statement 1");
        }
        else if (b==0){
            printf("Statement 2");
        }
        else {
            printf("Statement 3");
        }
    }
    else if (a<0) {
        printf("Statement 4");
    }
    else {
        printf("Statement 5");
    }
}