#include <iostream>
#include <string>
#include <cstdio> 
#define MAX_VALUE 100
using namespace std;

typedef struct{
int key;
}element;

typedef struct{
	element heap[MAX_VALUE];
	int heap_size;
}HeapType;


void init(HeapType* h);

element delete_max_heap(HeapType* h){
	int child =2, parent =1;
	element temp, item;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	
	while(child <= h->heap_size){
		if(child <h->heap_size && (h->heap[child].key < h->heap[child+1].key))child ++;
		
		if(temp.key > h->heap[child].key) break;
		
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	
	return item;

	
}

void insert_max_heap(HeapType* h, element item) // 1 7 3 9 4 -> 1 -> 7 1 ->  7 1 3 -> 9 7 3 1 -> 9 7 3 1 4
{
	int i ;
	i = ++(h->heap_size);
	while(i != 1&& item.key > h->heap[i/2].key){
		
		h->heap[i] = h->heap[i/2];
		i /=2;
		
	} 
	h->heap[i] = item;
	

}

void heap_sort(element a[] , int n)
{
	HeapType h;
	init(&h);
	
	for(int i = 0 ; i<n ; i++)
	{
		insert_max_heap(&h,a[i]);
		

	}
	for(int i = n-1 ; i>=0 ; i--)
	{
  a[i] = 		delete_max_heap(&h);
}

}

void init(HeapType* h)
{
	h->heap_size = 0;

}
int main( )
{
	int n;
	cin >> n;
	
	element * a = new element[n];
	for(int i = 0 ; i< n ; i++){
		
		cin >> a[i].key; 
	}
	heap_sort(a,n);
	
		for(int i = 0 ; i< n ; i++){
	
			cout << a[i].key << " ";
	}
	
	delete[] a;
	return 0;
}

