#include<stdio.h>
#define m 10
int hashset[m];

void init(){
	int i;
	for(i=0;i<m;i++){
		hashset[i]=-1;
	}
}

int f(int key){
	return key%m;
}

void add(int key){
	int index = f(key);
	if(hashset[index] == -1){
		hashset[index]=key;
		return;
	}
	else if(hashset[index] == key){
		printf("Key Already Exists.\n");
	}
	else{
		int probe;
		for(probe=1;probe<m-1;probe++){
			int i = (index+probe)%m;
			if(hashset[i] == -1){
				hashset[i]=key;
				return;
			}
			if(hashset[i]==key){
				printf("Key already Exists.\n");
				return;
			}
		}
		printf("Hashset Overflow.");
	}//else
}//add

void display(){
	int i;
	for(i=0;i<m;i++){
		printf("%d ",hashset[i]);
	}
}

void main(){
	init();
	add(10);
	add(10);
	add(20);
	add(45);
	add(33);
	display();		
}
