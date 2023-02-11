#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void quicksort(int *array, int bot, int top);
void showarray(int *array, int s, int f);


int main(){
    
    int array[] = {5,25,1,4,19,5,44};
    int n = sizeof(array)/sizeof(int); // Gives back the number of elements of the array
    printf("Array before sorting : \n");
    showarray(array,0,n-1);
    quicksort(array,0,n-1);
    printf("Array after sorting : \n");
    showarray(array,0,n-1);


    return 0;
}

void quicksort(int *array,int bot, int top){
    int i,j,k,x,t;
    i = bot;
    j = top;
    k = (bot + top)/2;
    x = array[k];
    do {
        while (array[i]<x)
            i++;
        
        while (array[j]>x)
            j--;
        if (i<=j){
            t = array[i];
            array[i] = array[j];
            array[j] = t;
            i++;
            j--;
        }
    }   while (i<=j);
    if (bot < j){
        quicksort(array,bot,j);
    }
    if (top > i){
        quicksort(array,i,top);
    }
    
}

void showarray(int *array, int s, int f){
    for (int i=s ; i<f ; ++i){
        printf("%d\n",array[i]);
    }
}
