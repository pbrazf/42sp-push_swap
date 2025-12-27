# push_swap

`push_swap` is a sorting algorithm project developed as part of the 42 São Paulo curriculum.  
The objective is to sort a stack of integers using a second auxiliary stack and a restricted set of operations, while minimizing the number of moves.

## 📦 Rules
- Two stacks: **A** and **B**
- Only specific operations are allowed:
  - `sa`, `sb`, `ss`
  - `pa`, `pb`
  - `ra`, `rb`, `rr`
  - `rra`, `rrb`, `rrr`

The program must output the sequence of operations needed to sort stack A in ascending order.

## 🧠 Strategy
- Small inputs are handled with specific optimized logic
- Larger inputs use an index-based approach and **radix sort**
- The algorithm prioritizes correctness and efficiency within project constraints

## 🛠️ Compilation
Compile the program using:

```bash
make
