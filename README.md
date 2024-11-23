# C-Utility Programs

This repository contains a collection of command-line utility programs written in C, demonstrating various useful algorithms and concepts. Each program serves a distinct purpose and provides useful functionality, ranging from text processing to game mechanics.

---

## Programs

### "factor.c"
A program to find the prime factors of a given integer "n".

- Takes an integer "n" as input and prints its prime factors in non-decreasing order.
- If "n" is prime, it prints "n" itself.
- If "n" has repeated factors, the factor is printed multiple times.
- Works for integers between 2 ≤ n ≤ 2^31 − 1.

**Example usage:**
```bash
$ ./factor 247
13 19

$ ./factor 7
7

$ ./factor 32
2 2 2 2 2
```

---

### "grep.c"
This program searches for a given string in input from stdin and prints every line that contains the string.

- By default, it is case-sensitive.
- Use the "-i" option to make the search case-insensitive.
- The program reads from stdin and continues until the user closes it (with Ctrl-D).

**Example usage:**
```bash
$ ./grep ello
Hello there
Hi there      # ignored, doesn’t contain “ello”
The sun is yellow
YELLOW         # ignored, “ello” is case-sensitive

$ ./grep -i ello
Hello there
YELLOW         # output is case-insensitive
```

---

### "sort.c"
Sorts the input from stdin in either lexicographical or numerical order.

- By default, sorts the input in a case-insensitive lexicographic order.
- Use the "-n" option for numeric sorting.

**Example usage:**
```bash
$ ./sort
juice
aPPLES
donuts
Banana
^D    # close stdin
```
Output
```
aPPLES
Banana
donuts
juice
```
```bash
$ ./sort -n
5
-3
2
7
^D    # close stdin
```
Output
```
-3
2
5
7
```

---

### "uniq.c"
This program filters out duplicate lines from stdin, counting the number of occurrences of each unique line.

- The input is case-sensitive.
- Only adjacent duplicates are considered as duplicates.

**Example usage:**

```bash
$ ./uniq
hello
hello
hello
world
world
^D    # close stdin
```
Output
```
3 hello
2 world
```
```bash
$ ./uniq
hello
world
hello
^D    # close stdin
```
Output
```
1 hello
1 world
1 hello
```

---

### "monster.c"
A simple text-based game where a player moves on a 2D grid, trying to avoid being caught by a monster.

- The player moves one square at a time and can use the directions "N" (North), "S" (South), "E" (East), or "W" (West).
- The monster moves each turn toward the player, either reducing the horizontal or vertical distance, depending on which is larger.
- If the player reaches the goal, the game ends with "player wins!".
- If the monster catches the player, the game ends with "monster wins!".
- The game board and positions are defined via command-line arguments.

**Example usage:**
```bash
$ ./monster 5 5 0 0 1 1 3 4
Initital Board:
. . . M .
. . . . .
. . . . .
. G . . .
P . . . .

Player move: E
monster moves S

New board:
. . . . .
. . . M .
. . . . .
. G . . .
. P . . .

Player move: N
Player wins!
```

---

## Building and Running

To compile and run any of the programs:

1. Clone the repository or download the source files.
2. Use "gcc" (or another C compiler) to compile the desired program.
   For example, to compile "factor.c":
   ```bash
   gcc factor.c -o factor
   ```
3. Run the program with the appropriate command-line arguments, as shown in the examples above.
