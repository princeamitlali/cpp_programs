#include<stdio.h>
int main()
{
	char ch;
	printf("enter the character\n");
	scanf("%c",&ch);
	if((ch >='a'&& ch<='z') || (ch>='A'&&ch<='Z'))
	{
		printf("character");
	}
	else
	{
		if(ch>= '0' && ch<='9')
		{
			printf("digit");
		}
		else
		{
			printf("special character");
		}
	}
	return 0;
}
