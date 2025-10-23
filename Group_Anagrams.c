/*Make Group of Anagrams*/
#include<stdio.h>
#include<string.h>
void main()
{
	printf("\n-----Let's Play Anagram Game-----\n");
	int i,k,j,n;
	printf("Enter Total Number Strings to Add in String Array:");
	scanf("%d",&n);
	char name[n][50];
	char temp;
	for(i=0;i<n;i++){
		printf("Enter name[%d]:",i);
		scanf("%s",name[i]);
	}
	for(k=0;k<n;k++){
		for(i=0;i<strlen(name[k]);i++){
			for(j=1;j<strlen(name[k]);j++){
				if(name[k][j-1]>name[k][j]){
					temp=name[k][j-1];
					name[k][j-1]=name[k][j];
					name[k][j]=temp;
				}
			}
		}
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(name[i],name[j])==0){
				printf("\nAnagram in %d and %d Index.",i,j);
			}
		}
	}
}
