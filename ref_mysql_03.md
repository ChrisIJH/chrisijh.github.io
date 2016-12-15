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
