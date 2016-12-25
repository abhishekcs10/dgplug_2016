============
permissions
============

::

	
    0100000000000000 (040000): Directory
    1000000110100100 (100644): Regular non-executable file
    1000000110110100 (100664): Regular non-executable group-writeable file
    1000000111101101 (100755): Regular executable file
    1010000000000000 (120000): Symbolic link
    1110000000000000 (160000): Gitlink

you add a new remote that would point to this main repo

::

	git remote add upstream https://github.com/sayanchowdhury/foobar.git

github configuration file
---------------------------

::

	.git/config

pull general syntax
---------------------

::

	git pull <remote_url> <branch_name>

Checking modifications made
==============================

In staged mode
---------------

::

	git diff --staged

In normal modified but unstaged mode

::

	git diff

How to work with repository of some other organisation
===========================================================

steps->

.. note::

	1-	Fork the repository
	2-	Clone it to your local machine
	3-	Now add remote stream to the original git repo

	::

		git remote add upstream https://github.com/user/foobar.git	

	4-	now `git pull --rebase upstream master` will pull changes from the original repo.
	5-	now when you try to push using `git push upstream master` this will give you an error as it points to my repo and you don't have access
	6-	so you need to do `git push origin master` --> that will push to you repo :)
	7-	Next go to your github repo the `foobar-1` one and create pull request
	8-	After review the maintainer of project will merge the changes

done!!
