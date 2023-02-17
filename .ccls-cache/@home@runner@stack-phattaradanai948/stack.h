
#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
	NodePtr top;
	int size;
}Stack;

typedef Stack * StackPtr;
void push(StackPtr s, char value);
char pop(StackPtr s);
void pop_all(StackPtr s);

void push(StackPtr s, char value) {
  NodePtr new_node = (NodePtr)malloc(sizeof(Node));
  if(new_node){
  new_node->nextPtr = s->top;
  new_node->data=value;
  s->top = new_node;
  s->size++;
  }
}

  char pop(StackPtr s) {
  NodePtr t = s->top;
  if(s->size>0) {
  char value = t->data; //(*top)->data
  s->top = t->nextPtr;//(*top)->nextPtr
  s->size--;
  free(t);
  return value;
  }
 // printf("Empty Stack"); 
  return 0;
  
}

void pop_all(StackPtr s){
  while(s->size>0) { //s->top
   pop(s);
  }
}

#endif
