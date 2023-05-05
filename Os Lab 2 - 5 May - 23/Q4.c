#include <stdio.h>

int main() {
    int k, count = 0 , t;
    printf("Enter an integer: ");
    scanf("%d", &k);
    printf("Enter an t: ");
    scanf("%d", &t);
    while(k) {
        if(k % 10 == t) {
            count++;
        }
        k /= 10;
    }

    printf("The number of t in the integer is: %d\n", count);
    return 0;
}

