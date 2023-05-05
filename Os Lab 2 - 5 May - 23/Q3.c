#include <stdio.h>

int main() {
    int k, count = 0;
    printf("Enter an integer: ");
    scanf("%d", &k);

    while(k) {
        if(k % 10 == 0) {
            count++;
        }
        k /= 10;
    }

    printf("The number of 0's in the integer is: %d\n", count);
    return 0;
}

