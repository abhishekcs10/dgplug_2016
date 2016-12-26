============
Input
============

input number to arbitrary precision
------------------------------------

::

	#include <math.h>

	float val = 37.777779;

	float rounded_down = floorf(val * 100) / 100;   /* Result: 37.77 */
	float nearest = roundf(val * 100) / 100;  /* Result: 37.78 */
	float rounded_up = ceilf(val * 100) / 100;      /* Result: 37.78 */ 

Notice that there are three different rounding rules you might want to choose: round down (ie, truncate after two decimal places), rounded to nearest, and round up. Usually, you want round to nearest.

As several others have pointed out, due to the quirks of floating point representation, these rounded values may not be exactly the "obvious" decimal values, but they will be very very close.

Above code prints double number upto n precision

roundf->
--------

	round double number to nearest integer. Thus to get nearest integer precision do->

::

	number=(number*(10^p))/(10^p); //number is rounder for p precision
