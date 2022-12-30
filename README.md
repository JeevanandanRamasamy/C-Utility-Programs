# C-Programs

## factor.c

factor takes a single integer n as a command-line argument and finds its prime factors, excluding 1. The output consists of a single line listing each prime factor in non-decreasing order. If n is prime, factor prints n itself. If there are repeat factors, the factor is printed as many times as it divides n. This program works for 2 ≤ n ≤ 2^31 − 1 (i.e., n will fit in a signed 32-bit integer).

./factor 247

13 19

./factor 7

7

./factor 32

2 2 2 2 2

## grep.c

grep takes a string as a command-line argument and then reads from stdin until the user closes stdin (with ctrl-d, written ^D below). It prints every line that contains the given string. It is case-sensitive by default, but case-insensitive if the command line option -i is given before the string. Strings may have arbitrary length.

./grep ello

Hello there&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# input

Hello there&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# output

Hi there&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# input, ignored since it doesn't contain "ello"

The sun is yellow&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# input

The sun is yellow&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# output

YELLOW&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# input, ignored since "ello" is case-sensitive

^D&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# close stdin

./grep -i ello

Hello there&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# input

Hello there&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# output

YELLOW&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# input

YELLOW&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# output

^D&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# close stdin

## sort.c

sort reads from stdin and sorts its input. If no command-line option is given, it uses case-insensitive lexicographic sorting. If the -n option is given, it uses numeric sorting (assuming all inputs will be valid integers). There should not be any spaces in the input string since it would be counted as multiple arguments. There can be an arbitrary number of strings, of arbitrary length.

./sort

juice

aPPLES

donuts

Banana

^D&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# close stdin

aPPLES

Banana

donuts

juice

2

./sort -n

5

-3

2

7

^D&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# close stdin

-3

2

5

7

./sort

274

10101

123

10

^D&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# close stdin

10

10101

123

274

## uniq.c

uniq reads from stdin and filters out duplicate lines of input. It reads lines from stdin, and then print each unique line along with a count of how many times it appeared. Input is case-sensitive, so “hello” and “Hello” are not duplicates. There can be an arbitrary number of strings, of arbitrary length. Note that only adjacent duplicates count, so if the input were the lines “hello”, “world”, and “hello” again, all three would be treated as unique.

./uniq

hello

hello

hello

world

world

^D&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# close stdin

3 hello

2 world

3

./uniq

hello


world

hello

^D&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# close stdin

1 hello

1 world

1 hello

## monster.c

This program is a game of a player and monster moving on a 2D grid. The player has a goal to reach. The monster wants to reach the player.

In each turn, the player moves one square, then the monster moves towards the player. If either reaches their target, the game ends immediately. If the player reaches the goal, it prints “player wins!”. If the monster reaches the player, it prints “monster wins!”.

The player’s moves (N, W, S, or E) are read from stdin, one per line. If the move is invalid (e.g., the player tries to move off the board), it prints “invalid move” and reads a new move. If the player intentionally moves into the monster’s square, it counts as the monster winning.

On its turn, the monster considers the horizontal and vertical distances to reach the player and moves to reduce the larger of these two. If they’re the same, the monster chooses one of the two at random. Its move is printed, e.g., “monster moves E”. The monster cannot move onto the goal; if the monster’s intended move would put it on the goal square, then the monster forfeits its move that turn. 

The board is specified by command-line parameters:

./monster boardX boardY plrX plrY goalX goalY monX monY

boardX - Number of squares in xdirection

boardY - Number of squares in ydirection

plrX - Player xstarting position

plrY - Player ystarting position

goalX - Goal xlocation

goalY - Goal ylocation

monX - Monster xstarting position

monY - Monster ystarting position

At the beginning of the game, and after each round where no one won, the board is printed as shown in the examples below. 

./monster 5 5 0 0 1 1 3 4

. . . M .

. . . . .

. . . . .

. G . . .

P . . . .

E

monster moves S

. . . . .

. . . M .

. . . . .

. G . . .

. P . . .

N

player wins!

./monster 4 6 0 0 2 4 1 1

. . . .

. . G .

. . . .

. . . .

. M . .

P . . .

E

monster moves S

monster wins!
