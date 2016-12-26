===========
algorithm
===========

sorting
-------

constructors
+++++++++++++

::

	sort(begin_iterator, end_iterator)
	sort(begin,end,cmp)

where cmp is any function that defines what comparison makes the first arguement of the function smaller than the other.

eg:

::
		cmp(a,b){
			if(a<b)
				return true;
			else
				return false;
