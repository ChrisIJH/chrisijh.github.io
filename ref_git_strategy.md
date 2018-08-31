---
layout: level1default 
permalink: /reference/ref_git_strategy/
---

# Git Strategy 

- <h2> New user for git</h2>

**With su**
<pre>
# new group
[**root@Server** ~]# groupadd dev

# new user
[**root@Server** ~]# useradd -G devs -d /Users/gituser -m -s /bin/bash gituser

# password
[**root@Server** ~]# passwd gituser
</pre>

- <h2> Bare repository </h2> 

**Now as a gituser**
<pre>

[**gituser@Server** ~]$ mkdir project.git

[**gituser@Server** ~]$ cd project.git

[**gituser@Server**  project.git]$ ls

[**gituser@Server**  project.git]$ git --bare init
Initialized empty Git repository in /home/gituser-m/project.git/

[**gituser@Server**  project.git]$ ls
branches config description HEAD hooks info objects refs
</pre>

