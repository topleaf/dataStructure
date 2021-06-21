/* example code to look for a key in a 2-d matrix,
 * which is sorted both in row and in column
 * the key algorithm here is to start searching either from left-bottom corner
 * or right-top corner , this way, each compare can reduce one row or one column
 * hence reduces the overall search range, until it finds the key or find out the key
 * does not exist in the matrix
 */

#include <stdio.h>
#include <stdbool.h>

#define ROW_NUM 4
#define COL_NUM 5

struct st{
    int row_id;
    int col_id;
    bool exist;
};

//void searchKey(int **data, int row_num,int col_num, int key, struct st *result);

void searchKey(int data[][COL_NUM], int row_num,int col_num, int key, struct st *result);
void searchKeyFromLeftBottom(int data[][COL_NUM], int row_num,int col_num, int key, struct st *result);

int main() {
    int array[ROW_NUM][COL_NUM]={
            {2,5,8, 9, 22},
            {3,6,18,19,44},
            {4,7,31,33,45},
            {7,8,34,45,88}
    };
    int key;
    struct st position;


    printf("\nplease input the number you want to search:");
    scanf("%d", &key);

    while (key!=-1) {
        searchKey(array, ROW_NUM, COL_NUM, key, &position);

        if (position.exist) {
            printf("the number is located in %d row, %d column ", position.row_id, position.col_id);
        } else
            printf("the number does not exist in the array");

        printf("\nUsing second way to search\n");
        searchKeyFromLeftBottom(array, ROW_NUM, COL_NUM, key, &position);
        if (position.exist) {
            printf("the number is located in %d row, %d column ", position.row_id, position.col_id);
        } else
            printf("the number does not exist in the array");

        printf("\nplease input the number you want to search(-1 to exit):");
        scanf("%d",&key);
    }

    return 0;
}

void searchKey(int data[][COL_NUM], int row_num,int col_num, int key, struct st *result){
        unsigned int i=0,j=col_num-1;
        unsigned int element_size = sizeof(int);

        while (i<row_num && j>=0){
            if (data[i][j] == key)
            {
                result->col_id=j;
                result->row_id=i;
                result->exist = true;
                return;
            }
            else if (data[i][j] > key){
                j--;
            }
            else if (data[i][j] < key){
                i++;
            }
        }
        result->exist=false;
        return;
}

void searchKeyFromLeftBottom(int data[][COL_NUM],int row_num,int col_num,int key, struct st *result){
    int i=row_num-1,j=0;
    while (i>=0 && j<col_num){
        if (data[i][j]==key){
            result->exist=true;
            result->row_id = i;
            result->col_id = j;
            return;
        }
        else if (data[i][j]>key)
            i--;
        else if (data[i][j]<key)
            j++;
    }
    result->exist=false;
    return ;
}