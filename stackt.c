#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 5

int push(int data);
int pop(int *pdata);

int stack[STACKSIZE],head;



        int main()
{
        int userData,ch;

        head = -1; /* Initially empty stack */

        do {
        printf("\n--- Menu ---\n1.Push\n2.Pop\n0.Exit\nChoice:");
        scanf("%d",&ch);
        switch (ch) {
            case 1: printf("Give data:");
                        scanf("%d",&userData);
                        if ( push(userData) )
                                printf("Successfully pushed to stack.\n");
                        else
                                printf("Stack full, push failed.\n");
                        break;
            case 2: if ( pop(&userData) )
                                                printf("Popped:%d\n",userData);
                                        else
                                                printf("Empty stack, no data popped.\n");
                                        break;
            case 0: printf("Bye!\n");
                    break;
            default:printf("Try again.\n");
                    break;
        } /* switch */
    } while (ch!=0);

    exit(0);
}

int push(int data) {
        int r = 0;

        if (head < STACKSIZE-1 ) {
                head++;
                stack[head] = data;
                r = 1;
        }

        return r;
}
int pop(int *pdata) {
        int r=0;

        if (head >= 0) {
                *pdata = stack[head];
                head--;
                r = 1;
        }
        return r;
}
