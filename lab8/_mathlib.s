global _product
global _power

	section .text


_product:
	;Standard prologue
	push rbp		;create a base pointer
	mov  rbp , rsp		;set new value
	push rsi		;push onto stack

	xor rax , rax		;zero out the return register
	mov rsi , [rbp+8]	;put x in rsi
	mov rcx , [rbp+12]	;put y in rcx

product_loop:
	cmp rcx , 0		;if y <= 0, skip to the end
	jle product_done	;and return 0
	add rax , rsi		;add x to rsi
	dec rcx			;decrement y--

	jmp product_loop	;loop back

product_done:
	;Standard epilogue
	pop rsi			;restore used registers
	pop rbp			;restore base pointer
	ret			;return to caller

power:
	;Standard prologue
	push rbp		;push the old base pointer
	mov  rbp , rsp		;set new value 
	push rsi		;push on stack

	xor rax , rax		;zero out return register

	mov rsi , [rbp+8]	;Put x in base
	mov rcx , [rbp+12]	;Put y in power
	
	cmp rcx , 0		;if y is greater than 0
	jg power_loop		;recursive call
	mov rax, 1		;set base case to 1
	jmp power_done		;jump to power_done
	
power_loop:
	dec  rcx		;decrement y--
	push rcx		;push on stack
	push rsi		;push on stack
	call power		;return to power
	push rax		;save exponent
	push rsi		;save base
	call product		;use product to multiply
	
power_done:
	;Standard epilogue
	pop rsi			;Restore used registers
	mov rsp, rbp;		;put base pointer into caller base
	pop rbp;		;Restore caller base
	ret			;return to caller
