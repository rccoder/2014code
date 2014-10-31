#include<stdio.h>
#include<string.h>

int main()
{
	char str[1000];
	scanf("%s",str);
	bool shishuzi=true;
	for(int i=0;i<strlen(str);i++)
		if(str[i]<'0' || str[i]>'9')
		{
			printf("不是数字！\n");
			shishuzi=false;
			break;
		}
	if(shishuzi==true)
		printf("是数字！\n");
return 0;
}