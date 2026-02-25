*This project has been created as part of the 42 curriculum by yucchen.*

# Push_swap

## Description
Push_swap is a C project centered around sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions.

In this project, I utilize a **Radix Sort** algorithm for large datasets and a specific **Small Sort** logic for handling up to 5 elements.

## Features
- **Stack Implementation**: Built using a doubly linked list structure for efficient manipulation.
- **Index Compression**: Includes a pre-sorting "ranking" step to simplify the sorting logic.
- **Error Handling**: Robust validation for non-numeric inputs, duplicates, and integer overflows.
- **Modular Code**: Operations (swap, push, rotate, reverse rotate) are isolated into their own modules.

## Instructions

### Compilation
```bash
make
```
This will also trigger the compilation of the internal `libft` library.

### Execution
Run the executable with a list of integers:
```bash
./push_swap 4 67 3 87 23
```

## Operations
The program uses the following stack operations:
- `sa` / `sb` / `ss`: Swap the first 2 elements.
- `pa` / `pb`: Push an element from one stack to another.
- `ra` / `rb` / `rr`: Rotate all elements up by 1.
- `rra` / `rrb` / `rrr`: Reverse rotate all elements down by 1.
