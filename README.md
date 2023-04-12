# Push_swap

The Push_swap project is a sorting algorithm project that requires sorting data on a stack using a limited set of instructions, with the lowest possible number of actions. The project involves writing the program in C.

## Rules

The game consists of two stacks named "a" and "b". Stack "a" initially contains a random number of either positive or negative numbers without any duplicates. Stack "b" is empty. The goal is to sort numbers in ascending order into stack "a".

The following operations are available to manipulate the stacks:

- **sa** : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- **sb** : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- **ss** : sa and sb at the same time.
- **pa** : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- **pb** : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- **ra** : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- **rb** : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- **rr** : ra and rb at the same time.
- **rra** : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- **rrb** : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- **rrr** : rra and rrb at the same time.

## Algorithm

The algorithm works by sorting a stack of values in two stacks, A and B. First, the algorithm identifies the biggest valid ascending consecutive index in stack A, which is the largest "loop." Then, it moves all values in stack A that are not part of the loop to stack B, grouping them if there are more than 100 values. Next, the algorithm finds the best spot in stack A to insert each value from stack B by looking for the closest possible index with the least rotation from the B value. Finally, the stack is rotated back to its minimum index (0) to complete the sorting process. This method is optimized for large stacks, but may be slower for smaller stacks.

Check out this [guide](https://github.com/VBrazhnik/Push_swap/wiki/Algorithm) for a more detailed explanation but without grouping.

## Usage

Clone the repository and navigate to the project directory. To compile the program, execute the following command in your terminal:
```bash
make
```
An executable file called `push_swap` will be created. Run the file:
```bash
ARG="3 5 1 2 4"; ./push_swap $ARG
```
Here, `ARG` is the numbers in stack A to be sorted. After running the command, you can see the operations need to sort the numbers in the stack. Copy the `ARG` and the operations and paste it in the [visualizer](https://codepen.io/ahkoh/full/bGWxmVz) to see how the numbers are sorted.

See `test_cases_push_swap.txt` for more test cases.

## Demo
![push_swap](https://user-images.githubusercontent.com/73651474/231321992-a851ca96-20d9-461c-b3e1-172aab35324d.gif)

## Credit
This project was completed as part of the curriculum of the Ecole 42 program. The instructions for the project were provided by the school.
