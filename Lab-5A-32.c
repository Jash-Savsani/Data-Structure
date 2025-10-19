/*Read two matrices, first 3x2 and second 2x3, perform multiplication operation 
and store result in third matrix and print it.*/
#include<stdio.h>
void main(){
	int i,j,k,ans=0;
	int a[3][2],b[2][3],c[3][3];
	for(i=0;i<3;i++){
		for(j=0;j<2;j++){
			printf("Enter a[%d][%d]:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			printf("Enter b[%d][%d]:",i,j);
			scanf("%d",&b[i][j]);
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			for(k=0;k<2;k++){
				ans = ans +  (a[i][k] * b[k][j]);
			}
			c[i][j] = ans;
			ans=0;			
		}
	}
	printf("Answer is : \n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d  ",c[i][j]);
		}
		printf("\n");
	}
}
