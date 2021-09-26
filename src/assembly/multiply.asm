        lw      0   4   round
        lw      0   2   mcand
        lw      0   3   mplier
        lw      0   5   check
        lw      0   6   neg1
loop    beq     0   5   8
        add     1   1   1
        nand    2   5   7
        nand    7   7   7
        beq     0   7   1
        add     1   3   1
        add     2   2   2
        add     4   2   4
        beq     0   0   loop
        noop
done    halt
round   .fill   15
check   .fill   16384
mcand   .fill   32456
mplier  .fill   315
neg1    .fill   -1