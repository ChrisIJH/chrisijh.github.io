---
layout: level1default 
permalink: /bigdata/linear-regression-spark/
---

<h1>Linear Regression Using Spark</h1>
[reference] : Scalable Machine Learning by BerkeleyX at Edx.org 

<h3>Bring up Spark </h3>

<pre><code>
import sys
import os
spark_home = os.environ.get('SPARK_HOME', None)
sys.path.insert(0, '/usr/local/spark/python')
sys.path.insert(0, '/usr/local/spark/python/lib/py4j-0.8.2.1-src.zip')
execfile(os.path.join(spark_home, 'python/pyspark/shell.py')
</code></pre>


<h2>Implementing from the ground</h2>

<h3>Reading a file</h3>

<p>At Shell,</p>
<pre><code>
head -n 10 millionsong.txt
wc -l millionsong.txt
head -n 1 millionsong.txt | awk -F',' ' { print NF }'
</code></pre>

<pre><code>
base_dir = os.path.join('data')
input_path = os.path.join('more_path', 'millionsong.txt')
filename = os.path.join(base_dir,input_path)
num_partitions = 2
rawData = sc.textfile(filename)
</code></pre>

<h3>Split and take samples (RDD)</h3>

<h3>Use LabledPoint</h3>


<h2>Using MLlib</h2>