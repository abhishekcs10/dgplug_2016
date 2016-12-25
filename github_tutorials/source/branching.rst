=============
The workflow
=============

From the updated master branch create a new branch and make your changes to that branch. Now after you push your branch to repository create a pull request.

Pull request is just like asking others to review your code and merge it to main branch if everything is fine with your code and the branch gets deleted.


==========
Branching
==========

By default the branch on which we work is called `master`.

to view current branch
-------------------------

::

	git branch

to create new branch (equivalent to creating a whole new copy of existing code)
----------------------------------------------------------------------------------

::

	git branch branch_name

to switch to other branch
-----------------------------

::

	git checkout branch_name

now you can simply perform git add and git commit without effecting the master branch

merge changes from existing branch to main branch(master)
------------------------------------------------------------

switch to master branch using git checkout then 

::

	git merge branch_name


.. seealso:: 
	
	- Begin by doing a git pull to get the latest content on your master branch
	- Run "git branch your-feature-name" to make a git branch
	- Code in your changes, add and commit the files
	- Pull the master branch again and merge it with your new branch
	- Push the branch up to github and submit it as a pull request
	- That pull request can now receive comments and code discussion, as well as accept new commits before being merged in with the master branch
