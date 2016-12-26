============
MAP
============

Create map
-----------

map<key_type, value_type> arr;


Insert
-------

arr[key]=value;//inserts if key doesnot exist and replaces value if exists

iterator
---------

map< , >::iterator it;

find key
--------

arr.find(key);

returns iterator and if iterator ==arr.end() it is not present in map

access value using iterator
-----------------------------

it->first gives key

it->second gives value





