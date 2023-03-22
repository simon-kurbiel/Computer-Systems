# Chapter 3
---
## Program Encoding
- we know that we can compile a c code by *. 
```
gcc -Og main main.c
```
But we can also optimize it more by doing 
```
gcc -O1 main main.c
gcc -O2 main main.c
```
- If we want to see the assembly code that c code generates
```
gcc -Og -S main.c
```
---
