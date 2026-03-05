#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];
int hashFunction(int key){return key % SIZE;}
void insert(int key){
    int index=hashFunction(key);
    while(hashTable[index]!=-1)
        index=(index+1)%SIZE;
    hashTable[index]=key;
}
void search(int key){
    int index=hashFunction(key);
    while(hashTable[index]!=-1){
        if(hashTable[index]==key){
            printf("Key %d found at index %d\n",key,index);
            return;
        }
        index=(index+1)%SIZE;
    }
    printf("Key not found\n");
}
void deleteKey(int key){
    int index=hashFunction(key);
    while(hashTable[index]!=-1){
        if(hashTable[index]==key){
            hashTable[index]=-1;
            printf("Key %d deleted\n",key);
            return;
        }
        index=(index+1)%SIZE;
    }
    printf("Key not found\n");
}
void display(){
    int i;
    printf("\nHash Table:\n");
    for(i=0;i<SIZE;i++){
        if(hashTable[i]!=-1)
            printf("%d ",hashTable[i]);
        else
            printf("_ ");
    }
    printf("\n");
}
int main(){
    int i;
    for(i=0;i<SIZE;i++)
        hashTable[i]=-1;
    insert(20);
    insert(30);
    insert(25);
    display();
    search(20);
    deleteKey(30);
    display();
    return 0;
}