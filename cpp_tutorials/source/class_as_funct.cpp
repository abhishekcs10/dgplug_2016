====================================
Making Class behave as a Function
====================================

Functionality of operator
===========================

Reference: `Functionality of void operator<https://stackoverflow.com/questions/11857150/functionality-of-void-operator>`_


::

		class background_task
		{
		public:

			void operator()() const
			{
				do_something();
			}
		};

		background_task f;
		std::thread my_thread(f);




You can overload the () operator to call your object as if it was a function:

::

		class A {
		public:
			void operator()(int x, int y) {
				// Do something
			}
		};

		A x;
		x(5, 3); // at this point operator () gets called


So the first parentheses are always empty: this is the name of the function: operator(), the second parentheses might have parameters (as in my example), but they don't have to (as in your example).

So to call this operator in your particular case you would do something like task().



