---
layout: level1default
permalink: /bigdata/mongodb-php/
---


<h1>Installing mongoDB-PHP driver on user area</h1>

<p>PHP MongoDB driver installtion looks pretty straight forward. But, it can be different if you happned to use shared web hosting service. That means you don't have full access to php installation and cannot take an adavantage of <a href="http://docs.mongodb.org/ecosystem/drivers/php/">easy installation.</a></p>

<h3>1. Config php.ini</h3>
<p>Locate the original php.ini by lookin up the result of phpinfo()</p>
<p>Add the following</p>

<pre>
extension_dir="/home/username/bin"
extension = mongo.so
</pre>

<p>The actual driver (extension) is mongo.so which will reside in ~/bin folder.</p>

<h3>2. Clone the git</h3>
<pre>
git clone https://github.com/mongodb/mongo-php-driver.git
</pre>

<h3>3. Compile</h3>
<p>Then, easy process will be as the following which will not apply for this case.</p>
<pre>
$ cd mongo-php-driver-master
$ phpize  # From this, all commands will not work because the installation php directory, include directory all wrong.
$ ./configure
$ make all
$ sudo make install
</pre>

<h5>a. Need to custom phpize file first.</h5>
<pre>
$ which phpize
</pre>
/usr/local/bin/phpize

<p>cp this to the different directory and change it as the below:</p>

<pre>
#!/bin/sh

# Variable declaration
#prefix='/usr/local'
prefix='/opt/alt/php54/usr'
#datarootdir='/usr/local/php'
datarootdir='/usr/local/lib/php'
exec_prefix="`eval echo ${prefix}`"
#phpdir="`eval echo ${exec_prefix}/lib/php`/build"
phpdir="`eval echo ${exec_prefix}/lib64/php`/build"
includedir="`eval echo ${prefix}/include`/php"</pre>

<p>The result of phpize will be like this:</p>
<pre>
$ ./phpize 
Configuring for:
PHP Api Version:         20100412
Zend Module Api No:      20100525
Zend Extension Api No:   220100525</pre>

<h5>b. ./configure --prefix=$HOME</h5>
<h6>c. make</h6>
<p>"make" will not work because Makefile still has wrong options with respect to the location of php ect. Fix the Makefile as below</p>

<pre>
$ cd mongo-php-driver-master/
$ vi Makefile
</pre>


<pre>
prefix = /opt/alt/php54/usr
exec_prefix = $(prefix)
libdir = ${exec_prefix}/lib
prefix = /opt/alt/php54/usr # change to this
phplibdir = /home/veritashq/bin/mongo-php-driver-master/modules
phpincludedir = /opt/alt/php54/usr/include/php  # change to this
CC = cc
CFLAGS = -g -O2
CFLAGS_CLEAN = $(CFLAGS)
CPP = cc -E
CPPFLAGS = -DHAVE_CONFIG_H
CXX =
CXXFLAGS =
CXXFLAGS_CLEAN = $(CXXFLAGS)
EXTENSION_DIR = /usr/local/lib/php/extensions/no-debug-non-zts-20100525
PHP_EXECUTABLE = /usr/local/bin/php
EXTRA_LDFLAGS =
EXTRA_LIBS =
INCLUDES = -I/opt/alt/php54/usr/include/php -I/opt/alt/php54/usr/include/php/main -I/opt/alt/php54/usr/include/php/TSRM -I/opt/alt/php54/usr/include/php/Zend -I/opt/alt/php54/usr/include/php/ext -I/opt/alt/php54/usr/include/php/ext/date/lib -I/home/veritashq/bin/mongo-php-driver-master/api -I/home/veritashq/bin/mongo-php-driver-master/util -I/home/veritashq/bin/mongo-php-driver-master/exceptions -I/home/veritashq/bin/mongo-php-driver-master/gridfs -I/home/veritashq/bin/mongo-php-driver-master/types -I/home/veritashq/bin/mongo-php-driver-master/batch -I/home/veritashq/bin/mongo-php-driver-master/contrib -I/home/veritashq/bin/mongo-php-driver-master/mcon -I/home/veritashq/bin/mongo-php-driver-master/mcon/contrib  # change to this
LFLAGS =

</pre>
<p>Then, 'make'</p>
<p>'make install' still didn't bring the module into the right location. Need to cp it to ~/bin</p>
<p>caution: php.ini file has already extension_dir definition. So, comment it and copy all those *.so in extenxtion_dir direcotry TO ~/bin.</p>



