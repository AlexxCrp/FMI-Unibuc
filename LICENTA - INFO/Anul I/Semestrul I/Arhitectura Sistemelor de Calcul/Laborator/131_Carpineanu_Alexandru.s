.data
	roles: .space 84			#int values[21]
	g: .space 1768				#int g[21][21]
	schimbat: .space 100

	message: .space 100	

	queue:	.space 84
	visited: .space 84
	spString: .asciiz " "
	nlString: .asciiz "\n"

	switchM: .asciiz "switch malitios index "
	str1: .asciiz ":"
	str2: .asciiz "host "
	str3: .asciiz "switch "
	str4: .asciiz "switch malitios "
	str5: .asciiz "controller "
	str6: .asciiz "index "
	str7: .asciiz ";"

	hostIdx: .asciiz "host index "
	da: .asciiz "Yes"
	nu: .asciiz "No"

	z: .asciiz "z"
	a: .asciiz "a"
.text
	
main:
	

	li $v0, 5
	syscall
	move $t0, $v0			#t0==numar de noduri


	li $v0, 5
	syscall
	move $t1, $v0			#t1==numar legaturi

	li $t2, 0
	li $t6, 1

forCitireLegaturi:
	bge $t2, $t1, exForCitireLegaturi
	
	li $v0, 5
	syscall				#lineIndex
	move $t3, $v0


	li $v0, 5
	syscall				#columnIndex
	move $t4, $v0

	
	mul $t5, $t3, $t0
	add $t5, $t5, $t4
	mul $t5, $t5, 4 
	
	sw $t6, g($t5)

	mul $t5, $t4, $t0
	add $t5, $t5, $t3
	mul $t5, $t5, 4

	sw $t6, g($t5)

	add $t2, $t2, 1

	j forCitireLegaturi

exForCitireLegaturi:
	li $t2, 0
	li $t3,  0

forCitireRoles:
	bge $t2, $t0, citireCerinta
	
	li $v0, 5
	syscall
	sw $v0, roles($t3)


	add $t3, $t3, 4
	add $t2, $t2, 1
	
	j forCitireRoles 


citireCerinta:

	li $v0, 5
	syscall
	move $t2, $v0

	
	beq $t2, 1, cerinta1
	beq $t2, 2, cerinta2
	beq $t2, 3, citireDateCerinta3



citireDateCerinta3:

	li $v0, 5
	syscall				#$s0 == host 1
	move $s0, $v0
	
	li $v0, 5
	syscall				#$s1 == host 2
	move $s1, $v0
	
	li $v0, 8
	la $a0, message
	li $a1, 100
	syscall


	j cerinta3

cerinta1:
	li $t2, 0
	li $t3, 0
	forCer1:
		bge $t2, $t0, et_exit
		lw $t4, roles($t3)
		beq $t4, 3, afisareSM
		beq $t4, 1, contForCer1
		beq $t4, 2, contForCer1
		beq $t4, 4, contForCer1
		
		afisareSM:
			la $a0, switchM
			li $v0, 4
			syscall
			
			move $a0, $t2
			li $v0, 1
			syscall
			
			la $a0, str1
			li $v0, 4
			syscall

			la $a0, spString
			li $v0, 4
			syscall

			li $t5 0
		forCer1_2:
			bge $t5, $t0, contAfisareSM

			mul $t6, $t2, $t0
			add $t6, $t6, $t5
			mul $t6, $t6, 4
			lw $t7, g($t6)
			beq $t7, 1 afisariCer1
			beq $t7, 0 contForCer1_2

			afisariCer1:
				mul $t8, $t5, 4
				lw $t7, roles($t8)
				beq $t7, 1, af1
				beq $t7, 2, af2
				beq $t7, 3, af3
				beq $t7, 4, af4
			af1:
				la $a0, str2
				li $v0, 4
				syscall
				j afFin
			af2:
				la $a0, str3
				li $v0, 4
				syscall
				j afFin
			af3:
				la $a0, str4
				li $v0, 4
				syscall
				j afFin
			af4:
				la $a0, str5
				li $v0, 4
				syscall
				j afFin
			afFin:
				la $a0, str6
				li $v0, 4
				syscall
				
				move $a0, $t5
				li $v0, 1
				syscall
				
				la $a0, str7
				li $v0, 4
				syscall

				la $a0, spString
				li $v0, 4
				syscall

				j contForCer1_2

		contForCer1_2:
			addi $t5, 1
			j forCer1_2
	contAfisareSM:
		la $a0, nlString
		li $v0, 4
		syscall
	contForCer1:		
		addi $t2, 1
		add $t3, $t3, 4
		j forCer1	
	

cerinta2:

	li $t1, 0	#queueLen=0
	li $t2, 0	#queueIdx=0
	sw $t1, queue($t2)
	addi $t1, 1
	sw $t1, visited($t2)
	while:
		beq $t1, $t2, verifConexitate
		mul $t9, $t2, 4
		lw $t3, queue($t9)		#$t3==curentNode
		addi $t2, 1
		mul $t7, $t3, 4
		lw $t5, roles($t7)
	if:
		bne $t5, 1, contWhile
		la $a0, hostIdx
		li $v0,  4
		syscall
		move $a0, $t3,
		li $v0, 1
		syscall
		la $a0, str7
		li $v0, 4
		syscall
		la $a0, spString
		li $v0, 4
		syscall

	contWhile:
		li $t4, 0			#t4==columnIndex
		
		while2:
			bge $t4, $t0, while
		if2:
			mul $t5, $t3, $t0
			add $t5, $t5, $t4
			mul $t5, $t5, 4
			lw $t6, g($t5)
			bne $t6, 1, contWhile2
		if3:
			mul $t5, $t4, 4
			lw $t6, visited($t5)
			beq $t6, 1, contWhile2
			mul $t9, $t1, 4
			sw $t4, queue($t9)
			add $t1, $t1, 1
			li $t9, 1
			sw $t9, visited($t5)
			
		contWhile2:
			add $t4, $t4, 1
			j while2
		
		verifConexitate:

			li $t8, 0
			li $t9, 0
			forConex:
				bge $t8, $t0, contVerif
				lw $t7, visited($t9)
				ifver:
					beq  $t7, 0, No
					
				add $t8, $t8, 1
				add $t9, $t9, 4
				j forConex
		contVerif:
			
			Yes:

				la $a0, nlString
				li $v0, 4
				syscall

				la $a0, da
				li $v0, 4
				syscall

				j et_exit

			No:
				la $a0, nlString
				li $v0, 4
				syscall

				la $a0, nu
				li $v0, 4
				syscall

				j et_exit
	

cerinta3:
	

	li $t1, 0	#queueLen=0
	li $t2, 0	#queueIdx=0
	sw $s0, queue($t2)
	addi $t1, 1
	mul $t9, $s0, 4
	sw $t1, visited($t9)
	li $s2, 0
	while_1:
		beq $t1, $t2, Mesaj
		mul $t9, $t2, 4
		lw $t3, queue($t9)		#$t3==curentNode
		addi $t2, 1
	if_1:
		bne $t3, $s1 contWhile_1
		li $s2, 1
		j Mesaj

	contWhile_1:
		li $t4, 0			#t4==columnIndex
		
		while2_1:
			bge $t4, $t0, while_1
		if2_1:
			mul $t5, $t3, $t0
			add $t5, $t5, $t4
			mul $t5, $t5, 4
			lw $t6, g($t5)
			bne $t6, 1, contWhile2_1
		ifInterm:
			mul $t9, $t4, 4
			lw $s3, roles($t9)
			beq $s3, 3, contWhile2_1
		if3_1:
			mul $t5, $t4, 4
			lw $t6, visited($t5)
			beq $t6, 1, contWhile2_1
			mul $t9, $t1, 4
			sw $t4, queue($t9)
			add $t1, $t1, 1
			li $t9, 1
			sw $t9, visited($t5)
			
		contWhile2_1:
			add $t4, $t4, 1
			j while2_1


	Mesaj:
		beq $s2, 1, necriptat
		beq $s2, 0, criptat

	necriptat:
		
		la $a0, message
		li $v0, 4
		syscall
		j et_exit

	criptat:
		li $t9, 1
		li $t0, 0		#i	
		li $t2, 0		#j
		lb $t3, a
		lb $t4, z
		forCriptare:
			lb $t1, message($t0)		#t1==element curent
				
			beq $t1, $0, afcriptat	
			li $t2, 0
			for2Criptare:
				bge $t2, 10, contForCriptare	#for(j=0;j<10;j++)

				ifA:		
					beq $t1, $t3, ainz
				ifZ:
					beq $t1, $t4, zina 				

				scadere:
					sub $t1, $t1, 1	
					addi $t2, 1			
					j for2Criptare

				ainz:
					mul $t5, $t1, 4
					lw $t6, schimbat($t5)
					beq $t6, 1, scadere
					move $t1, $t4
					addi $t2, 1
					mul $t5, $t1, 4
					sw $t9, schimbat($t5)
					j for2Criptare
				zina:
					mul $t5, $t1, 4
					lw $t6, schimbat($t5)
					beq $t6, 1, scadere
					move $t1, $t3
					addi $t2, 1
					mul $t5, $t1, 4
					sw $t9, schimbat($t5)
					j for2Criptare

		contForCriptare:
			sb $t1, message($t0)	

			addi $t0, 1
	
			j forCriptare

	afcriptat:
		la $a0, message
		li $v0, 4
		syscall

		j et_exit 


et_exit:
	
	li $v0, 10
	syscall
