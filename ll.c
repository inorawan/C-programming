#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h> 

struct node {
  int data;
  struct node * next;
};

struct node * create_ll( ){

  int arr[18] = {1,2,3,4,5,6,7,8,9,10,11,89,100,101,102,103,104,105};
  int n = 10;
  struct node  head ;
  head.next = NULL;
  struct node * temp = &head;

  for( int i = 0; i < n; i++){

    struct node * new_node = (struct node *)malloc(sizeof(struct node));

    if( new_node == NULL) return NULL;

    new_node->data = arr[i];
    new_node->next = NULL;
    temp->next = new_node;
    temp = new_node;
  }

  return head.next;
}

void print_ll( struct node * head){

  if( head == NULL) printf("ll is empty");

  while( head != NULL){
    printf("%d ", head->data);
    head = head->next;
  }
}

void print_ll_recursive( struct node * head){

  if( head == NULL) return;

  print_ll_recursive(head->next);
  printf("%d ", head->data);
}

bool find_ele(struct node * head, int ele)
{
  if( head == NULL) return false;

  while( head != NULL){

    if( head->data == ele ) return true;
    head= head->next ;
  }

  return false;
}

bool find_ele_recursive(struct node * head, int ele)
{
  if( head == NULL) return false;

  if( head->data == ele ) return true;

  return  find_ele_recursive( head->next, ele);
}

struct node * find( struct node* head ){

  if( head == NULL || head->next == NULL) return NULL;
  struct node * slow = head, * fast = head->next;

  while( fast->next != NULL){
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}

struct node * find_recursive( struct node* head ){

  if( head == NULL || head->next == NULL) return NULL;

  if( head->next->next == NULL) return head;
  return find_recursive(head->next);
}

void insert_at_anyplace(struct node* head, int ele, int x ){


  struct node * temp = head, *prev;
  if( head == NULL) return;
  // if( head->data == ele){
  //   struct node *new_node = (struct node*) malloc ( sizeof( struct node));
  //   new_node->data = x;
  //   new_node->next = head;
  //   head = new_node;
  // }
  while( temp->data != ele && temp != NULL){ 
    // prev = temp;
    temp = temp->next;
  }

  if( temp == NULL) return;

  struct node * new_node = (struct node *) malloc( sizeof( struct node));
  if( new_node == NULL)
     return ;
  new_node->data = x;

  new_node->next = temp->next;
  temp->next = new_node;
  temp->data += new_node->data;
  new_node->data = temp->data - new_node->data;
  temp->data -= new_node->data;
}


void insert_at_anyplace_recursive(struct node* head, int ele, int x ){
  if( head == NULL) return;  
  if( head->data == ele) {
    struct node * new_node = (struct node *) malloc( sizeof( struct node));
    if( new_node == NULL)
       return ;
    new_node->data = x;

    new_node->next = head->next;
    head->next = new_node;
    head->data += new_node->data;
    new_node->data = head->data - new_node->data;
    head->data -= new_node->data;
    return ;
  }

  insert_at_anyplace_recursive(head->next, ele, x);

}

void delete_ele(struct node* head, int ele){

  if( head==NULL ) return ;

  if( head->data == ele){
    if( head->next == NULL){
      head = NULL;
      return;
    }
    struct node * temp = head->next;
    head->data = temp->data;
    head->next = temp->next;

    temp->next = NULL;
    free(temp);
    return;
  }

  while( head->next->data != ele && head->next != NULL){
    head = head->next;
  }

  if( head->next == NULL) return;

  struct node * temp = head->next;
  head->next = head->next->next;
  temp->next = NULL;
  free(temp);
  
}


// void delete_ele_recursive(struct node* head, int ele){

//   if( head == NULL) return;

//   if( head->data == ele){
//     if( head->next == NULL){
//       head = NULL;
//       free(head);
//       return;
//     }
//     struct node * temp = head->next;
//     head->data = temp->data;
//     head->next = temp->next;

//     temp->next = NULL;
//     free(temp);
//     return;
//   }
  
//   delete_ele_recursive(head->next, ele);
// }


struct node* recursiveDeleteNode(struct node* head, int key) {
    // Base case: empty list
    if (head == NULL) {
        return head;
    }

    // If the node to be deleted is the head node
    if (head->data == key) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Recursively delete the node in the rest of the list
    head->next = recursiveDeleteNode(head->next, key);

    return head;
}





int main() {


  struct node* head = create_ll();

  // print_ll(head);
  // printf("\n");
  // print_ll_recursive(head);
  // printf("\n");

  // if( find_ele_recursive(head, 5) ) printf("found");
  // else printf("not found");


  // struct node * ans = find(head);
  // struct node * ans_recursive = find_recursive(head);
  // if( ans == NULL) printf("ll is empty or have one element");
  // else 
  //   printf( "----->>>%d\n", ans->data);
  // if( ans_recursive == NULL) printf("ll is empty or have one element");
  // else 
  //   printf( "%d---->>", ans->data);

  insert_at_anyplace_recursive(head, 1,999);


  print_ll(head);
  printf("\n");
  head = recursiveDeleteNode(head, 1);
  print_ll(head);
  return 0;
  
}