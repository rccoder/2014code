include Irvine32.inc
.data
arrayi sdword 100 DUP(? )
str1 byte "请输入要排序的个数：", 0
str2 byte "请输入：", 0
str3 byte "排序完成结果", 0
num sdword ?
.code
main PROC
; 输入需要输入的数组长度
mov edx, offset str1
call WriteString
call ReadInt
mov ecx, eax
mov num, eax
mov esi, offset arrayi
; 依次输入数组中的数
mov edx, offset str2
L1 : call WriteString
	 call ReadInt
	 mov[esi], eax
	 add esi, 4
	 LOOP l1
	 ; 开始循环冒泡排序
	 mov ecx, num
	 dec ecx
	 ; 压栈外部ecx，进入内部
 L2 : push ecx
	  mov ecx, num
	  dec ecx
	  ; 进行相应的交换
	  mov esi, offset arrayi
  L3 : mov eax, [esi]
	   cmp eax, [esi + 4]
	   jg L4
	   xchg eax, [esi + 4]
	   mov[esi], eax
   L4 : add esi, 4
		LOOP L3
		pop ecx
		LOOP L2
		mov ecx, num
		mov esi, offset arrayi
	L5 : mov edx, offset str3
		 call WriteString
		 call Crlf
		 ;打印排序后的数组
	L6 : mov eax, [esi]
		 call WriteInt
		 call Crlf
		 add esi, 4
		 LOOP L6
		 call Crlf
		 exit
 main ENDP
 END main