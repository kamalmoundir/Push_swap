# Push\_swap

Push\_swap is an algorithmic project in C designed to sort a stack of integers using a limited set of operations. The challenge is to achieve the sorting with the fewest possible moves.

## Project Description

Push\_swap uses two stacks, `a` and `b`, and allows a series of operations to move and sort the elements. The program must be able to receive a list of unsorted integers and produce a sequence of commands to sort them.

### Project Structure

- **push\_swap.c**: Main file handling the program's logic.
- **operations.c**: Implements the allowed operations on the stacks.
- **utils.c**: Helper functions for error handling, input validation, etc.
- **Makefile**: File to automate the project's compilation.
- **README.md**: This file, documenting the project.

## Allowed Operations

- `sa` (swap a): Swap the first two elements of stack `a`.
- `sb` (swap b): Swap the first two elements of stack `b`.
- `ss`: Execute `sa` and `sb` simultaneously.
- `pa` (push a): Move the first element from stack `b` to the top of `a`.
- `pb` (push b): Move the first element from stack `a` to the top of `b`.
- `ra` (rotate a): Shift all elements of `a` up by one position.
- `rb` (rotate b): Shift all elements of `b` up by one position.
- `rr`: Execute `ra` and `rb` simultaneously.
- `rra` (reverse rotate a): Shift all elements of `a` down by one position.
- `rrb` (reverse rotate b): Shift all elements of `b` down by one position.
- `rrr`: Execute `rra` and `rrb` simultaneously.

## Installation

### Prerequisites

- GCC or any C-compatible compiler.
- Makefile to compile the project.

### Clone the Repository

```bash
git clone https://github.com/kamalmoundir/push_swap.git
cd push_swap
```

### Compilation

Compile the project using the `make` command:

```bash
make
```

This command will generate the `push_swap` executable.

## Usage

Run the program with a list of integers to sort:

```bash
./push_swap <list_of_integers>
```

Example:

```bash
./push_swap 2 1 3 6 5 8
```

The program will output the sequence of operations needed to sort the stack.

### Integration with Checker

You can verify the correctness of the output using a checker script:

```bash
./push_swap <list_of_integers> | ./checker <list_of_integers>
```

## Sorting Strategies

The project can implement various sorting strategies, such as:

- **Insertion Sort**: Efficient for small lists.
- **Radix Sort**: Useful for larger lists.

## Testing

It is recommended to test the program with different lists of integers to ensure the algorithm's efficiency and correctness. Automated scripts can also be used to generate test cases and verify performance.

## Contribution

Contributions are welcome. Please open a Pull Request with your changes or improvements.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

Thanks to the 42 school community for providing this challenging and educational project.

