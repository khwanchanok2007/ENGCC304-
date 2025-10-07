#include <stdio.h>

int main()
{
    int score = 0;
    printf("Please enter your score: ");
    scanf("%d", &score);
    
    if (score >= 80) {
        printf("A!\n");
    }
    else if (score >= 75 && score < 80) {
        printf("B+!\n");
    }
    else if (score >= 70 && score < 75) {
        printf("B!\n");
    }
    else if (score >= 65 && score < 70) {
        printf("C+!\n");
    }
    else if (score >= 60 && score < 65) {
        printf("C!\n");
    }
    else if (score >= 55 && score < 60) {
        printf("D+!\n");
    }
    else if (score >= 50 && score < 55) {
        printf("D!\n");
    }
    else if (score < 50) {
        printf("F!\n");
    }
    else
    {
        printf("please enter number only.");
    }
    return 0;
}
