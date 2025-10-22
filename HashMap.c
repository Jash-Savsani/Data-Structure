#include<stdio.h>
#include<string.h>
#define m 10
struct pair{
	char key[10];
	int value;
};
struct pair hashmap[m];
int f(char key[]){
	int i,h=0;
	for(i=0;i<strlen(key);i++){
		h = h+ key[i];
	}
	return h%m;
}

void add(char k[], int v){
	int index=f(k);
	if(hashmap[index].key[0] == '\0'){//space
		strcpy(hashmap[index].key,k);
		hashmap[index].value=v;
		return;		
	}
	else if(strcmp(hashmap[index].key,k)==0){
		hashmap[index].value=v;
		return;
	}
	else{//when colloision occurs
		int probe;
		for(probe=1;probe<m;probe++){
			int i=(index+probe)%m;//linear probing
			if(hashmap[i].key[0]=='\0'){
				strcpy(hashmap[i].key,k);
				hashmap[i].value=v;
				return;
		}
			if(strcmp(hashmap[i].key,k)==0){
				hashmap[i].value=v;
				return;
			}
		}
		printf("HasMap OverFlow.\n");
}
}
int get(char k[]){
	int index = f(k);
	if(hashmap[index].key[0]=='\0'){
		return -1;
	}
	if(strcmp(hashmap[index].key,k)==0){
		return hashmap[index].value;
	}
	else{
		int probe;
		for(probe=1;probe<m;probe++){
			int i = (index+probe)%m;
			if(strcmp(hashmap[i].key,k)==0){
				return hashmap[i].value;
			}
		}
	return -1;
	}
}
void main(){
	add("p1",10);
	add("p2",45);
	add("p3",55);
	add("p2",78);
	add("p1",100);
	printf("p1 is available ? : %d\n",get("p1"));
	printf("p2 is available ? : %d\n",get("p2"));
	printf("p3 is available ? : %d\n",get("p3"));
	printf("p4 is available ? : %d\n",get("p4"));
}
