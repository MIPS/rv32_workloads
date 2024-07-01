#include <stdio.h>

// Function to calculate the sum of the first N positive integers
unsigned int calculate_sum(unsigned int N) {
    unsigned int sum = 0;
    for (unsigned int i = 1; i <= N; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    unsigned int N = 100; // Change N to the desired value
    unsigned int result = calculate_sum(N);
    printf("Sum of the first %u positive integers: %u\n", N, result);
    return 0;
}

