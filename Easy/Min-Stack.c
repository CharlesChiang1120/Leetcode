#include<stdio.h>
#include<stdlib.h>

// Stack implementation
typedef struct {
    int *data;
    int size;
} Stack;


Stack* CreateStack() {
    Stack *s = malloc(sizeof(Stack));
    s->data = NULL;    
    s->size = 0;
    return s;
}

void DestoryStack(Stack* s) {
    free(s->data);
    free(s);
}

void PushStack(Stack* s, int x) {
    s->data = realloc(s->data, sizeof(int)*(s->size+1));
    s->data[s->size] = x;
    s->size++; 
}

void PopStack(Stack* s) {
    s->size--; 
}

int TopStack(const Stack* s) {
    return s->data[s->size-1];
}

void PrintStack (const Stack* s) {
    for (int i = 0; i < s->size; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main(void) {
    // push, pop, top, isEmpty, ....
    Stack* s = CreateStack();

    PushStack(s, 10);
    PrintStack(s);

    PushStack(s, 20);
    PrintStack(s);

    PushStack(s, 30);
    PrintStack(s);

    PopStack(s);
    PrintStack(s);

    PopStack(s);
    PrintStack(s);

    DestoryStack(s);
    return 0;
}


// ========================================================
// Leercode Min-Stack V1

typedef struct {
    int* data;
    int size;
} MinStack;

MinStack* minStackCreate() {
    MinStack* s = malloc(sizeof(MinStack));
    s->data = NULL;    
    s->size = 0;
    return s;
}

void minStackPush(MinStack* obj, int val) {
    obj->data = realloc(obj->data, sizeof(int)*(obj->size+1));
    obj->data[obj->size] = val;
    obj->size++; 
}

void minStackPop(MinStack* obj) {
    obj->size--; 
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->size-1];
}

int minStackGetMin(MinStack* obj) {
    int min = obj->data[0];
    for (int i = 1; i < obj->size; i++) {
        if (obj->data[i] < min) {
            min = obj->data[i];
        }
    }
    return min;

}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj);
}


// ========================================================
// Leercode Min-Stack V2

typedef struct {
    int* data;
    int* mins;
    int size;
} MinStack;

MinStack* minStackCreate() {
    MinStack* s = malloc(sizeof(MinStack));
    s->data = NULL;   
    s->mins = NULL;
    s->size = 0;
    return s;
}

void minStackPush(MinStack* obj, int val) {
    obj->data = realloc(obj->data, sizeof(int)*(obj->size+1));
    obj->mins = realloc(obj->mins, sizeof(int)*(obj->size+1));
    obj->data[obj->size] = val;
    
    if (obj->size == 0 || obj->mins[obj->size-1] > val) {
        obj->mins[obj->size] = val;
    } else {
        obj->mins[obj->size] = obj->mins[obj->size-1];
    }
    obj->size++; 
}

void minStackPop(MinStack* obj) {
    obj->size--; 
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->size-1];
}

int minStackGetMin(MinStack* obj) {
    return obj->mins[obj->size-1];
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj->mins);
    free(obj);
}


