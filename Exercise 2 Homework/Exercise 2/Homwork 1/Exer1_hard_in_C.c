// swap a and b with function and pointer
#include <stdio.h>

void swap(int *a, int *b);

int main() {
    int a, b;

    // Input two integers
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Print before swapping
    printf("Before swap: a = %d, b = %d\n", a, b);

    // Call swap function
    swap(&a, &b);

    // Print after swapping
    printf("After swap: a = %d, b = %d\n", a, b);

    return 0;
}

// Function to swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}