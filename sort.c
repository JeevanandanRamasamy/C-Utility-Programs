#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void num_sort() {
    int c = 0, *list = malloc(100 * sizeof(int));
    while (!feof(stdin)) {
        scanf("%d", &list[c]);
        ++c;
    }
    c--;
    list = realloc(list, c * sizeof(int));
    for (int i = 1; i < c; ++i) {
        int key = list[i];
        int j = i - 1;
        while (j >= 0 && list[j] > key) {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key;
    }
    for (int i = 0; i < c; ++i)
        printf("%d\n", list[i]);
    free(list);
}

void char_sort() {
    char** list = malloc(100 * sizeof(char*));
    int c = 0;
    while (!feof(stdin)) {
        list[c] = malloc(100 * sizeof(char));
        scanf("%s\n", list[c]);
        ++c;
    }
    list = realloc(list, c * sizeof(char*));
    for (int i = 1; i < c; ++i) {
        char key[100];
        strcpy(key, list[i]);
        int j = i - 1;
        while (j >= 0 && strcasecmp(list[j], key) > 0) {
            strcpy(list[j + 1], list[j]);
            j = j - 1;
        }
        strcpy(list[j + 1], key);
    }
    for (int i = 0; i < c; ++i) {
        printf("%s\n", list[i]);
        free(list[i]);
    }
    free(list);
}

int main(int argc, char** argv) {
    if (argv[1] && !strcmp(argv[1], "-n"))
        num_sort();
    else
        char_sort();
    return EXIT_SUCCESS;
}