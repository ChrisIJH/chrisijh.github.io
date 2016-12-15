---
layout: level1default 
permalink: /reference/ref_mysql_02/
---

# Mysql 2

<h1>Installation</h1>
<p>
<ol>
  <li> Change my_default.ini to my.ini</li>
  <li> In side the file, basedir = "..." and datadir = "..."</li>
  <li> Run > mysqld --log_syslog=0 --initialize-insecure : This will do no log and create root account without password.</li>
  <li> Run > mysqld --log_syslog=0</li>
  <li> To shutdown, run > mysqladmin -u root shutdown </li>
</ol>
</p>
<h2>When remote connection not working </h2>
