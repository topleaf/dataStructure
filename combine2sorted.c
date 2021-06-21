//
// Created by lijin on 21-6-13.
// algorithm to combine 2 sorted array into one array, the first array has enough spare space to
// hold both array's elements
// trick is : keep 2 pointers to first and second array,
//      first ,get total number of the combined array, use a new_index to point to this position
//      compare and move first and second pointer from end to start,put the greater number in new_index position
//      put the remaining first or second elements into first array to complete the process.
#include <stdio.h>

#define  MAX_NUM 100

void combine(int *first, int first_len,int *second,int second_len);

int main(){
    int a1[MAX_NUM]={3,4,5,8,33, 66, 99, 203,233,234,235,249,930};
    int a2[]={1,4,20,30,99,202,400,600};

    combine(a1,13,a2,8);
    for (int i=0;i<21;i++){
        printf("%d ",a1[i]);
    }
}

void combine(int first[],int first_len,int second[],int second_len)
{
    int new_len,first_index,second_index,new_index;
    new_len = first_len+second_len;

    first_index=first_len-1;
    second_index=second_len-1;
    new_index = new_len-1;
    while (new_index>=0 && first_index>=0 && second_index>=0){
        if (first[first_index]>second[second_index]){
            first[new_index] = first[first_index];
            first_index--;
        }
        else if (first[first_index]<=second[second_index]){
            first[new_index]=second[second_index];
            second_index--;
        }
        new_index --;
    }
    while(first_index>=0 && new_index>=0){
        first[new_index--]=first[first_index--];
    }
    while(second_index>=0 && new_index>=0){
        first[new_index--]=second[second_index--];
    }
}

