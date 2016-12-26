============
Date format
============

Determine day on given date
----------------------------

::

	#include<stdio.h>

	int dayofweek(int d, int m, int y)
	{
	  	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
		y -= m < 3;
	 	return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
	}

	/* Driver function to test above function*/
	int main()
	{
		int day = dayofweek(30, 8, 2010);
		printf ("%d", day);
		return 0;
	}




Explanation of above
------------------------

Let us start with the simple scenario in which leap years did not exist and every year had 365 days.

Knowing  what day January 1 falls on a certain year, it is easy to find which  day any other date falls. This is how you go about it : January has 31 =  7 × 4 + 3 days, so February 1 will fall on the day which follows three  days after January 1. Similarly, March 1 will fall on the day three days  after the day corresponding to January 1, April 1 will fall 6 days  after, and so on. Thus, the first days of each month are offset with  respect to January 1 by the array {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5}.  This array is essentially what t[] is. Notice that it is slightly  different from the t[] given in the question, but that is due to leap  years and will be explained later. Once the day corresponding to the  first date of the month is known, finding the day for any other date is  just a matter of addition.

Since  365 = 7 × 52 + 1, the day corresponding to a given date will become  incremented by 1 every year. For example, July 14, 2014 is a Monday and  July 14, 2015 will be a Tuesday. Hence adding the difference between  year numbers allows us to switch from the day of a reference year to any  other year.

At this stage, the leap-year free dow function can be written as such:

::

    int dow(int y, int m, int d){ 
      static int t[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5}; 
      return (y + t[m-1] + d + c) % 7;
    }



Here  c is a constant which corresponds to setting the "origin" of the day  system : y, t[m] and d only tell us how many days to shift by; we need a  reference to start the shifting and which is provided by c.

Now  let us look at the real case when there are leap years. Every 4 years,  our calculation will gain one extra day. Except every 100 years when it  doesn't. Except every 400 years when it does (Seriously, what kind of  intelligent designer comes up with this stuff? Couldn't the duration of  the year have been an integer multiple of the synodic day?). How do we  put in these additional days? Well, just add y/4 - y/100 + y/400. Note  that all division is integer division. This adds exactly the required  number of leap days.

Except  there is a tiny problem. The leap day is not January 0, it is February  29. This means that the current year should not be counted for the leap  day calculation for the first two months.

How  do we do this? Well, there are probably many intuitive ways to go about  this. But this piece of code sacrifices intuition for brevity. Suppose  that if the month were January or February, we subtracted 1 from the  year. This means that during these months, the y/4 value would be that  of the previous year and would not be counted.

Smart,  right? Except for a tiny problem. We are subtracting 1 from the year  for January and February for non-leap years too. This means that there  would be a "blank" day between February 28 and March 1, that is, we have  made every non-leap year a leap year, and leap years double-leap years.  Hm, so what if we subtracted 1 from the t[] values of every month after  February? That would fill the gap, and the leap year problem is solved.  That is, we need to make the following changes:

::

    t[] now becomes {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4}


if m corresponds to Jan/Feb (that is, m<3) we decrement y by 1
the annual increment inside the modulus is now y + y/4 - y/100 + y/400 in place of y


That's it, we get the full solution


::

    int dow(int y, int m, int d){ 
      static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4}; 
      y -= m < 3;
      return (y + y/4 - y/100 + y/400 + t[m-1] + d + c) % 7;
    }



Coincidentially, c just happens to be 0 - this is an empirical fact and cannot be "derived" from anything we have done till now - and we get back the function in the question.
