.data
prompt1: .asciiz "enter array size: "
a: .word 400
prompt2:  .asciiz "enter n elements: \n"
space: .asciiz " "

.text
main:
    li      $v0, 4
    la      $a0, prompt1
    syscall

    li      $v0, 5
    syscall
    move    $s0, $v0

    la      $t0, a
    la      $s2, a
    move    $t1, $0

    addi    $t2, $s0, -1
    move    $s1, $t2

    li      $v0, 4
    la      $a0, prompt2
    syscall

input:
    beq     $t1, $s0, done_input

    li      $v0, 5
    syscall
    sw      $v0, 0($t0)

    addi    $t0, $t0, 4
    addi    $t1, $t1, 1

    j       input

done_input:
    li      $t3, 0

    for_loopi:
        bge     $t3, $s1, done_sort
        li      $t4, 0

        for_loopj:
            bge     $t4, $s1, next_iti

            sll		$t5, $t4, 2			# $t5 = $t4 << 2
            add       $t5, $t5, $s2

            move      $t6, $t5
            addi      $t6, $t6, 4

            lw      $t7, 0($t5)
            lw      $t8, 0($t6)

            addi    $t4, $t4, 1

            ble     $t7, $t8, for_loopj
            # swap here
            sw      $t8, 0($t5)
            sw      $t7, 0($t6)

            j       for_loopj
        next_iti:
            addi    $t3, $t3, 1
            j       for_loopi

done_sort:
    li      $t0, 0
    for_loop:
        bge     $t0, $s0, exit
        sll     $t1, $t0, 2
        add    $t1, $t1, $s2
        lw      $t1, 0($t1)
        move    $a0, $t1
        li      $v0, 1
        syscall

        li      $v0, 4
        la      $a0, space
        syscall

        addi    $t0, $t0, 1

        j       for_loop

exit:
    li	$v0, 10		
    syscall	
