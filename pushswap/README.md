*This project has been created as part of the 42 curriculum by <login1>[, <login2>[, <login3>[...]]].*

# Push_swap

## Description
Push_swap is a 42 project aiming to sort a stack of integers using a limited set of operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`) while minimizing the number of operations. The program takes integers as input (either as separate arguments or a single quoted string), outputs the sequence of operations to sort the stack, and can be tested with `checker_linux` to verify correctness.

## Instructions
Compile the project at the root with `make`. Use `make clean` to remove object files, `make fclean` to remove the executable, and `make re` to recompile everything. Run the program as `./push_swap 3 2 1 42` or `./push_swap "3 2 1 42"`. To verify sorting: `./push_swap 3 2 1 42 | ./checker_linux 3 2 1 42` (should return `OK`). For testing with random numbers: `./push_swap $(shuf -i 1-1000 -n 100) | wc -l` for 100 numbers or `./push_swap $(shuf -i 1-5000 -n 500) | wc -l` for 500 numbers.

NUMS=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
./push_swap $NUMS | tee ops.txt | ./checker_linux $NUMS
echo "Number of operations: $(wc -l < ops.txt)"


## Goals
The goal is to sort the stack efficiently. Maximum operations for full score: 100 numbers < 700, 500 numbers < 5500. Minimum validation (≥80%) thresholds vary: 100 < 1100 & 500 < 8500, or 100 < 700 & 500 < 11500, or 100 < 1300 & 500 < 5500. The program uses stack manipulations and a “cheapest move” strategy to optimize rotations and pushes.

## Resources & AI Usage
References: 42 push_swap subject, C standard library docs (`atoi`, `malloc`, `free`), stack data structure (Wikipedia), sorting algorithm guides (GeeksforGeeks). AI assistance was used to explain algorithm strategies, optimize Makefile structure, debug testing procedures, and clarify efficient stack operations. All code implementations are manually written; AI was only a guidance tool.

