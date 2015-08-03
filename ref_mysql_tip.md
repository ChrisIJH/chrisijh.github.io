---
layout: level1default 
permalink: /reference/ref_mysql_tip/
---

<h3>Get the ID generated in the last query</h3>

<p>Never forget the argument $link below : <mark>mysql_insert_id($link)</mark></p>
<pre>
<xmp>
<?php
$link = mysql_connect('localhost', 'mysql_user', 'mysql_password');
if (!$link) {
    die('Could not connect: ' . mysql_error());
}
mysql_select_db('mydb');

mysql_query("INSERT INTO mytable (product) values ('kossu')");
printf("Last inserted record has id %d\n", mysql_insert_id($link));
?>
</xmp>
</pre>

