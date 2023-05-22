	.text
	.globl	mod17
	.type	mod17, @function

mod17:
	movq %rdi, %rsi     #idea: Dodaje cyfry na miejscach parzystych oraz na miejscach nieparzystych, potem ponawiam to na wynikach i obliczam roznice.
	movq $0x0F0F0F0F0F0F0F0F, %r10 # Maska do odzielenia cyfr stojacych na miejscach parzystych i nieparzystych.
	andq %r10, %rsi # Odzielanie.
	shlq $4, %r10
	andq %r10, %rdi

	movq %rsi, %r9  #Obliczam sume cyfr stojacych na miejscach nieparzystych.
	shrq $8, %rsi
	addq %rsi, %r9
	
	movq %r9, %rsi
	shrq $16, %rsi
	addq %rsi, %r9

	movq %r9, %rsi
	shrq $32, %rsi
	addq %rsi, %r9

	andq $0x7F, %r9 # Wynik zapisuje w %r9.

	movq %rdi, %r8 # Obliczam sume cyfr stojacych na miejscach parzystych.
	shrq $8, %rdi
	addq %rdi, %r8

	movq %r8, %rdi
	shrq $16, %rdi
	addq %rdi, %r8 	

	movq %r8, %rdi
	shrq $32, %rdi
	addq %rdi, %r8 

	shrq $4, %r8
	andq $0x7F, %r8  # Wynik zapisuje w %r8.
	
	movq %r9, %rsi
	shrq $4, %rsi
	andq $0xF, %r9 # Skracanie wyniku z miejsc nieparzystych.

	cmpq %rsi, %r9 # Zabezpieczenie w przypadku ujemnego wyniku.
	jae .next1
	addq $17, %r9
.next1:	
	subq %rsi, %r9

	movq %r8, %rdi  # Skracanie wyniku z miejsc parzystych.
	shrq $4, %rdi
	andq $0xF, %r8

	cmpq %rdi, %r8 # Zabezpieczenie w przypadku ujemnego wyniku.
	jae .next2
	addq $17, %r8
.next2:
	subq %rdi, %r8

	cmp %r8, %r9 # Zabezpieczenie w przypadku ujemnego wyniku.
	jae .end
	addq $17, %r9
.end:	
	subq %r8, %r9 # Odejmowanie dwoch sum cyfr.
	movq %r9, %rax
	ret

	.size	mod17, .-mod17
