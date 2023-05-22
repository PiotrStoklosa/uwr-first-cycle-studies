	.text
	.globl	clz
	.type	clz, @function

clz:                          # Idea: najpierw sprowadzam liczbe do postaci, ktora zapisana binarnie sklada sie z jednego ciagu zer oraz z jednego ciagu jedynek tak, aby liczba wiadacych zer byla taka sama, jak w podanym argumencie funkcji. Nastepnie zliczam liczbe jedynek w zapisie binarnym wykorzystujac poznanego na zajeciach popcounta. Znajac liczbe jedynek, liczbe zer mozemy latwo obliczyc ze wzoru 64 - L, gdzie L jest liczba jedynek.

	movq %rdi, %rsi # "Dodaje" jedna jedynke po pierwszej napotkanej jedynce. (poprzez or)
	shrq %rdi
	orq %rdi, %rsi
	
	movq %rsi, %rdi # "Dodaje" 2 jedynki po dwoch napotkanych jedynkach. (poprzez or)
	shrq $2, %rdi
	orq %rdi, %rsi
	
	movq %rsi, %rdi # "Dodaje" 4 jedynki po czterech napotkanych jedynkach. (poprzez or)
	shrq $4, %rdi
	orq %rdi, %rsi
	
	movq %rsi, %rdi # "Dodaje" 8 jedynek po osmiu napotkanych jedynkach. (poprzez or)
	shrq $8, %rdi
	orq %rdi, %rsi

	movq %rsi, %rdi # "Dodaje" 16 jedynek po szesnastu napotkanych jedynkach. (poprzez or)
	shrq $16, %rdi
	orq %rdi, %rsi
	
	movq %rsi, %rdi # "Dodaje" 32 jedynki po trzydziestu dwoch napotkanych jedynkach. (poprzez or)
	shrq $32, %rdi
	orq %rdi, %rsi 
					# W tym miejscu liczba (w rejestrze %rsi) sklada sie z nieprzerwanego ciagu zer i nieprzerwanego ciagu jedynek.

	movq $0x5555555555555555, %r8 # Maski potrzebne do popcounta.
	movq $0x3333333333333333, %r9
	movq $0x0f0f0f0f0f0f0f0f, %r10
	
	movq %rsi, %rdi # popcount
	shrq %rdi
	andq %r8, %rdi
	subq %rdi, %rsi
	
	movq %rsi, %rdi
	andq %r9, %rdi
	shrq $2, %rsi
	andq %r9, %rsi
	addq %rdi, %rsi
	
	mov %rsi, %rdi
	shrq $4, %rdi
	addq %rdi, %rsi
	andq %r10, %rsi

	mov %rsi, %rdi
	shrq $8, %rdi
	addq %rdi, %rsi

	mov %rsi, %rdi
	shrq $16, %rdi
	addq %rdi, %rsi

	mov %rsi, %rdi
	shrq $32, %rdi
	addq %rdi, %rsi
	
	andq $0x7f, %rsi # Po tej operacji w rejestrze %rsi znajduje sie suma jedynek.

	movq $64, %rax # W wyniku zajduje sie liczba 64
	subq %rsi, %rax # Odejmuje od wyniku liczbe jedynek.

	ret   # "Dodanie" potrzebnych jedynek do liczby dziala w czasie log(n), popcount rowniez dziala w czasie log(n), wiec moje rozwiazanie dziala w O(log(n)).


	.size	clz, .-clz
