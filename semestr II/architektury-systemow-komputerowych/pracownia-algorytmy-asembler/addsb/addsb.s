        .text
        .globl  addsb
        .type   addsb, @function

addsb:
        xor     %eax,%eax
        ret

        .size   addsb, .-addsb
