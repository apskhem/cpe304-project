lw 0 1 n
lw 0 2 r
lw 0 6 plus1
lw 0 7 neg1
sw 5 1 address    //push n
add 5 6 5		  // size +1
sw 5 2 address    //push r
comb beq 0 5 19   //loop
lw 5 2 address    //pull r
sw 5 0 address	  //restore mem
add 5 7 5		  // size -1
lw 5 1 address    //pull n
sw 5 0 address    //restore mem
beq 1 2 yes       //check n==r
beq 0 2 yes       //check r==0
add 1 7 1         // n-1
sw 5 1 address    //pull n-1
add 5 6 5         //size +1
sw 5 2 address    //pull r
add 2 7 2         // r-1
add 5 6 5         //size +1
sw 5 1 address    //pull n-1
add 5 6 5         //size +1
sw 5 2 address    //pull r-1
yes add 3 6 3     //answer += 1
beq 0 0 comb      // back to loop
noop 
done halt
n .fill 4
r .fill 2
neg1 .fill -1
plus1 .fill 1
address .fill 100