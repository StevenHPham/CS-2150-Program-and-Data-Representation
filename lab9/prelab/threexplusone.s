	;; Optimization 1: instead of using idiv to check for remainder, I used test
	;; to check for odd/even numbers since odd have a right-most bit of 1 and even 0. 
	
	global threexplusone

	section .text

	;; register rdi holds (n) input integer
	;; register r10 holds steps counter

threexplusone:
	xor rax , rax 		;zero out the return (steps) register
	xor r10 , r10		;zero out r10


begin:	cmp rdi , 1		;compare rdi (n) to 1 // base case
	jle end			;if n <= 1, jump to end (should return 0)
	
	
	test rdi , 1		;flag set to 0 if even , 1 is odd (if x is even)
	jnz odd			;jump if not zero to odd flag (else.. jump to odd)
	

even: 	shr rdi , 1		;divide n / 2
	inc r10			;increment r10 steps counter
	call begin		;recursion
	ret
	



odd:	lea rdi , [1+3*rdi]	;if x is odd, we land here
	inc r10			;increment r10
	call begin		;recursion
	ret



	
end:	mov rax , r10		;move counter to rax
	ret			;return steps counter
				
	
