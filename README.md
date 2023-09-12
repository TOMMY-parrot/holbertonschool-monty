The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Monty ByteCode files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument

Compilation & Execution

The program will be compiled with the following:

gcc -Wall -Werror -Wextra -pedantic * .c -o monty

To run the program:

./monty bytecode_file

available operations

-push - pushes an element to the stack.

-pall - prints values on the stack starting from the top.

-pint - prints value at the top of the stack.

-pop - removes the top element of the stack.

-swap - swaps the top two elements.

-add - sume the top two elements on the stack, result is stored in the second node and the first node is removed.

-nop - does not do nothing.

completed by yassin guellouz