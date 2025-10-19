/*Read two 2x2 matrices and perform addition of matrices into third matrix and 
print it*/
#include<stdio.h>
void main()
{
	int i,j;
	int a[2][2],b[2][2],c[2][2];
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("Enter a[%d][%d]:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("Enter b[%d][%d]:",i,j);
			scanf("%d",&b[i][j]);
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	printf("Addition of Two Matrices is :\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d  ",c[i][j]);
		}
		printf("\n");
	}
}
