/* example code to create a binary search tree
 * traverse it with mid order
 * and destroy it
 * Jin Li, 2021-June-21
 */

#include <stdio.h>
#include <malloc.h>

struct node{
    int content;
    struct node *left,*right;
};

int buildBinaryTree(struct node **);
int traverseTreeMidOrder(struct node *);
int destroyBinaryTree(struct node **pTree);
int searchBinaryTree(struct node *, int key);

int main() {
    int key;
    struct node *pTree=NULL;
    printf("An example code of binary tree building,searching and destroying.\n");
    buildBinaryTree(&pTree);
    traverseTreeMidOrder(pTree);

    printf("\n Input a key to check if it exists in the tree(-1 to exit):\n");
    scanf("%d",&key);
    while (key!=-1){
        if (searchBinaryTree(pTree,key)==1){
            printf("\n%d exists",key);
        }
        else{
            printf("\n%d does not exist in the tree",key);
        }
        printf("\n Input another key to check if it exists in the tree(-1 to exit):\n");
        scanf("%d",&key);
    }
    destroyBinaryTree(&pTree);


    return 0;
}

struct node * newNode(int key){
    struct node *ptr;

    if ((ptr = malloc(sizeof(struct node)))==NULL)
        return NULL;
    ptr->content = key;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}

int insert2Tree(struct node **pRoot, struct node *ptr){
    if (ptr == NULL)
        return -1;
    if (*pRoot==NULL){
        *pRoot = ptr;
        return 0;
    }
    else if ((*pRoot)->content >= ptr->content){
        insert2Tree(&((*pRoot)->left),ptr);
        return 0;
    }
    else{
        insert2Tree(&((*pRoot)->right),ptr);
        return 0;
    }
}

// insert nodes into a binary tree
int buildBinaryTree(struct node **pTree){
    struct node *ptr;
    int key;

    printf("\nplease input integers to build a binary tree, use -1 to end:\n");
    scanf("%d",&key);

    while (key!=-1){
        ptr = newNode(key);
        insert2Tree(pTree,ptr);
        scanf("%d",&key);
    }
    return 0;
}

int traverseTreeMidOrder(struct node *pTree){
    struct node *ptr;

    ptr=pTree;

    if (ptr==NULL)
        return 0;

    if (ptr->left == NULL && ptr->right == NULL){   // leaf node
        printf(" leaf node: %d ", ptr->content);
        return 0;
    }
    else{
        traverseTreeMidOrder(ptr->left);
        printf(" non-leaf node: %d ",ptr->content);
        traverseTreeMidOrder(ptr->right);
        return 0;
    }
}

int destroyBinaryTree(struct node **pTree){
    struct node *ptr;
    ptr=*pTree;
    if (ptr == NULL)
        return 0;
    if (ptr->left == NULL && ptr->right == NULL){ // leaf node, remove it
        printf("\nDelete a leaf node: %d",ptr->content);
        free(ptr);
        return 0;
    }else{
        destroyBinaryTree(&(ptr->left));
        destroyBinaryTree(&(ptr->right));
        printf("\nDelete myself: %d",ptr->content);
        free(ptr);
        return 0;
    }

}

int searchBinaryTree(struct node *pTree, int key){
    struct node *ptr;
    ptr = pTree;

    if (ptr==NULL)
        return 0;
    if (ptr->content==key)
        return 1;
    else if (ptr->content > key){
        searchBinaryTree(ptr->left,key);
    }
    else{
        searchBinaryTree(ptr->right,key);
    }
}