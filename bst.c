#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a,b) (a>b?a:b)


struct node {
  int data;
  struct node *left;
  struct node *right;
};



struct node* getNode(int data){

  struct node* newNode = (struct node*) malloc(sizeof(struct node));
  if( newNode == NULL) return NULL;
  newNode->data = data;
  return newNode;
}

struct node* levelOrder(struct node* root, int ele){
  if( root == NULL) {
    root = getNode(ele);
    return root;
  }

  if( root->data >= ele) root->left = levelOrder(root->left, ele);
  else root->right = levelOrder(root->right, ele);

  return root;
}

struct node *create_bst( struct node *root, int arr[], int n){
  if( n == 0) return root;

  for( int i = 0; i < n; i++){
    root = levelOrder(root, arr[i]);
  }
  return root;
}

void print_bst(struct node* root){
  if( root == NULL) return;
  
  print_bst(root->left);
  printf("%d ", root->data);
  print_bst(root->right);
}

bool searchNode( struct node* root , int ele){

  if( root == NULL ) return false;

  if( root->data == ele ) return true;
  if( root->data >= ele) return searchNode(root->left, ele);
  else return searchNode(root->right, ele);
}

struct node* findMin( struct node* root){

  if( root == NULL) return root;
  if( root->left == NULL  ) return root;
  else  return findMin(root->left);
}
struct node* findMax( struct node* root){
  if( root == NULL ) return root;
  if( root->right == NULL) return root;
  else return findMax(root->right);
}

struct node* deleteNode( struct node* root, int ele){

  if( root== NULL ) return NULL;

  if( root->data > ele )  {root->left = deleteNode(root->left, ele); return root;}
  else if( root->data < ele ) {root->right = deleteNode(root->right, ele); return root;}

  else{
    
    if( root->left == NULL) {
      struct node * temp = root->right;
      free(root);
      return temp;
    }
    else if( root->right == NULL ){
      struct node * temp = root->left;
      free(root);
      return temp;
    }
    else{
      struct node * temp = findMin(root->right);
      printf("....\n%d\n", temp->data);
      root->data = temp->data;
      root->right = deleteNode(root->right, root->data);
      return root;
    }
  }
  
}

int heightBST( struct node* root){

  if( root == NULL) return 0;

  int left = 1 + heightBST(root->left);
  int right = 1 + heightBST(root->right);
  return max(left, right);
}

int heightLevelBST( struct node* root ){

  
}

int main(){
  printf("Hello World\n");
  int n=15;
  
  int arr[n];
  for( int i = 0; i < n; i++){
    arr[i] = i+1;
  }
 
  arr[0] = arr[n/2];
  for( int i = 0; i < n; i++) printf("%d\n", arr[i]);
  struct node *root = NULL;
  
  root = create_bst(root, arr, n);

  print_bst(root);
  // for(int i = 0; i < n; i++)
  //  printf( "\n%d",searchNode(root, arr[i]));

  
 // for(int i = 0; i < n; i++) 
 //   printf( "\n%d",searchNode(root, arr[i]+10));
// printf("\n%d\t%d\n",findMin(root)->data, findMax(root)->data);
// root = deleteNode(root, 80);
//   print_bst(root);
// printf("\n%d\t%d",findMin(root)->data, findMax(root)->data);
printf("\n%d", heightBST(root));
  
return 0;
}