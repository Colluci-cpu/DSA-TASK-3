#include <stdio.h>

// a) Sum of first Natural numbers
int sum(int n) {
    if (n == 0) return 0;          // base case
    return n + sum(n - 1);
}

// b) Factorial
long factorial(int n) {
    if (n == 0 || n == 1) return 1;   // base case
    return n * factorial(n - 1);
}

// c) Nth term of Fibonacci (0, 1, 1, 2, 3, 5, ...)
int fib(int n) {
    if (n == 0) return 0;          // base cases
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

// d) Generate N terms of Fibonacci
void fibSeries(int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", fib(i));
    printf("\n");
}

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    printf("Sum of first %d numbers = %d\n", n, sum(n));
    printf("Factorial of %d = %ld\n", n, factorial(n));
    printf("Fibonacci term %d = %d\n", n, fib(n));
    printf("First %d Fibonacci terms: ", n);
    fibSeries(n);
    return 0;
}
