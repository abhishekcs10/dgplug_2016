============
Ansible
============

A development environment setup to do all of your scripting work on servers automatically.

It does

1- Configuration Management
2- Server Deployment
3- Ad-hoc task Execution

Find examples at-

`Ansible Github <https://github.com/geerlingguy/ansible-for-devops>`_

Find documentation of ansible at

docs.ansible.com


Creating A Basic Inventory File in ansible
---------------------------------------------

Ansible uses an inventory file to communicate with your server.
Like a hosts file (at /etc/hosts) that matches IP address to domain names, an Ansible inventory file matches servers (IP address or domain names) to groups.

**The default directory is /etc/ansible/hosts**

Inventory file format
----------------------

you need sudo

::

	[example]
	www.example.com

where example is the group of servers you are managing and next line is the domain name or IP address of a server in that group.

*If you are not using 22 for ssh on this server, then put domain name as www.example.com:port*

The example assumes the you have a server somewhere that you can connect to.
By *connect to* means the public and private key have been setup and password authentication is not needed.
Run following command to connect

::

	$ansible example -m ping -u [username]

If you need to have password authentication install **sshpass** and run following command.
	
::

	$ansible example -m ping -u [username] -k

To check memory usage of remote machine
==========================================

::

	$ansible example -a "free -m" -u [username]

.. note::
	- *free* is linux command to check memory usage
	- with -a option you can run any linux related command on server







