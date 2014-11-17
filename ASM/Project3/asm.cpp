#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;
int main()
{
	const unsigned LOOP_SIZE = 10000000;
	LARGE_INTEGER li;
	LONGLONG start, end, freq;
	QueryPerformanceFrequency(&li);
	freq = li.QuadPart;
	QueryPerformanceCounter(&li);
	start = li.QuadPart;
	for (int n = 0; n < LOOP_SIZE; n++)
	{
		__asm
		{
			mov eax, 4;
		}
	}
	QueryPerformanceCounter(&li);
	end = li.QuadPart;
	cout << "立即数TIME：" << (int)((end - start) * 1000 / freq) <<  " ms" << endl;



	__asm
	{
		mov ebx, 4;
	}
	QueryPerformanceFrequency(&li);
	freq = li.QuadPart;
	QueryPerformanceCounter(&li);
	start = li.QuadPart;
	for (int n = 0; n < LOOP_SIZE; n++)
	{
		__asm
		{
			mov eax, ebx;
		}
	}
	QueryPerformanceCounter(&li);
	end = li.QuadPart;
	cout << "寄存器TIME：" << (int)((end - start) * 1000 / freq) << " ms" << endl;

	
	QueryPerformanceFrequency(&li);
	freq = li.QuadPart;
	QueryPerformanceCounter(&li);
	start = li.QuadPart;
	for (int n = 0; n < LOOP_SIZE; n++)
	{
		__asm
		{
			mov al, [1064H];
		}
	}
	QueryPerformanceCounter(&li);
	end = li.QuadPart;
	cout << "储存器直接寻址TIME：" << (int)((end - start) * 1000 / freq) << " ms" << endl;
	
	__asm
	{
		mov esi, [4000H];
	}
	QueryPerformanceFrequency(&li);
	freq = li.QuadPart;
	QueryPerformanceCounter(&li);
	start = li.QuadPart;
	for (int n = 0; n < LOOP_SIZE; n++)
	{
		__asm
		{
			mov eax, [esi];
		}
	}
	QueryPerformanceCounter(&li);
	end = li.QuadPart;
	cout << "寄存器间接寻址TIME：" << (int)((end - start) * 1000 / freq) << " ms" << endl;

	__asm
	{
		mov esi, [4000H];
	}
	QueryPerformanceFrequency(&li);
	freq = li.QuadPart;
	QueryPerformanceCounter(&li);
	start = li.QuadPart;
	for (int n = 0; n < LOOP_SIZE; n++)
	{
		__asm
		{
			mov eax, [esi+10H];
		}
	}
	QueryPerformanceCounter(&li);
	end = li.QuadPart;
	cout << "寄存器相对寻址TIME：" << (int)((end - start) * 1000 / freq) << " ms" << endl;


	__asm
	{
		mov eax, 0050H;
		mov ebx, 1000H;
		mov edi, 1100H;
	}
	QueryPerformanceFrequency(&li);
	freq = li.QuadPart;
	QueryPerformanceCounter(&li);
	start = li.QuadPart;
	for (int n = 0; n < LOOP_SIZE; n++)
	{
		__asm
		{
			mov  eax, [ebx + esi + 0600h];
		}
	}
	QueryPerformanceCounter(&li);
	end = li.QuadPart;
	cout << "相对基址变址（带比例因子）寻址TIME：" << (int)((end - start) * 1000 / freq) << " ms" << endl;

	__asm
	{
		mov eax, 0050H;
		mov ebx, 1000H;
		mov edi, 1100H;
	}
	QueryPerformanceFrequency(&li);
	freq = li.QuadPart;
	QueryPerformanceCounter(&li);
	start = li.QuadPart;
	for (int n = 0; n < LOOP_SIZE; n++)
	{
		__asm
		{
			mov [ebx+esi*2],  eax;
		}
	}
	QueryPerformanceCounter(&li);
	end = li.QuadPart;
	cout << "基址变址（带比例因子）寻址TIME：" << (int)((end - start) * 1000 / freq) << " ms" << endl;

	int i;
	cin >> i;
}