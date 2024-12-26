#include<stdio.h>
#include<math.h> // Required for the pow() function

void main() {
    int n, temp, noofdigit = 0, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;

    // Count the number of digits
    while (temp != 0) {
        noofdigit++;
        temp /= 10;
    }

    temp = n; // Restore original number for further processing

    // Calculate the sum of digits raised to the power of noofdigit
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, noofdigit); // Using pow() for the power calculation
        temp /= 10;
    }

    // Check if the sum equals the original number
    if (n == sum) {
        printf("%d is an Armstrong number\n", n);
    } else {
        printf("%d is not an Armstrong number\n", n);
    }
}
