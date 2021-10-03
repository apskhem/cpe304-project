Due date: 8th Oct. 2021
Presentation date: 13:30, 9th Oct. 2021

Requirements:
* Programs in Assembly Language.
* Behavioral simulator.
* Assembler.

An SMC Computer is a 32-bit computer, using word-addressing, has 8 registers and 65,536 words of memory. There are 4 types of instruction format including R-type, I-type, J-type, and O-type. the zeroth register must always be zero valued.

instruction formats

    (R-type format):    0000000 [opcode-3u] [rs-3u] [rt-3u] 0000000000000 [rd-3u]
    (I-type format):    0000000 [opcode-3u] [rs-3u] [rt-3u] [offset-16s]
    (J-type format):    0000000 [opcode-3u] [rs-3u] [rd-3u] 000000000000000000
    (O-type format):    0000000 [opcode-3u] 0000000000000000000000000000

instructions

    add     (R-type format)     000 -> [rd]     [rs1]   [rs2]
    nand    (R-type format)     001 -> [rd]     [rs1]   [rs2]
    lw      (I-type format)     010 -> [rs]     [rt]    [offset]
    sw      (I-type format)     011 -> [rs]     [rt]    [offset]
    beq     (I-type format)     100 -> [rs1]    [rs2]   [jmp]
    jalr    (J-type format)     101 -> [rs]     [jmp]
    halt    (O-type format)     110 -> *none
    noop    (O-type format)     111 -> *none

sample-1 assembly format

    (address 0):            lw      0   1   five    load reg1 with 5 (uses symbolic address)
    (address 1):            lw      1   2   3       load reg2 with -1 (uses numeric address)
    (address 2):    start   add     1   2   1       decrement reg1
    (address 3):            beq     0   1   2       goto end of program when reg1==0
    (address 4):            beq     0   0   start   go back to the beginning of the loop
    (address 5):            noop
    (address 6):    done    halt                    end of program
    (address 7):    five    .fill   5
    (address 8):    neg1    .fill   -1
    (address 9):    stAddr  .fill   start           will contain the address of start

registers

    $0  value 0.
    $1  n input to the function.
    $2  r input to the function.
    $3  return value of the function.
    $4  local variable for the function.
    $5  stack pointer.
    $6  temporary value (can hold different values at different times, e.g. +1, -1, function address).
    $7  return address.
    
stricter rules:
* (assembler): outputting the machine-code file.
* (assembler): call exit(0) if there is any error in the source code, otherwise call exit(1) for successful execution.
* (simulator): initialize all registers with 0.

# Getting Started with Shell script

## Available Scripts

### `./project.sh build [simulator|assembler] [file path to be lauched]`

Builds the app.

### `./project.sh run [simulator|assembler] [file path to be lauched]`

Builds and runs the app.

---

* [Documentation Link](https://docs.google.com/document/d/1pPPcLB-Py4FEpzhrFXzngHWpZWRNnk5hxilXXESu75A/edit?fbclid=IwAR2yzCX4YDY69kweeUpBiNJloPRTHdTv4xnocrXVYnmKvA-qB-K5TCNBLo0)

* [Role Link](https://www.figma.com/file/8FgUeychlmIqn0tGLKPz4A/ComAxP?node-id=36%3A2996)
