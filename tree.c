#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info;
    struct Node *right;
    struct Node *left;
}Node;  

//Functions of organizing a Binary Tree

Node *createnode(void);
void AddInOrder(Node *root, Node *node);
void ShowInOrder(Node *root);
int CountNodes(Node *root);
int MaxValue(Node *root);



// Main 
int main(void){
    Node *root;
    root = NULL;

return 0;
}

// Code of functions
 Node *createnode(void){
    Node *new;
    new = (Node *)malloc(sizeof(Node));

        if (new == NULL){
            printf("No space\n");
            exit(0);
        }
        else{
            printf("Type data :\n");
            scanf("%d",&new->info);
            new->right = NULL;
            new->left = NULL;
        }
        return new;
}

void AddInOrder(Node *root, Node *node){

    if (node->info == root->info){
        printf("Node already exists \n");
    }
    else  if (node->info < root->info){
            if (root->left == NULL){
                root->left = node->info;
            }
            else{
                AddInOrder(root->left,node); /* In case root->left isn't empty, we call again the fucntion
                to put in order the new value */ 
            }
        }
    else 
        if (root->right == NULL){
            root->right = node->info;
        }
        else{
            AddInOrder(root->right,node);/*Same case if the root->right isn't empty.*/
        }
}      


void ShowInOrder(Node *root){
    if (root!=NULL){
        ShowInOrder(root->left);
        printf("%d\n",root->info);
        ShowInOrder(root->right);
    }
}

int CountNodes(Node *root){
    if (root == NULL){
        return 0;
    }
    else{
        int l = CountNodes(root->left);
        int r = CountNodes(root->right);
        return l+r+1; /*Returning l+r+1 because root node isn't going to be counted*/
    }

}

int MaxValue(Node *root){
    if (root == NULL){
        return 0;
    }
    else{
        int res = root->info;
        int rres = MaxValue(root->right);
        int lres = MaxValue(root->left);
        if (lres > res){
            res = lres;
        }
        else if (rres > res){
            res = rres;
        }
    return res;
    }
}
