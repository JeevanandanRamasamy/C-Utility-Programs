#include <stdio.h>
#include <stdlib.h>

void factorize(int num) {
    int i = 2;
    while (i < num/2) {
        if (num % i == 0) {
            printf("%d ", i);
            num /= i;
        }
        else 
            ++i;
    }
    printf("%d\n", num);
}

int main(int argc, char** argv) {
    if (argv[1])
        factorize(atoi(argv[1]));
    return EXIT_SUCCESS;
}