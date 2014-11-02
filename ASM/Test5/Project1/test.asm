title large
include Irvine32.inc
.data
op1 dword 0AB2A406h, 0AB2A406h, 0AB2A406h, 0AB2A406h, 0AB2A406h, 0AB2A406h, 0AB2A406h, 0AB2A406h
op2 dword 780108B7h, 780108B7h, 780108B7h, 780108B7h, 780108B7h, 780108B7h, 780108B7h, 780108B7h
str1 byte "相加后的结果", 0
str2 byte "相减后的结果", 0
sum dword 9 DUP(0)
.code
main PROC
mov ecx, 8
mov esi, (offset op1) + 14
mov edi, (offset op2) + 14
mov ebx, (offset sum) + 16
call Add_Num
pushad
mov edx, offset str1
call WriteString
call crlf
call Display_Add
popad
call Dec_Num
call crlf
pushad
mov edx, offset str1
call WriteString
call crlf
call Display_Add
call crlf
popad
exit
main ENDP

Add_Num PROC
pushad
clc
l1 : mov eax, [esi]
	 adc eax, [edi]
	 pushfd
	 mov[ebx], eax
	 add esi, 2
	 add edi, 2
	 add ebx, 2
	 popfd
	 loop L1
	 popad
	 ret
	 Add_Num ENDP
Display_Add PROC
	pushad
	mov eax, sum+16
	call WriteHex
	mov eax, sum + 14
	call WriteHex
	mov eax, sum+12
	call WriteHex
	mov eax, sum + 10
	call WriteHex
	mov eax, sum + 8
	call WriteHex
	mov eax, sum + 6
	call WriteHex
	mov eax, sum + 4
	call WriteHex
	mov eax, sum + 2
	call WriteHex
	mov eax, sum
	call WriteHex
	popad
	ret
Display_Add ENDP
	 Dec_Num PROC
	 pushad
	 clc
 L2 : mov eax, [esi]
	  sbb eax, [edi]
	  pushfd
	  mov[ebx], ebx
	  add esi, 2
	  add edi, 2
	  add ebx, 2
	  popfd
	  LOOP L2
	  popad
	  ret
	  Dec_Num ENDP
	  END main
