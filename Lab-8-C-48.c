/*
48. Write a menu driven program to implement following operations on the 
Doubled Ended Queue using an Array 
• Insert at front end, Insert at rear end 
• Delete from front end, Delete from rear end 
• Display all elements of the queue
*/
#include<stdio.h>
#define n 5
int f=-1,r=-1;
int deq[n];
void r_enqueue(int y){
	if(r>=n-1){
		printf("Queue is Overflow.\n");
		return;
	}
	deq[++r]=y;
	if(f==-1){
		f=0;
	}
	return;
}
int f_dequeue(){
	if(f==-1){
		printf("queue is empty.\n");
		return -1;
	}
	int y=deq[f];
	if(f==r){
		f=-1;
		r=-1;
	}
	else{
		f++;	
	}
	return y;
}
void f_enqueue(int y){
	if(f==0){
		printf("Double Ended Queue is OverFlow.\n");
		return;
	}
	else if(f==-1){
		f=0;
		r=0;
	}else{
		f--;
	}
	deq[f]=y;
	return;
}
int r_dequeue(){
	if(r==-1){
		printf("Double Ended Queue is UnderFlow.\n");
		return -1;
	}
	int y = deq[r];
	if(r==f){
		r=-1;
		f=-1;
	}else{
		r--;
	}
	return y;
}
void display(){
	if(f==-1){
		printf("Queue is Empty.\n");
		return;
	}
	int i;
	printf("Queue Elements : ");
	for(i=f;i<=r;i++){
		printf("%d\t",deq[i]);
	}printf("\n");
}
void main(){
	int i,n2;
	printf("1.R_Enqueue\n2.F_Dequeue\n3.F_Enqueue\n4.R_Dequeue\n5.Display\n\n");
	printf("Enter -1 to Break a Loop.\n");
	while(1){
		printf("Enter Your Choise:");
		scanf("%d",&i);
		if(i==-1)
			break;
		switch(i){
			case 1:printf("\nEnter Number for R_Enqueue:");
					scanf("%d",&n2);
					r_enqueue(n2);
					break;
			case 2: n2 = f_dequeue();
					printf("\nF_Dequeue Number is : %d\n",n2);
					break;
			case 3:printf("\nEnter Number for F_Enqueue:");
					scanf("%d",&n2);
					f_enqueue(n2);
					break;
			case 4: n2 = r_dequeue();
					printf("\nR_Dequeue Number is : %d\n",n2);
					break;
			case 5: display();
		}
	}
}

