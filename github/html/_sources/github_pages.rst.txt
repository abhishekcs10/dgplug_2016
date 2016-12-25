================
Github Pages
================

Setup Github Page for user or organization
============================================

It is like having your portfolio on github domain..:)
To create one -

::

	- Create a repository with name <username>.github.io 
	- Add your website source code to this repository.
	- Now your website goes live on https://<username>.github.io/

*Replace <username> with your github username.*

Creating github pages for your project
=======================================

You can configure GitHub Pages to publish your site's source files from master, gh-pages, or a /docs folder on your master branch for Project Pages and other Pages sites that meet certain criteria.


.. note::
	
	If your site is a User or Organization Page that has a repository named <username>.github.io or <orgname>.github.io, you cannot publish your site's source files from different locations. User and Organization Pages that have this type of repository name are only published from the master branch.


Enabling GitHub Pages to publish your site from gh-pages 
=============================================================

If the above things confused you... just ignore and follow below steps to setup website for your project.

Using **gh-pages** works in all situation.

To select gh-pages as your publishing source, you must have the branch present in your repository. If you don't have a gh-pages branch, you can create them and then return to source settings to change your publishing source.

Creating *gh-pages* branch
-----------------------------

::

	git branch gh-pages
	git checkout gh-pages
	git rm  
	- On GitHub, navigate to your GitHub Pages site's repository.
	- Repository settings buttonUnder your repository name, click **Settings**.
	- Use the Select source drop-down menu to select master or gh-pages as your GitHub Pages publishing source.



