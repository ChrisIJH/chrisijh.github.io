---
layout: level1default 
permalink: /reference/ref_mysql_01/
---


<h1>Index</h1>
- Creating an index on two columns is not same as creating two separate single-column indexes. COLUMN ODER IS VERY IMPORTANT.
- InnoDB uses B+Trees.
- MyISAM uses a prefix compression technique that makes indexs smaller, but InnoDB leaves values uncompressed in its indexes. MyISAM indexes refer to the indexed rows by their pyhsical storage locations, but InnoDB refers to them by their primary key values.
- The general idea of B-Tree is that all the vlaues are stored in order. it starts at the root node. Each slot holds pointers to child nodes. It finds the right pointer by looking at the vlaues in the node pages which define the upper and lower bounds of the values in the child nodes. 
- B-Trees store the indexed columns in order, they are useful for searchign for ranges of data. ex) everyone whose name begins with I throught K.

## B-tree index limitation
- When index columns are: lastname, firstname, dob
- They are NOT useful if the lookup does not start from the leftmost side of the indexed columns. ex) find all people neamd Bill or all  people born ona certain date, because those columns are not leftmost in the index. Likewise, you can't use the index to find people whose last name ends with a particular letter.
- you can't skip columns in the index.ex) find all people whose last name is Smith and who were born on a particular date. Mysql will just use only the first column of the index which is last name in this case.
- The storage engine can't optimize accesses with any columns to the right of the first range condition. ex) Where last_name='smith' and first_name LIKE 'J%' and dob='1999-1-1', the index will use only the first two columns excluding dob because 2nd columns is the first range condition appeared.
- In MySQL, only the memory storage engine supports explicit hash indexes.

# Indexing Strategies
## Isolating the column
- The index column should be isolated in the query. That is, it should not be part of an expression or be inside a function in the query. ex) Select actor_id from sasd.actor where actor_id + 1 = 5; -->It's not working. where clause should be simple. index column should be alone on one side of the comparison operator.

## Prefix indexes and Index Selectivity
- When index is a very long character column, use only the first few characters instead of the whole value. For BLOB or TEXT columns, or very long VARCHAR columns, you must define prefix indexes, because MySql disallows indexing their full length.
- MySQL cannot use prefix indexes for ORDER BY or GROUP BY queries, nor can it use them as covering indexes.

## Multicolumn Indexes
- Individual indexes on lots of columns won't help MySQL improve performance for most queries. MySQL 5.0 can cope a little with this by using an index merge. But, earlier version could use only a single index.  
ex) If the table has an index of film_id and an index of actor_id:
SELECT film_id , actor_id FROM sadf.film_actor WHERE actor_id=1 OR film_id=1  
--> 5.0 and higher will use index merge which uses UNION automatically. Lower version will just do table scan.  
In this OR case, use UNION:  

SELECT film_id , actor_id FROM sadf.film_actor WHERE actor_id=1  
UNION ALL  
SELECT film_id, actor_id FROM sadf.film_actor WHERE film_id=1 AND actor_id <> 1;  
- INTERSECTION for AND  

## Choosing a Good Column Order
- B-Tree index is sorted by the leftmost column then by the next column, and so on. It satisfies ORDER BY, GROUP BY, DISTINCT clauses.
ex) query: SELECT * FROM payment WHERE staff_id= 2 AND customer_id= 584;  
If we check the number of rows for each one,   mysql> SELECT SUM(staff_id= 2), SUM(customer_id= 584) FROM payment\G  
*************************** 1. row ***************************  
     SUM(staff_id= 2): 7992  
SUM(customer_id= 584): 30  

According to the rule of thumb, we should place customer_id first in the index.
