# push_swap

A 42 Amman project: sort a list of integers using two stacks (`a` and `b`) and a small set of moves, printing the moves used.

| Move | Effect |
| --- | --- |
| `sa` `sb` `ss` | swap the top two elements of a, b, or both |
| `pa` `pb` | push the top of one stack onto the other |
| `ra` `rb` `rr` | rotate up: the top element goes to the bottom |
| `rra` `rrb` `rrr` | rotate down: the bottom element goes to the top |

## How it sorts

Small inputs (up to 5 numbers) use hand-written cases. Larger inputs are replaced by their rank (0 to n-1) and then sorted with **binary radix sort**: for each bit, numbers with a 0 bit are pushed to `b` and the rest are rotated, then everything is pushed back.

Measured on random input: 100 numbers in about 1,084 moves, 500 numbers in about 6,784 moves.

## Usage

```sh
make
./push_swap 3 2 1          # ra, sa
./push_swap "4 67 -3 12"   # numbers can also come as one string
```

It prints `Error` to stderr for non-numbers, duplicates, or values outside the `int` range. With no arguments it prints nothing.

## Author

[thaqer](https://github.com/thaqer), 42 Amman. Originally kept in [42amman_journey](https://github.com/thaqer/42amman_journey).
