include Irvine32.inc
.data
arrayi sdword 100 DUP(? )
str1 byte "������Ҫ����ĸ�����", 0
str2 byte "�����룺", 0
str3 byte "������ɽ��", 0
num sdword ?
.code
main PROC
; ������Ҫ��������鳤��
mov edx, offset str1
call WriteString
call ReadInt
mov ecx, eax
mov num, eax
mov esi, offset arrayi
; �������������е���
mov edx, offset str2
L1 : call WriteString
	 call ReadInt
	 mov[esi], eax
	 add esi, 4
	 LOOP l1
	 ; ��ʼѭ��ð������
	 mov ecx, num
	 dec ecx
	 ; ѹջ�ⲿecx�������ڲ�
 L2 : push ecx
	  mov ecx, num
	  dec ecx
	  ; ������Ӧ�Ľ���
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
		 ;��ӡ����������
	L6 : mov eax, [esi]
		 call WriteInt
		 call Crlf
		 add esi, 4
		 LOOP L6
		 call Crlf
		 exit
 main ENDP
 END main