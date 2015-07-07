---
layout: level1default
permalink: /bigdata/spark-var/
---

Introduction
------------

**_Value-At-Risk(VaR)_** is an important and effective risk measure. There are several ways to compute this. One famous
 method is the one using Monte Carlo Simulation. However, it requires heavy computation. In this project, Apache Spark (with python) is
 used to compute the intraday VaR with yahoo historical 5 min data for example.  
This project consists of 2 different jobs to implement of risk management by finding **_Value-At-Risk(VaR)_** 
using 5-minute-tick-data with [Apache Spark][1]. One is data collecting job which is coded in _Java_. 
The other is computation job for finding VaR coded in _Python_ with [**Spark Python API**][2]. 
This project will give an example of implementing VaR by utlizing not only [**Hadoop ditributed file system**][4] 
and spark cluster computing platform but also its computing algorithm with iPython's interactive analytic functionality. 
We used [*Google Cloud Service*][3].

[1]: http://spark.apache.org
[2]: http://spark.apache.org/docs/1.0.2/api/python/index.html
[3]: https://cloud.google.com
[4]: https://hadoop.apache.org


System
------
- Google Cloud Service: Standalone deploy mode. 
  - Master node and workers for Apache Spark.
  - Name/Secondary node, Data nodes
- iPython : For interactive analytics
  - configured with Pyspark module
  - configured for remote access to master server
- Apache Hadoop 1.2.1
  - Name Node, Secondary Name Node, Data Nodes
- Apache Spark 1.0.2
  - Master/Worker, Workers
- Directory Structure of **Hadoop File System**
  
    >/-- bdproject/  
    >    /-- data/ : Storing 10-day-5min-Tick-data  
    >    /-- dailyData/ : Storing 1-day-1min-Tick-data  
    >    /-- sp500 : file containing all tickers  


Software Packages
-----------------

- Files at Master Node

```  
|-- bdproject/
      |-- TickDataReadWrite.java
      |-- ReadTickData.jar
      |-- GetVar.py
      |-- GetVar_least_spark.py
      |-- sp500
```
  
- Data Collecting Module
  - TickDataReadWrite.java : Jave file for data collecting and write them to Apache Hadoop Ditributed File System.
  - ReadTickData.jar : Jar package from TickDataReadWrite.java
  - Using crontab or other utility for automated collecting.
- Computing Module
  - GetVar.py : Python file for computing Value-At-Risk of Portfolio using Apache Spark Python API.
  - GetVar_least_spark.py : Python file for comparing the performance of plain python and the Apache Spark. It uses Apache Spark Python API only for accessing hadoop files. It didn't use any other Apache Spark Python API for computing VaR.
- sample file
  - sp500: Ticker list

Usages
------

1. Replace the Hadoop File System paths in the TickDataReadWrite.java accordingly based on your particular directory structure. However, Yahoo Finance url should not change.
2. Create Jar file then run it. Use Cron or other time based job scheduler for automatic data collecting. 10-day data will be collected once a day before market opens. 1-min data will be collected every 5 minutes while market opens 
  - example:
  
    For 10-day 5-min data

    `hadoop jar ReadTickData.jar com.cijhwang.hadoop.TickDataReadWrite 0`
    
    For 1-day 1-min data
    
    `hadoop jar ReadTickData.jar com.cijhwang.hadoop.TickDataReadWrite 1`
3. Start the ipython with pyspark loaded
4. Connect to ipython server and run GetVar.py
  - example:
  
    `% run GetVar.py`

Algorithm
---------

Basic Alrgorithm is as below:

![algo](https://www.evernote.com/shard/s9/sh/c7eeb72a-87f5-430b-9418-00c6c9b0319e/1766485dc5e07387873a0c0ec6bc651a/deep/0/Pasted-Image-1-20-15,-4-29-AM.png)  



[here](https://github.com/Sapphirine/Real-time-Risk-Management-System){:target='_blank'} is the link to GitHub for this project.



