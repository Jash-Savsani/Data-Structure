/*WAP to check whether the string is Palindrome or not using Pointer*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main(){
	int i,n;
	char *name = (char*) malloc (sizeof(char));
	printf("Enter String : ");
	scanf("%s",name);
	n=strlen(name);
	for(i=0;i<n;i++){
		if(*(name+i)==*(name+n-1)){
			n--;
		}
		else{
			printf("Given %s is not Palindrome.",name);
			i=-1;
			return;
		}
	}
	if(i!=-1){
		printf("Given %s is Palindrome.",name);
	}
}

