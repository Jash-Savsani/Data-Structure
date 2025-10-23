/*Longest Substring Without Repeating Characters.*/
#include<stdio.h>
#include<string.h>
void main()
{
	int i,j,n,max1=0,max2=0,temp=0;
	char name[50];
	printf("Enter String:");
	gets(name);
	char *p1,*p2;
	p1 = name;
	p2 = name;
	n=strlen(name);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i<j){
				if(*(name+i) == *(name+j)){
					if((max1+max2)<(j-i)){
						max1=i;
						max2=j;
						temp=1;
					}
				}
			}
		}	
	}
	if(temp==1){
		printf("Largest Substring is : ");
		for(i=max1;i<max2;i++){
			printf("%c",name[i]);
		}
	}
	else{
		printf("Largest Substring is not Found.");
	}
}
