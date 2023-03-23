# Machine Level Representation Of Programs
---
## Program Encoding
### we know that we can compile a c code by *. 
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

---

## Arithmetic and Logical Operations

| Instruction | Effect | Description |
|----------|:-------------:|------:|
| leaq S, D | D ← &S | Load effective address |
| inc D  |D ← D+1  | Increment |
| dec D  | D ← D−1  | Decrement |
| neg D  | D ← -D  | Negate |
| not D  | D ← ~D  | Complement |
| add S, D  | D ← D + S  | Add |
| sub S, D  | D ← D − S  | Subtract |
| imul S, D  | D ← D ∗ S  | Multiply |
| xor S, D  | D ← D ^ S  | Exclusive-or |
| or S, D  | D ← D | S  | Or |
| and S, D  | D ← D & S  | And |
| sal k, D  | D ← D << k  | Left shift |
| shl k, D  | D ← D << k  | Left shift (same as sal) |
| sar k, D  | D ← D >>A k  | Arithmetic right shift |
| shr k, D  | D ← D >>L k  | Logical right shift |

---

## Control
| Flag | Name | Description |
|----------|:-------------:|------:|
|CF | Carry flag | The most recent operation generated a carry out of the most significant bit. Used to detect overflow for unsigned operations. |
| ZF | Zero flag | The most recent operation yielded zero |
| SF | Sign flag | The most recent operation yielded a negative value |
| OF | Overflow flag | The most recent operation caused a two’s-complement overflow—either negative or positive. |

### Only Lea doesn't change the flags. Others which do not flags include mov or any bitwise operations.

### Other instructions such as cmp and test only alter the conditional flags without altering any registers.
|Instruction |Based on |Description|
|----------|:-------------:|------:|
|cmp S1, S2 |S2 − S1 |Compare|
|cmpb|   | Compare byte|
|cmpw|   |  Compare word|
|cmpl|   |  Compare double word|
|cmpq |   | Compare quad word|
|test| S1, S2 S1 & S2 |Test|
|testb|   |  Test byte|
|testw|   |  Test word|
|testl|   |  Test double word|
|testq |   | Test quad word|

---

## While Loop
### The following C Code
```
short test_one(unsigned short x) {
    short val = 1;
    while (x) {
      val ^= x;
      x >>= 1;
    }
    return val & 0;
}
```
### Would Result In This Assembly Translation
```
test_one:
    movl $1, %eax
    jmp .L5
.L6:
    xorq %rdi, %rax
    shrq %rdi Shift right by 1
.L5:
    testq %rdi, %rdi
    jne .L6
    andl $0, %eax
    ret
```
---
## For Loops
```
long fact_for(long n)
{
    long i;
    long result = 1;
    for (i = 2; i <= n; i++)
        result *= i;
    return result;
}
```
### Translates in assembly to
```
fact_for:
    movl $1, %eax 
    movl $2, %edx 
    jmp .L8 
.L9: 
    imulq %rdx, %rax 
    addq $1, %rdx 
.L8:
    cmpq %rdi, %rdx 
    jle .L9 
    rep; ret 
```


## Switch Statements :








