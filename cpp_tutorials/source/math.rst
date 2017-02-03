======================
Mathematical function
======================

Find ditance between two points
================================

hypot
------

proto: double hypot(double x,double y)

to find distance between (x1,y1) and (x2,y2)

::

	dist=hypot(x2-x1,y2-y1)

Finding polar cordinates from cartesian cordinates
=====================================================

To calculate polar cordinates use following functions
-------------------------------------------------------

atan2
++++++

 For any real number (e.g., floating point) arguments x and y not both equal to zero, atan2(y, x) is the angle in radians between the positive x-axis of a plane and the point given by the coordinates (x, y) on it. The angle is positive for counter-clockwise angles (upper half-plane, y > 0), and negative for clockwise angles (lower half-plane, y < 0)

.. math::

	 \mathbf {atan2} (y,x)={\begin{cases}\arctan({\frac{y}{x}})&{\text{if }}x>0,\\\arctan({\frac {y}{x}})+\pi &{\text{if }}x<0{\text{ and }}y\geq 0,\\\arctan({\frac {y}{x}})-\pi &{\text{if }}x<0{\text{ and }}y<0,\\+{\frac {\pi }{ 2}}&{\text{if }}x=0{\text{ and }}y>0,\\-{\frac {\pi }{2}}&{\text{if }}x=0{\text{ and }}y<0,\\{\text{undefined}}&{\text{if }}x=0{\text{ and }}y=0.\end{cases}}

 
::

	double atan2(double y,double x)	


.. seealso::

	atan calculates angle but only for first and fourth quadrant irrespective of signs of x and y coordinate.
	also the atan2 calculates angle from x-axis so consider the case to shift the given cordinate system to origin


Value of pi
=============

define pi as acos(-1.0)








