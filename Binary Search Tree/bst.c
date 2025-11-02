#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
void delete(TREE *,int);
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

	printf("\nEnter a number to delete:\n");
	scanf("%d",&s);
	delete(hptr,s);
	
	printf("Printing Preorder.....\n");
    pre_order(hptr);
    printf("\nPrinting Inorder.....\n");
    in_order(hptr);
    printf("\nPrinting Postorder.....\n");
    post_order(hptr);
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
void delete(TREE *ptr,int r){
    TREE *q=search(ptr,r),*p=parent;
    if(ptr==NULL || q==NULL){ 
		printf("The data to delete does not exist.\n"); 
		return;
    }
    bool null=(q->left==NULL);
    bool nulr=(q->right==NULL);
    if(null && nulr){
		if(p->left==q) p->left=NULL;
		else p->right=NULL;
		free(q);
		q=NULL;
    }
    if((!null)&&(nulr)){
		if(p->left==q) p->left=q->left;
		else p->right=q->left;
		free(q);
		q=NULL;
    } 
    if((null)&&(!nulr)){
		if(p->left==q) p->left=q->right;
		else p->right=q->right;
		free(q);
		q=NULL;
    } 
    if((!null)&&(!nulr)){
		TREE *rm= q->left;
		while(rm->right !=0){
	   		p=rm;
	   		rm=rm->right;
		}
		q->roll=rm->roll;
		q=rm;
		if(p->left==q) p->left=q->right;
		else p->right=q->right;
		free(q);
		q=NULL;
    } 
	printf("\n is deleted.\n",r);
	return;
}
