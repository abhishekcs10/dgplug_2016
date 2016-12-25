================
Source Control
================

When multiple users are trying to edit the same file, how the original file gets edited is all that we read in source control

Github keeps the track of all the changes that have been made.

It detect, for example, conflicts on any line on which changes have been made. If the change is made on the same line it asks for the correct version of the file.


Getting thing from existing repository(your own github account) online on github to your machine (Github cloning)
-------------------------------------------------------------------------------------------------------------------

::

	git clone link_to_git_repository(eg https://www.github.com/user/project.git

it creates a folder with the name of the name of the project in the present directory.

Check what changes have been made from online version of the project to offline version.
-----------------------------------------------------------------------------------------

run on your local machine 

::

	git status 


to add particular file to the github repository
-------------------------------------------------

the files which have not been yet added to the git repo are known as **Untracked Files**.

::

	git add *file_name*

if you type git status again you will notice the changes to be commited in the github repository.

To add all the files chaged in current github directory

::

	git add .

				OR

::
	
	git add -A



After adding the git files using git add the files are said to be in **Staged state**

to commit the changes in the github repository
------------------------------------------------

::

	git commit -m "your_message"

it makes changes in the local copy of the repository but still online copy is unchanged.

.. note::  to make multi line msg comment simply remove -m arguement git then opens vim to add message

to make changes to online copy of repository
----------------------------------------------

::

	git push

to get the changes from online repository to the local machine 
-----------------------------------------------------------------

::
	
	git pull

Note:	 
+++++

`git commands work if the user is inside the git directory`

now if you check git status you will be notified about the changes made to git repository

Conflicts
------------

If there are git conflicts in a file, at merge time they will be reflected in the file
<<<<<<<<<<<<<<HEAD    -> changes made by you

>>>>>>>>>>>>>>>>>>>>> some_hash_checksum

simply fix conflicts manually
remove the extra lines added by git
save file

::

	type git add -A
	git commit (without -m )

then merge will continue


Creating a new repository on your local machine and getting it to the github remote directory
-----------------------------------------------------------------------------------------------------

First make a folder and then run

::

	git init

this initialises the git repository in your current folder. Then commit project in your local machine repository.

then when you get internet connection

make a repository with the same name
now go to the local machine github project folder and run

::

	git remote add origin http_path_to_your_proect

then 

::

	git branch --set-upstream-to=origin/master master


