*This project has been created as part of the 42 curriculum by pedrferr.*

# Push_swap

A C program that sorts a list of integers using two stacks and a restricted set of
operations, aiming to produce the lowest possible number of instructions.

## Description

Push_swap is an algorithmic project focused on sorting integers using two stacks (A and B)
and a limited set of operations. The objective is not only to sort correctly, but to do so
with the smallest possible number of operations, respecting strict constraints.

## Allowed Operations

The program may only use the following instructions:

* `sa`, `sb`, `ss`
* `pa`, `pb`
* `ra`, `rb`, `rr`
* `rra`, `rrb`, `rrr`

These operations manipulate the top elements of stacks A and B.

## Algorithm Strategy

* For very small inputs (≤ 3 or ≤ 5 numbers), direct sorting logic is used.
* For larger inputs, an index-based **Radix Sort** approach is applied, adapted to stack
  operations and bitwise comparison.

## Usage

```bash
make
./push_swap 3 2 1
```

The program outputs one instruction per line to sort the stack in ascending order.

## Error Handling

The program prints `Error` to stderr if:

* an argument is not a valid integer
* a value is outside the `int` limits
* duplicate numbers are provided

If no arguments are given, nothing is displayed.

## Resources

* Video (Radix Sort explanation):
  [https://www.youtube.com/watch?v=XiuSW_mEn7g](https://www.youtube.com/watch?v=XiuSW_mEn7g)

* Stack data structure:
  [https://en.wikipedia.org/wiki/Stack_(abstract_data_type)](https://en.wikipedia.org/wiki/Stack_%28abstract_data_type%29)

* Radix Sort:
  [https://en.wikipedia.org/wiki/Radix_sort](https://en.wikipedia.org/wiki/Radix_sort)

## AI Usage

AI tools were used only to help understand the subject and review algorithm concepts.
All implementation decisions and code were written and fully understood by the author.
