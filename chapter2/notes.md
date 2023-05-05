
# Chapter 2
---
## Different Numbering System
---
1. Decimal. What most of humans use. 1,2,3,4,5,6,7,8,9,10
2. Binary.  What computers use. 0,1
3. Hex      This is base 16. {1,2,3,4,5,6,7,8,9,10,A,B,C,D,E,F}

---
## Boolean Algebra
1. The & and bitwise operator : if 1 & 1, It will be set to 1, Otherwise it will be 0.
2. The |  or bitwise operator : will only be set two 0 when you do 0 | 0
3. The ^ xor bitwise operator : will be set to 1 if they are different, otherwise it will be 0

### practice problem 2.10

```
void inplace_swap(int *x, int *y) {
  *y = *x ^ *y; /* Step 1 */
  *x = *x ^ *y; /* Step 2 */
  *y = *x ^ *y; /* Step 3 */
  
suppose *x = 5, *y = 6
1. *y = 101 ^ 110 = 011
2. *x = 101 ^ 011 = 110
3. *y = 110 ^ 011 = 101
Both x & y get swapped.

}
```

### practice problem 2.12
 
#### x = 0x87654321, with w = 32.
1. The least significant byte of x, with all other bits set to 0. [0x00000021]
```
x & 0xff
```
2.  All but the least significant byte of x complemented, with the least significant
byte left unchanged. [0x789ABC21]
```
x ^ ~0xff
```
3. The least significant byte set to all ones, and all other bytes of x left unchanged. [0x876543FF]
```
x | 0xff
```


---

## Shift Operations in c
| a   |      a << 2     |  Logical >> 3 |   arithmetic a >> 3 |
|----------|:-------------:|------:|-------:
| 0x 1101 0100  | 0x 0101 0000  |  0x 0001 1010| 0x 1111 1010 |
| 0x 0110 0100 |   0x 1001 0000  |  0x 0000 1100 | 0x 1110 1100 |
| 0x 0111 0010 |  0x 1100 1000  |0x 0000 1110    | 0x 0000 1110 |
| 0x 0100 0100|  0x 0001 0000 |0x 0000 1000  | 0x 1110 1000  |

## Integer Representations

### 1. Unsigned Numbers :
1. The Maximum number that you can have is $2^n$-1 where n is the number of bits
2. On the other hand, the least amount of numbers that you can store is 0
#### For example,
char only has 8bits which is 1 byte. in this case, the maximum number is $2^8$ - 1 which is 255

### signed Numbers:
1. In the case of signed numbers the least significant bit has negative weight. 1000(binary) = -1 * $2^3$ = -8

## Floating point
### IEEE Floating-Point Representation
V = $(-1)^s$ x M x $2^E$

#### Case1: Normalized Values
E = e - Bias

### Case2 : Denormalized Values
E = 1 - bias
