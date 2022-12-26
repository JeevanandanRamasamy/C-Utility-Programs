#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    char* input = NULL;
    size_t n = 0;
    while (!feof(stdin)) {
        getline(&input, &n, stdin);
        if (argv[1]) {
            if ((!strcmp(argv[1], "-i") && strcasestr(input, argv[2])) || strstr(input, argv[1]))
                printf("%s", input);
        }
    }
    free(input);
    return EXIT_SUCCESS;
}