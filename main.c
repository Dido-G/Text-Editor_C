#include <stdio.h>
#include <string.h>
typedef struct Operation{
    char type; // i= "insert", d = "delete"
    int pos;
    int length;
    char data[100]; //the text
    struct Operation* next; //for stack - linked list
}Operation;

void insert(char* buffer, int pos, char* text, Operation** undoStack){
    int len = strlen(buffer);
    int text_len = strlen(text);

    //shift text to right
    memmove(buffer + pos + text_len, buffer + pos, len - pos + 1);
    //copy the text
    memcpy(buffer + pos, text, text_len);


    //record reverse operation(d)
    Operation * op = malloc((sizeof(Operation)));
    op->type = "d";
    op->pos = pos;
    op->length = text_len;
    strcpy(op->data, text);
    push(undoStack, op);
}

void delete(char* buffer, int pos, int length){
    int len = strlen(buffer);
    memmove(buffer + pos, buffer + pos + length, len - pos - length + 1);
}

void print(char* buffer){
    
}


Operation* pop(Operation** stack, Operation* operation){
    if(*stack == NULL){
        return NULL;
    }
    Operation* top = *stack;
    *stack = top->next;
    return top;
}

void pop(Operation** stack, Operation* op){
    op->next = *stack;
    *stack = op;
}

int isEmpty(Operation** stack){
    
}



int main() {

    Operation* undoStack = NULL;
    Operation* redoStack = NULL;

    char buffer[1000] = "";
    char command[20];
    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "insert") == 0) {
            int pos;
            char text[100];
            scanf("%d %s", &pos, text);
            insert(buffer, pos, text, undoStack);

        } else if (strcmp(command, "delete") == 0) {
            int pos, length;
            scanf("%d %d", &pos, &length);
            delete(buffer, pos, length);

        } else if (strcmp(command, "print") == 0) {
            printf("%s\n", buffer);

        } else if (strcmp(command, "exit") == 0) {
            break;

        } else {
            printf("Unknown command.\n");
        }
    }

    return 0;
}

