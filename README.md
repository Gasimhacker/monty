# Monty Interpreter

Monty is a repository that implements a Monty interpreter, which allows you to execute Monty bytecode files. The Monty language is a simple stack-based programming language. This interpreter provides functionality for various opcodes, allowing you to manipulate the stack and perform arithmetic and logical operations.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Supported Opcodes](#supported-opcodes)
- [Examples](#examples)

## Installation

To use the Monty interpreter, you need to clone the repository to your local machine:

`git clone https://github.com/Gasimhacker/monty.git`


After cloning the repository, navigate to the project directory:

`cd monty`


Compile the source code using a C compiler (e.g., gcc):

`gcc -Wall -Werror -Wextra -pedantic *.c -o monty`


Now, you have successfully installed the Monty interpreter.

## Usage

You can run Monty bytecode files using the following command:

`./monty <file>`


Replace `<file>` with the path to the Monty bytecode file you want to execute.

## Supported Opcodes

The Monty interpreter supports the following opcodes:

1. push <int>: Pushes an element onto the stack.
2. pall: Prints all the elements in the stack.
3. pint: Prints the value at the top of the stack.
4. pop: Removes the top element from the stack.
5. swap: Swaps the top two elements of the stack.
6. add: Adds the top two elements of the stack.
7. nop: Does nothing.
8. sub: Subtracts the top element from the second top element.
9. mul: Multiplies the top two elements of the stack.
10. div: Divides the second top element by the top element.
11. mod: Computes the modulo of the second top element by the top element.
12. # <comment>: Represents a comment. The interpreter ignores the rest of the line.
13. pchar: Prints the character at the top of the stack.
14. pstr: Prints the string contained in the stack until a null terminator or non-ASCII character is encountered.
15. rotl: Rotates the stack to the top.
16. rotr: Rotates the stack to the bottom.
17. stack: Sets the format of the data to stack (LIFO).
18. queue: Sets the format of the data to a queue (FIFO).

## Examples

Here are some examples of Monty bytecode files:

Example 1: push and pall

File: example.m


`push 1`
`push 2`
`push 3`
`pall`


Command:

`./monty example.m`


Output:


3
2
1


Example 2: add, pint, and pop

File: arithmetic.m


`push 10`
`push 5`
`add`
`pint`
`pop`
`pint`


Command:

`./monty arithmetic.m`


Output:


15
10

