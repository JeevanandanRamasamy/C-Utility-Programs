#include <stdio.h>
#include <stdlib.h>

int boardX, boardY, plrX, plrY, goalX, goalY, monX, monY;

void printBoard() {
    for (int i = boardY - 1; i >= 0; --i) {
        for (int j = 0; j < boardX; ++j) {
            if (j == plrX && i == plrY)
                printf("%s", "P ");
            else if (j == goalX && i == goalY)
                printf("%s", "G ");
            else if (j == monX && i == monY)
                printf("%s", "M ");
            else
                printf("%s", ". ");
        }
        printf("\n");
    }
}

void plrMove() {
    char dir;
    if (scanf(" %c", &dir) && !feof(stdin)) {
        if (dir == 'N' && plrY < boardY - 1)
            plrY++;
        else if (dir == 'W' && plrX > 0)
            plrX--;
        else if (dir == 'S' && plrY > 0)
            plrY--;
        else if (dir == 'E' && plrX < boardX - 1)
            plrX++;
        else {
            printf("invalid move\n");
            plrMove();
        }
    }
}

void verticalMove();

void horizontalMove() {
    if (plrX > monX && (monX + 1 != goalX || monY != goalY)) {
        monX++;
        printf("Monster moves E\n");
    }
    else if (plrX < monX && (monX - 1 != goalX || monY != goalY)) {
        monX--;
        printf("Monster moves W\n");
    }
    else
        verticalMove();
}

void verticalMove() {
    if (plrY > monY && (monY + 1 != goalY || monX != goalX)) {
        monY++;
        printf("Monster moves N\n");
    }
    else if (plrY < monY && (monY - 1 != goalY || monX != goalX)) {
        monY--;
        printf("Monster moves S\n");
    }
    else
        horizontalMove();
}

void monMove() {
    if (abs(plrX - monX) > abs(plrY - monY))
        horizontalMove();
    else if (abs(plrX - monX) < abs(plrY - monY)) 
        verticalMove();
    else {
        if (rand() < 0.5) 
            horizontalMove();
        else 
            verticalMove();
    }
}

int startGame() {
    while (!feof(stdin)) {
        plrMove();
        if (plrX == goalX && plrY == goalY)
            return 1;
        else if (plrX == monX && plrY == monY)
            return 0;
        monMove();
        if (plrX == monX && plrY == monY)
            return 0;
        printBoard();
    }
    return 1;
}

int main(int argc, char** argv) {
    boardX = atoi(argv[1]);
    boardY = atoi(argv[2]);
    plrX = atoi(argv[3]);
    plrY = atoi(argv[4]);
    goalX = atoi(argv[5]);
    goalY = atoi(argv[6]);
    monX = atoi(argv[7]);
    monY = atoi(argv[8]);
    printBoard();
    if (startGame())
        printf("player wins!\n");
    else
        printf("monster wins!\n");
    return EXIT_SUCCESS;
}