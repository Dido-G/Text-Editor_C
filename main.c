#include <stdio.h>

typedef struct Operation{
    char type; // i= "insert", d = "delete"
    int pos;
    int length;
    char data[100]; //the text
    struct Operation* next; //for stack - linked list
}Operation;

void insert(char* buffer, int pos, char* text){
    
}

void delete(char* buffer, int pos, int length){
    
}

void print(char* buffer){
    
}


void push(Operation** stack, Operation operation){
    
}

int isEmpty(Operation** stack){
    
}



int main(){

}
