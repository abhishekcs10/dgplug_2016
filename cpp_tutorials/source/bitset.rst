=================
Bitset
=================

Constructor
------------

::

	bitset<16> foo;
	bitset<16> f2(0xfa2);
	bitset<16> baz(string("101010011"));

set bits
---------

::

	foo.set();  //sets all bits in bitset
	foo.set(2,0) //sets 2nd index bit from lsb to 0 (indexing from 0)
	foo.set(2) //sets 2nd index bit to 1



	 
	
