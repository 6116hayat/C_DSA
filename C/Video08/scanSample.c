#include <stdio.h>

int main() {
    int age;
    float height;
    char name[50];

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your height in meters: ");
    scanf("%f", &height);

    printf("Enter your name: ");
    scanf("%s", name);

    printf("\nHello, %s! You are %d years old and %.2f meters tall.\n", name, age, height);

    return 0;
}
