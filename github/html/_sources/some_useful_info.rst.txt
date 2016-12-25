=====================
Understanding GITHUB 
=====================

Permissions
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


Rebase
=========

To understand this, we need to understand a bit about how git works. A git repository is a tree structure, where the nodes of the tree are commits. 
Lets take following example

.. figure:: rebase.jpg
	:width: 200px
	:height: 200px
	:align: center
	:figclass: align-center	
	:alt: Before-rebase
	
	Before rebase

it has four commits on the master branch, and each commit has an ID (in this case, a, b, c, and d). You'll notice that d is currently the latest commit (or HEAD) of the master branch. 
Here, we have two branches: master and my-branch. You can see that master and my-branch both contain commits a and b, but then they start to diverge: master contains c and d, while my-branch contains e and f. b is said to be the "merge base" of my-branch in comparison to master -- or more commonly, just the "base". It makes sense: you can see that my-branch was based on a previous version of master.

So let's say that my-branch has gone stale, and you want to bring it up to date with the latest version of master. To put it another way, my-branch needs to contain c and d. You could do a merge, but that causes the branch to contain weird merge commits that make reviewing the pull request much more difficult. Instead, you can do a rebase.

.. figure:: rebase2.jpg
	:width: 200px
	:height: 200px
	:align: center
	:figclass: align-center	
	:alt: After-rebase
	
	After rebase


When you rebase, git finds the base of your branch (in this case, b), finds all the commits between that base and HEAD (in this case, e and f), and re-plays those commits on the HEAD of the branch you're rebasing onto (in this case, master). Git actually creates new commits that represent what your changes look like on top of master: in the diagram, these commits are called e′ and f′. Git doesn't erase your previous commits: e and f are left untouched, and if something goes wrong with the rebase, you can go right back to the way things used to be.

When many different people are working on a project simulateously, pull requests can go stale quickly. A "stale" pull request is one that is no longer up to date with the main line of development, and it needs to be updated before it can be merged into the project. The most common reason why pull requests go stale is due to conflicts: if two pull requests both modify similar lines in the same file, and one pull request gets merged, the unmerged pull request will now have a conflict. Sometimes, a pull request can go stale without conflicts: perhaps changes in a different file in the codebase require corresponding changes in your pull request to conform to the new architecture, or perhaps the branch was created when someone had accidentally merged failing unit tests to the master branch. Regardless of the reason, if your pull request has gone stale, you will need to rebase your branch onto the latest version of the master branch before it can be merged.


How to work with repository of some other organisation
===========================================================

The book steps (ProGit)
-------------------------

.. note::

	1. Fork the repository
	2. Create a topic branch from master .
	3. Make some commits to improve the project.
	4. Push this branch to your GitHub project.
	5. Open a Pull Request on GitHub.
	6. Discuss, and optionally continue committing.
	7. The project owner merges or closes the Pull Request.
	
	Eg- Let the project forked be abc

	.. code-block:: bash

		$ git clone my_copy_of_project_url
		$ cd abc
		$ git checkout -b new_branch
		$ #make changes whatever you want
		$ git diff --word-diff
		$ git commit -a -m "message"
		$ git push origin new_branch

	Then do step 5,6,7 

The problem in above steps is what if you want to pull changes from the original source.

**You have two main options in order to do this. You can either rebase your 
branch on top of whatever the target branch is (normally the master branch of the repository you forked), or you can merge the target branch into your branch.
Most developers on GitHub will choose to do the latter, for the same reasons we just went over in the previous section. What matters is the history and the final merge, so rebasing isn’t getting you much other than a slightly cleaner history and in return is far more difficult and error prone.
If you want to merge in the target branch to make your Pull Request mergeable, you would add the original repository as a new remote, fetch from it, merge the main branch of that repository into your topic branch, fix any issues and finally push it back up to the same branch you opened the Pull Request on.**

Manual merging (Preferred)
-------------------------------

.. note::

	1.	Fork the repository
	2.	Clone it to your local machine
	3.	Now add remote upstream to point the original git repo

	::

		git remote add upstream https://github.com/user/foobar.git

	4.	now `git fetch upstream master` will pull changes from the original repo.
	5.	`git merge upstream/master` //conflicts may arise resolve them
	6.	Now you need to do `git push origin master` --> that will push to you repo :)
	7.	Next go to your github repo the `foobar-1` one and create pull request
	8.	After review the maintainer of project will merge the changes


Rebase method (Less Preferred)
-------------------------------

.. note::

	1.	Fork the repository
	2.	Clone it to your local machine
	3.	Now add remote stream to the original git repo

	::

		git remote add upstream https://github.com/user/foobar.git	

	4.	now `git pull --rebase upstream master` will pull changes from the original repo.
	5.	now when you try to push using `git push upstream master` this will give you an error as it points to my repo and you don't have access
	6.	so you need to do `git push origin master` --> that will push to you repo :)
	7.	Next go to your github repo the `foobar-1` one and create pull request
	8.	After review the maintainer of project will merge the changes

done!!
