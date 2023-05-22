	.text
	.globl	bitrev
	.type	bitrev, @function

bitrev:             # Idea: Zamieniam miejscami pierwsze 32 bitow z drugimi, potem w kazdym z tych blokow zamieniam po 16 bitow miejscami itd. na koncu zamieniam kazda pare bitow (bit pierwszy z bitem drugim, bit trzeci z bitem czwartym itd.). Na koncu uzyskuje odwrocone bitami slowo.

	movq %rdi, %r9 # kopiowanie wyniku do %r9
	shrq $32, %rdi # przesuniecie pierwszego bloku 32 bitow w miesjce drugiego
	shlq $32, %r9 # przesuniecie drugiego bloku 32 bitow w miejsce pierwszego
	orq %r9, %rdi # "dodanie" dwoch blokow bitow

	movq $0xFFFF0000FFFF0000, %r8 # ustawienie odpowiedniej maski w rejestrze %r8
	movq %rdi, %r9 # kopiowanie wyniku do %r9
	andq %r8, %r9 # wziecie odpowiednich bitow poprzez and z maska
	shrq $16, %r9 # przesuniecie blokow bitow w prawo
	shlq $16, %rdi # przesuniecie blokow bitow w lewo
	andq %r8, %rdi # pozbycie sie bitow ktore moga "nachodzic" na wynik
	orq %r9, %rdi # "dodanie" blokow po zmianach pozycji

	movq $0xFF00FF00FF00FF00, %r8 # tak samo jak wyzej, tylko biore bloki 8 bitow
	movq %rdi, %r9
	andq %r8, %r9
	shrq $8, %r9
	shlq $8, %rdi
	andq %r8, %rdi
	orq %r9, %rdi

	movq $0xF0F0F0F0F0F0F0F0, %r8 # bloki 4 bitow
	movq %rdi, %r9
	andq %r8, %r9
	shrq $4, %r9
	shlq $4, %rdi
	andq %r8, %rdi
	orq %r9, %rdi

	movq $0xCCCCCCCCCCCCCCCC, %r8 # bloki 2 bitow
	movq %rdi, %r9
	andq %r8, %r9
	shrq $2, %r9
	shlq $2, %rdi
	andq %r8, %rdi
	orq %r9, %rdi

	movq $0xAAAAAAAAAAAAAAAA, %r8 # pojedyncze bity
	movq %rdi, %r9
	andq %r8, %r9
	shrq $1, %r9
	shlq $1, %rdi
	andq %r8, %rdi
	orq %r9, %rdi

	movq %rdi, %rax	# przenosze wynik do %rax

	ret

	.size	bitrev, .-bitrev
