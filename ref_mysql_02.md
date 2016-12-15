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
<h2> When remote connection not working </h2>
<p>
<ol>  
<li> Run > mysql -u root</li>  
<li> GRANT ALL PRIVLEGES ON *.* TO 'root'@'%' ;</li>  
</ol>
</p>
<h2> More data size allowed </h2>
<p>
<ol>  
<li> At my.cnf, [mysqld] max_allowed_packet=500M</li>  
<li> Or run > set global max_allowed_packet=104857600</li>  
</ol>
</p>
<h2> More connection allowed </h2><p><ol> <li>run > set global max_connections=2048</li>  
</ol>
</p>

## Move DB


- $ mysqldump -u root [old DB name] > name.sql
- $ mysql -u root [new DB name] < name.sql

## Move table
- $ mysqldump -u root [DB name] [table name] | mysql-u root [new DB name]
- Being copied to the same table name

## No inf to table
