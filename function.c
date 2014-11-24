#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mhDefs.h"
#include "stuDefs.h"




void mh_init(HeapType *heap){	
  //initialize an empty list
  heap ->numBlocks = 0;
  heap->head = NULL;
  };


void mh_cleanup(HeapType *heap){
  //free the memory of linked list(head of list)
  free(heap->head);
};

void *mh_alloc(HeapType *heap, int n, char *label){
BlockNode *current;//track current node in linked list
BlockNode *block;//this will be a new node in list
 
current = heap->head;//initialize current to head of list
block =(BlockNode *) malloc(sizeof(BlockNode));// allocate memory for new block
//check if head is null or not
if(current == NULL){ 
  heap->head = block;//set the new block to head
  current = block;
 }else{
//trace to the last node in linked list
  while(current->next != NULL){
   current = current->next;
   }
   current->next = block;
  }
  block->data = (BlockType *)malloc(sizeof(BlockType));
  block->data->addr = &block->data;
  block->data->size = n;
  block->data->rsv = C_TRUE;
  block->next = NULL;
  strcpy(block->data->tag , label);
  //increase the number of blocks
  heap->numBlocks += 1;	
  return block->data->addr;
 
};


void mh_dealloc(HeapType *heap, void *addr){
 BlockNode *current;
 BlockNode *prev;
 
 current = heap->head;
 prev = NULL;
 while(current != NULL){
  if(current->data->addr == addr){
   break;
   }else{
  prev = current;
  current = current->next;}
  }
  
  if(current == NULL){
   printf("Not found the element");
  }
  else{
   if(prev!=NULL){
   prev->next = current->next;
   }else{
   heap->head = current->next; 
   }
   current->data->rsv = C_FALSE;
   free(current->data);
   free(current);
   
  }
   
  
};


void mh_dump(HeapType *heap){
  BlockNode *current;
  current = heap->head;
  while(current != NULL){
    printf("%30s: %10d bytes stored at position %p\n ",current->data->tag,current->data->size,current->data->addr);
   current = current->next;
   }
  printf("\n");
};

int mh_count(HeapType *heap){
 int count;
 count = 0;
 BlockNode *current;
 //Using while loop to examine every block of List
 current = heap->head;
 while(current != NULL){
    if(current->data->rsv == C_TRUE){
       count += current->data->size;
   };
   current = current->next;
 };
  return count;
};

void mh_collect(HeapType *heap){
  //int i; //used in for loop
  BlockNode *next;
  BlockNode *current;
  BlockNode *prev;
  BlockNode *traceNode;
  //set the current pointer to head 
  current = heap->head;
  //while loop to trace the last element in list
  while(current != NULL){
   next=current->next;
   traceNode = heap->head;
   prev = NULL;
   //free the memory 
   //free the memory from the beginnig of the list  
   if(prev!=NULL){
    prev->next = traceNode->next;
   }else{
    heap->head = traceNode->next; 
     }
    //free the memory data first ,then free the node it self.
   free(traceNode->data);
   free(traceNode);
    //forward one position
   current = next;
     }
   }


 
