---
layout: level1default 
permalink: /reference/ref_r_01/
---

<h1>R reference</h1>


<h5>Data loading writing</h5>

<p>dataframe to file</p>

<pre>
# Without row.names=FALSE, the result will includes the row index as string at the leftmost column.
write.table(Boston,file="a.txt", row.names=FALSE)
</pre>

