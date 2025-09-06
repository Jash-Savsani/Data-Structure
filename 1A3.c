#include<stdio.h>
void main()
{
	char c;
	char temp;
	printf("Enter Character: ");
	scanf("%c",&c);
	temp=c;
	int n=0;
	if(c>='A' && c<='Z'){
		c+=32;
		n=1;
	}
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
		if(n==1){
			printf("%c is Vowel",temp);
		}
		else{
			printf("%c is Vowel",c);	
		}
		
	}
	else
	{
		if(n==1){
			printf("%c is Constant",temp);
		}
		else
		{
			printf("%c is Constant",c);	
		}
			
	}
}
