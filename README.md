# Monty Recreation
#### Hi! This repo is a recreation of the Monty interpreter, made for Holberton school project 

------------


# AUTHORS.
## Alejandro Pineda Sánchez
- Git: https://github.com/Apinedas
- Twitter: https://twitter.com/Apsanchez2549
- Linkedin:
## Carlos Andres Pardo Rodriguez
- Git: https://github.com/ANDRES3021
- Twitter: https://twitter.com/CarlosA54648157
- Linkedin: https://www.linkedin.com/in/carlos-andres-pardo-rodriguez-8bbb90202/

# Learning Objectives
At the end of this project, you are expected to be able to explain to anyone , without the help of Google :


## General

------------


What do LIFO and FIFO mean
What is a stack, and when to use it
What is a queue, and when to use it
What are the common implementations of stacks and queues
What are the most common use cases of stacks and queues
What is the proper way to use global variables

# Requirements
## General

Allowed editors: vi , vim , emacs

All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c90

All your files should end with a new line

A README.md file, at the root of the folder of the project is mandatory

Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

You allowed to use a maximum of one global variable

No more than 5 functions per file

You are allowed to use the C standard library

The prototypes of all your functions should be included in your header file called monty.h

Don’t forget to push your header file

All your header files should be include guarded

You are expected to do the tasks in the order shown in the project

------------
# Tasks
## 0. push, pall
The opcode push pushes an element to the stack.

Usage: push <int>
where <int> is an integer
if <int> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
where is the line number in the file
You won’t have to deal with overflows. Use the atoi function
## 1. pint
The pint opcode

The opcode pint prints the value at the top of the stack, followed by a new line.

Usage: pint
If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE
## 2. pop
The pop opcode

The opcode pop removes the top element of the stack.

Usage: pop
If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE
## 3. swapThe swap opcode

The opcode swap swaps the top two elements of the stack.

Usage: swap
If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
## 4. add
The add opcode

The opcode add adds the top two elements of the stack.

Usage: add
If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter
## 5. nop
The nop opcode

The opcode nop doesn’t do anything.

Usage: nop

------------



# Links
- [FIFO and LIFO Accounting](http://https://en.wikipedia.org/wiki/FIFO_and_LIFO_accounting "FIFO and LIFO Accounting")
- [The Monty Scripting Language](http://montyscoconut.github.io/about.html "The Monty Scripting Language")
- [Stacks ](https://www.youtube.com/watch?v=9Tp8wHD66lw "Stacks ")

------------
