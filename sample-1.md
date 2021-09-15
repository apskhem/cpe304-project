lw [register value] [register to be stored] [offset]

instruction formats

    (R-type format):    0000000 [opcode] [rs] [rt] 0000000000000 [rd]
    (I-type format):    0000000 [opcode] [rs] [rt] [offset]
    (J-type format):    0000000 [opcode] [rs] [rd] 000000000000000000
    (O-type format):    0000000 [opcode] 0000000000000000000000000000

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

sample-1 binary format

    (address 0):
    (address 1):
    (address 2):
    (address 3):
    (address 4):
    (address 5):
    (address 6):
    (address 7):
    (address 8):
    (address 9):