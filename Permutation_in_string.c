/*Permutation in String*/
#include<stdio.h>
#include<string.h>
void main()
{
	int i,j,n2,n1,n3,k=0;
	char str1[50],str2[50];
	printf("Enter Big String:");
	gets(str1);
	printf("Enter Small String:");
	gets(str2);
	n2=strlen(str2);
	n1=strlen(str1);
	char *ptr[n2];
	for(i=0;i<n2;i++){
		ptr[i]=&str1[i];
	}
	for(i=0;i<(n1-n2+1);i++){
		n3=0;
		for(j=0;j<n2;j++){
			if(*ptr[j]==str2[j]){
				n3++;
			}
		}
		if(n3==n2){
			printf("Yes, Here Permutation Available.");
			k=1;
			break;
		}
		for(j=0;j<n2;j++){
			ptr[j]++;
		}
	}
	if(k==0){
		printf("No, Here Permutation is Not Available.");
	}
}
