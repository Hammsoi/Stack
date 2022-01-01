#include <stdio.h>
#include <stdlib.h>


typedef struct data{
  int a;
}Data;
typedef struct node{
  Data data;
  struct node* next;
}Node;

typedef struct stk{
  Node* Top;
}Stk;


void addStk(Stk* stack, Data data){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode -> data = data;
  newNode->next = stack->Top;
  stack->Top = newNode;
}

int check(Stk* stack){
  if(stack->Top == NULL){
    return 1;
  }
  else{
    return 0;
  }
}

Data popStk(Stk* stack){
  Data data;
  Node* tmp;
  
  if(check(stack) == 1){
    printf("Stack is Empty.\n");
    exit(-1);
  }

  data = stack->Top->data;
  tmp = stack->Top;
  stack->Top = stack->Top->next;
  free(tmp);
  return data;

}

void printStk(Stk* stack){
  Node* tmp= stack->Top;
  int num = 1;
  if(check(stack) == 0){
    while(1){
      printf("%d번-> %d\n",num,tmp->data.a);
      if(tmp->next !=NULL){
        tmp=tmp->next;
        num++;
      }
      else{
        break;
      }
      
    }
  }
}

void initStk(Stk* stack){
  stack->Top = NULL;
}







int main(void) {

  Stk stack;
  Data data;
  initStk(&stack);

  data.a = 1;
  addStk(&stack, data);
  data.a = 2;
  addStk(&stack, data);
  data.a = 3;
  addStk(&stack, data);
  data.a = 4;
  addStk(&stack, data);

  printStk(&stack);
  printf("---------------------\n\n");
  //4
  popStk(&stack);

  printStk(&stack);
  printf("---------------------\n\n");
  //3,2
  popStk(&stack);
  popStk(&stack);

  printStk(&stack);
}