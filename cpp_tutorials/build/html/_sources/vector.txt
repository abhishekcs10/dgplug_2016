===================
VECTOR
===================

unique(begin,end)
------------------

returns iterator of last element inserted and does not alters the size of container

resize(count)
--------------

::
	resize(end-begin)
 
where end denotes the last index of resized array and begin represents the starting index of resized array.

assign(int how_many, int what_value)
--------------------------------------

assigns new values to vector array

::

	arr.assign(n,100)

assigns n elements initialized with 100

::

	arr (c_arr,c_arr+n)

assigns value from c_array to vector
