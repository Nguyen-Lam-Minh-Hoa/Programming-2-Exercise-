// program to find sum using function
#include <stdio.h>

// Function declaration
int add(int a, int b);

int main() {
    int num_1, num_2, sum;

    // Input two integers
    printf("Enter two integers: ");
    scanf("%d %d", &num_1, &num_2);

    // Function call
    sum = add(num_1, num_2);

    // Output result
    printf("Sum: %d\n", sum);

    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;
}
