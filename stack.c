#include <stdio.h>
#include <stdlib.h>
#define size 10


int push(int data);
int pop(int *pdata);

int stack[size],head; //Global Values



int main(void){
    int data;
    head = -1;

    printf("Type data to push to the stack :\n");
    scanf("%d",&data);
    if (push(data)){
        printf("Pushed\n");
    }
    else{
        printf("Stack full");
    }

    if (pop(&data)){
        printf("Popped %d: \n",data);   
    }
    else{
        printf("Stack empty\n");
    }

    return 0;
}


int push(int data){
    int r = 0;
        if (head < size -1){
            head++;
            stack[head]=data;
            r++;
        }
    return r; //If r equals 0, there is no space in the stack. Otherwise, there is space and the data was pushed successfully.
}

int pop(int *pdata){
    int r =0;
        if (head >= 0){
            *pdata = stack[head];
            head--;
            r++;
        }
    return r;
}