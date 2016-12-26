Allocation in c
================

applies to pointer of data structure

malloc
-------

::

	(void *) malloc (num*sizeof(arr));

simply allocates memory

calloc
-------

::

	(void *) calloc(int num, sizeof(type));

clears memory and initializes to zero.

c++ allocation
----------------

::
	
	pointer = new type
	pointer = new type [number_of_elements]


The first expression is used to allocate memory to contain one single element of type type. The second one is used to allocate a block (an array) of elements of type type, where number_of_elements is an integer value representing the amount of these. For example:

::

	int* foo;
	foo = new int [5];

	
In this case, the system dynamically allocates space for five elements of type int and returns a pointer to the first element of the sequence, which is assigned to foo (a pointer). Therefore, foo now points to a valid block of memory with space for five elements of type int.

::

	int *k;
	k=new (nothrow) int[i];


In this case, if the allocation of this block of memory fails, the failure can be detected by checking if foo is a null pointer:

::

	1 int* foo;
	2 foo = new (nothrow) int [5];
	3 if (foo == nullptr) {
	4 // error assigning memory. Take measures.
	5 }

 
