; linearSearch.s

;; purpose: This file contains imnplementation of the function
;; linear search

	global linearSearch

	section .text


	;; Parameter 1 (rdi) is a pointer to the array
	;; Parameter 2 (rsi) is a size / index of the array
	;; Parameter 3 (rdx) is the target int
linearSearch:
	
	xor rax , rax 			;zero out the return register
	xor r10 , r10			;zero out the counter i

begin:	cmp r10 , rsi			;if array size is exceed
	jg notequal			;jump to notequal 
	mov eax , DWORD [rdi + 4*r10]   ;get array element

	cmp eax , edx			;compare array element and target int,  
	je equal			;jump if equal

	inc r10				;else increment r10 
	jmp begin			;loop back


	

equal:
	mov rax , r10
	ret 

notequal:
	mov rax , -1			;return -1 if past the size of the index
	ret
