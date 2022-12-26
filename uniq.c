#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** list;
char current[100], next[100];
int ctr;

void addToList(int num) {
    list[ctr] = malloc(100 * sizeof(char));
    sprintf(list[ctr], "%d %s", num, current);
    ++ctr;
}

void counter() {
    int i = 1;
    if (!feof(stdin))
        scanf("%s", current);
    while (!feof(stdin)) {
        scanf("%s", next);
        if (!strcmp(current, next))
            ++i;
        else {
            addToList(i);
            strcpy(current, next);
            i = 1;
        }
    }
    if (i > 1)
        addToList(i - 1);
    list = realloc(list, ctr * sizeof(char*));
}

int main(int argc, char** argv) {
    list = malloc(100 * sizeof(char*));
    ctr = 0;
    counter();
    for (int i = 0; i < ctr; ++i) {
        printf("%s\n", list[i]);
        free(list[i]);
    }
    free(list);
    return EXIT_SUCCESS;
}