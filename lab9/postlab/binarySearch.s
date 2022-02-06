	global binarySearch
	section .text

	;; register rdi is a pointer to the array
	;; register rsi is the left int
	;; register rdx is the right int
	;; register rcx is the target int

	;; register r10 is where we are at in the array
	;; if [r10] is equal to rcx , je (jump equal) to found
	;; use [r10] or r10 to get the target int?
	
binarySearch:
	xor rax , rax 		;zero out return counter
	xor r10 , r10		;zero out the array position
	
	

	
loop:   cmp rsi , rdx		;if low > high, go to notfound
	jg notfound
	mov r10 , rsi		;save the old index
	add r10 , rdx		;how to add rsi & rdx to a different register?
	shr r10 , 1		
	
	mov eax , DWORD [rdi + 4*r10] ;get middle array element

	
	cmp ecx , eax		;compare the array element we're at w/ target
	je found 		;jump to found if they equal

	jl less			;if not found, is eax > or < than ecx

	mov rsi , r10
	inc rsi			;end up here if element is greater than target
	call loop
	ret


less:	mov rdx , r10		;jump here if element is less than target
	dec rdx 
	call loop
	ret
	

notfound:
	mov rax , -1 		;return -1 if element is not found
	ret


found:	mov rax , r10		;return the found int
	ret
