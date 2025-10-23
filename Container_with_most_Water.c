/*Container with most water*/
#include<stdio.h>
void main()
{
	int i,j,n,h,w,i1,j1,area,max=0;
	printf("Enter Size of Non-Negative Array:");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		printf("Enter a[%d]:",i);
		scanf("%d",&a[i]);
	}
	int *ptr1 = a;
	int *ptr2 = a;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(*(ptr1+i) < *(ptr2+j)){
				h = *(ptr1+	i);
			}
			else{
				h = *(ptr2+j); 
			}
			w = j-i;
			area = h*w;
			if(max<area){
				max=area;
				i1=i;
				j1=j;
			}
		}
	}
	printf("Container Index (%d,%d) with most Water is : %d",i1,j1,max);
}
