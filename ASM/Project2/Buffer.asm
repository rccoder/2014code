include irvine32.inc
includelib user32.lib
INCLUDELIB MSVCRT.LIB
_getche PROTO C

.data
buf byte 16 dup(? )
ip dword ?
op dword ?
tep byte ?
w byte ?

.code
main	PROC
mov ip, offset buf
mov op, offset buf
L1 : INVOKE _getche
	 mov ecx, 10
	 mov tep, al
	 cmp al, 1bh
	 jnz L2
	 mov ecx, 1
	 jmp L3
 L2 : cmp tep, '-'
	  jz L4
	  cmp tep, '0'
	  jb L5
	  cmp tep, '9'
	  jg L5
	  JLE L6
  L5 : cmp tep, 'A'
	   jb L3
	   cmp tep, 'Z'
	   jg L3
	  L6:call IQ
	  jmp L3
  L4 : call OQ
   L3 : LOOP L1
		exit
		main ENDP

mod16 PROC; 
	mov eax, ebx
	mov edx, 0
	mov ecx, 16
	div ecx
	mov ebx, edx
	ret
mod16 ENDP

IQ PROC
	mov ebx, ip
	sub ebx, offset buf
	call mod16
	mov ip, offset buf
	add ip, ebx; 
	mov ebx, ip
	mov cl, tep
	mov [ebx], cl
	add ip, 1
	ret
IQ ENDP

OQ PROC
	mov ebx, op
	sub ebx, offset buf
	call mod16
	mov op, offset buf
	add op, ebx
	mov ebx, op
	mov al, [ebx]
	mov w, al
	mov edx, offset w
	call writestring
	add op, 1
	ret
OQ ENDP

END main