/* Allow a user to enter N words and store it in an array.  
• Generate a random number between 0 to N-1.  
• Based on the random number generated display the word stored at that 
index of an array and allow user to enter its anagram.  
• Check whether the word entered by the user is an anagram of displayed 
number or not and display an appropriate message.  
• Given a word A and word B. B is said to be an anagram of A if and only if 
the characters present in B is same as characters present in A, 
irrespective of their sequence. For ex: “LISTEN” == “SILENT” */
#include<stdio.h>/*Bakki che.*/
#include<stdlib.h>
#include<string.h>
void main(){
	int  rn,n,i,j,num=0;
	char str[50];
	char temp;
	printf("How Many name You Want to Store:");
	scanf("%d",&n);
	char name[n][50] ;
	for(i=0;i<n;i++){
		printf("Enter name[%d]:",i);
		scanf("%s",name[i]);	
	}
	rn = rand() % n;
	printf("%d\nLets Play Game...\n",rn);
	printf("RANDOM  STRING IS: %s",name[rn]);
	printf("\nEnter Your String:");
	scanf("%s",str);
	//printf("str==>%d\nname[rn]==>%d",strlen(str),strlen(name[rn])); check
	if(strlen(str)==strlen(name[rn])){
		n=strlen(str);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if((str[j]==name[rn][i]) && (str[j] != ' ' && name[rn][i] != ' ')){
						str[j]=' ';
						name[rn][i]=' ';
						num++;
						break;
				}	
			}	
		}
		if(num==n){
			printf("Given String is Anagram.");;	
		}
		else{
			printf("Given String is not Anagram.");
		}	
	}
	else{
		printf("Given String is not Anagram.");
	}
}
//	if(strlen(str)==strlen(name[rn]))
//	{
//	    n=strlen(str);
//	    printf("\nn=%d\n",n);
//		for(i=0;i<n;i++)
//		{
//			for(j=0;j<n-i;j++)
//			{
//				if(str[i]==name[rn][j])//if caharcter same
//				{
//				    printf("\nCondition==>j=%d;%d<%d;%d  AND i=%d\n",j,j,(n-i),j,i);
//					temp = name[rn][j];
//					name[rn][j] = name[rn][n-1];
//					name[rn][n-1] = temp;
//					printf("\nname[rn][n-1]=%c\n",temp);
//					temp = str[i];
//					str[i] = str[n-1];
//					str[n-1] = temp;
//					printf("\nstr[n-1]=%c\n",temp);
//					num++;
//					n--;
//				}
//			}
//		}
//		printf("\n\nname=%s\nstr=%s\n\nnum_mength=%d\nstrlen(str)=%d",name[rn],str,num,strlen(str));
//		if(num==(strlen(str)))
//		{
//			printf("\n\nGiven Word is Anagram.");
//		}
//		else
//		{
//			printf("\n\nGiven Word is not Anagram.");
//		}
//	}
//	else
//	{
//		printf("Given Number is not Anagram.");	
//	}   

