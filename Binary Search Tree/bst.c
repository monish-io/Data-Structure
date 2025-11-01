#include<stdio.h>
#include<stdlib.h>
typedef struct bst{
    struct bst *left;
    struct bst *right;
    int roll;
}TREE;
void add_tree(TREE **,int);
void pre_order(TREE *);
void in_order(TREE *);
void post_order(TREE *);
TREE *search(TREE *,int);
int main(){
    char op;
    int n,s;
    TREE *hptr=NULL;
    do{
      printf("Enter a serial num:\n");
      scanf("%d",&n);
	  add_tree(&hptr,n);
      printf("Do you want to add another number?\n");
      scanf(" %c",&op);
    }while(op=='y');
	
    printf("Printing Preorder.....\n");
    pre_order(hptr);
    printf("\nPrinting Inorder.....\n");
    in_order(hptr);
    printf("\nPrinting Postorder.....\n");
    post_order(hptr);

	printf("\nEnter a number to search:\n");
	scanf("%d",&s);
	TREE *adr=search(hptr,s);
	if(adr==NULL) printf("The data does not exist.\n");
	else printf("\n%d is found in %p\n",s,adr);
}
void add_tree(TREE **ptr,int num){
    if(*ptr==NULL){
        *ptr=(TREE*)malloc(sizeof(TREE));
        (*ptr)->left=NULL;
        (*ptr)->right=NULL;
        (*ptr)->roll=num;
    }
    else if((*ptr)->roll > num) add_tree(&(*ptr)->left,num);
    else add_tree(&(*ptr)->right,num);
}
void pre_order(TREE *ptr){
    if(ptr!=NULL){
        printf("%d ",ptr->roll);
        pre_order(ptr->left);
        pre_order(ptr->right);
    }
}
void in_order(TREE *ptr){
    if(ptr){
        in_order(ptr->left);
        printf("%d ",ptr->roll);
        in_order(ptr->right);
    }
}
void post_order(TREE *ptr){
    if(ptr){
        post_order(ptr->left);
        post_order(ptr->right);
        printf("%d ",ptr->roll);
    }
}
TREE *parent;
TREE *search(TREE *ptr,int n){
	if(ptr == NULL) return NULL;
	else if(ptr->roll == n) return ptr;
	else if(ptr->roll > n){
		parent=ptr;
		return search(ptr->left,n);
	}
	else{
		parent=ptr;
		return search(ptr->right,n);
	}
}
