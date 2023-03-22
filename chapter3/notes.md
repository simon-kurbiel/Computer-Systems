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
### If we want to see the assembly code that c code generates
```
gcc -Og -S main.c
```
---
## Data Formats

| C declaration   |      Intel Data Type      |  Assembly-Code Suffix |   Size(bytes) |
|----------|:-------------:|------:|-------:
| Char |  Byte | b |  1|
| Short |   Word   |  w | 2 |
| Int | Double Word |   l |  4 |
| Long |  Quad Word | q |  8 |
| Char * |   Quad Word  |   q | 8 |
| Float | Single Precision |   s |  4 |
| Double | Double Precision |    l |  8|

### Data Movement Instructions

#### The Mov Class
| Instruction|   Effect | Description |
|----------|:-------------:|------:|
| moveb |  S, D    D ← S |move byte |
| movw |    S, D    D ← S  |  move word |
| movl | S, D    D ← S |  move double word |
| movq | S, D    D ← S |  move quad word |

##### For example
| movabsq | $0x0011223344556677, %rax | %rax = 0011223344556677 |
|----------|:-------------:|------:|
| movb | $-1 , %al | %rax = 00112233445566FF |
movw | $-1, %ax | %rax = 001122334455FFFF |
movl | $-1, %eax | %rax = 00000000FFFFFFFF |
movq | $-1, %rax | %rax = FFFFFFFFFFFFFFFF |

