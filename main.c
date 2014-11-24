#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mhDefs.h"
#include "stuDefs.h"



//Struct a new type called heaptype

//This function initalize heaptype in main function
//void mh_init(HeapType *heap);

//A memory allocation prototype. Free the memory allocated
//void mh_cleanup(HeapType *heap);

/*add a new block to block array, save the address, return
memory using malloc()
*/
//void *mh_alloc(HeapType *heap, int n, char *label);


/*The function finds the blocks element in heap parameter corresponds to the block of memory pointed by addr
it sets the block element to not reserverd and deallocates the memory pointed by addr using free();
*/
//void mh_dealloc(HeapType *heap, void *addr);

/*
*/
//int mh_count(HeapType *heap);

/*A screen dumping function with prototype:
*/
//void nh_dump(HeapType *heap);

/*A garbage collection function with prototype
using free()*/
//void mh_collect(HeapType *heap);


int main()
{
  HeapType *heap;
  void  *ptr1, *ptr2, *ptr3, *ptr4,*ptr5,*ptr6,*ptr7,*ptr8,*ptr9;

  heap = (HeapType *) malloc(sizeof(HeapType));
  mh_init(heap);

  ptr1 = mh_alloc(heap, 5*sizeof(int), "ints");
  ptr2 = mh_alloc(heap, 10*sizeof(double), "doubles");
  ptr3 = mh_alloc(heap, 8*sizeof(char), "chars");
  ptr4 = mh_alloc(heap, 12*sizeof(StudentType), "Students");
  ptr5 = mh_alloc(heap, 12*sizeof(SupermanType), "superman");
  ptr6 = mh_alloc(heap, 10*sizeof(float), "Float");
  ptr7 = mh_alloc(heap, 3*sizeof(long), "Long");
  ptr8 = mh_alloc(heap, 2*sizeof(short), "short");
  ptr9 = mh_alloc(heap, 12*sizeof(SpiderType), "Spider");
  printf("\nDUMP 1, byte count = %d\n", mh_count(heap));
  mh_dump(heap);
  //add 5 new types to test
  mh_dealloc(heap, ptr1);
  mh_dealloc(heap, ptr2);
  mh_dealloc(heap, ptr3);
  mh_dealloc(heap, ptr7);
  mh_dealloc(heap, ptr4);
  mh_dealloc(heap, ptr5);

  printf("\nDUMP 2, byte count = %d\n", mh_count(heap));
  mh_dump(heap);

  mh_collect(heap);

  printf("\nDUMP 3, byte count = %d\n", mh_count(heap));
  mh_dump(heap);
  printf("\n\n");

  mh_cleanup(heap);
  free(heap);

  return 0;
}









