/*WAP to replace lowercase characters by uppercase & vice-versa in a user 
specified string. */
#include<stdio.h>
#include<string.h>
void main()
{
	int i;
	char name[50];
	printf("Enter a String:");
	scanf("%s",name);
	for(i=0;i<strlen(name);i++)
	{
		if(name[i]>=90 && name[i]<=122)
		{
			name[i]-=32;
		}
	}
	printf("After UPPERCASE : %s",name);
}
