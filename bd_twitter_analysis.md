---
layout: level1default
permalink: /bigdata/twitter-analysis/
---

Introduction
------------

**_Twitter_** Analysis



Overview
------

<div class="piktowrapper-embed" pikto-uid="6792262-twit_ana" >
    <div class="pikto-canvas-wrap">
        <div class="pikto-canvas"></div>
    </div>
</div>
<script>
    (function(d){
        var js, id="pikto-embed-js", ref=d.getElementsByTagName("script")[0];
        if (d.getElementById(id)) { return;}
        js=d.createElement("script"); js.id=id; js.async=true;
        js.src="https://magic.piktochart.com/assets/embedding/embed.js";
        ref.parentNode.insertBefore(js, ref);
    }(document));
</script>



## Procedure

<pre><code>
import numpy as np
import pandas as pd
import json
import csv
import nltk
import pymongo
from pymongo import MongoClient
</code></pre>

0. Twitter Data acquired pre process before MongoDB

        # Last line can be not done correctly if it was taken in the middle of receiving twitter stream. So, remove the last line.
        head -n -1 pre.json > test.json

        # There can be a message code from twitter which doesn't start with {. This will make an error when dumping into MongoDB. Find it and delete it.

        grep -vi { test.json > test_tmp.json; mv test_tmp.json test.json
        

1. Actuired data go to MongoDB (time)

    
        client = MongoClient()
        db = client.myDB
        june24 = db.June24
        with open('test.json') as f:
            for line in f:
                a = json.loads(line)
                db.June24.insert_one(a)

2. Load data from MongoDB for analysis
    
        textOnly = june24.find( {}, {"text":1} )
        tobe_parallelized=[]
        for line in textOnly:
            real_text = line['text']
            tobe_parallelized.append(real_text)

   (Cf.)

      db.tweets.delete_many( {} ) # delete all ROWS(DOCUMENT) 
      june24.count()

  2.a. Spark

      rdd = sc.parallelize(tobe_parallelized)

3. Data Cleaning  
<pre><code>

def removePuncLower(text):
    regex = re.compile('[%s]' % re.escape(string.punctuation))
    out = re.sub(regex," ", text) # Punctuation

    out = out.lower()
    out = out.strip()
    out1 = re.split(u'[\s]\s*', out) # Whitespace
    
    result = []
    for w in out1:
        regex2 = re.compile('[\W*]') # nonword character
        tmp = re.sub(regex2, '', w)

        if re.findall(u'\d+', tmp)!=[]: # if the string is either number only or mix of letter, omit it.
            continue
        else:
            tmp = tmp.strip()
            result.append(re.sub(regex2, '', tmp))
                       
    return result

def stop_word(doc):
    stopset = set(nltk.corpus.stopwords.words('english'))
    filter_stops = lambda a: len(a) < 3 or a in stopset
    good_words=[]
    for lstOfWords in doc:
        for word in lstOfWords:
            if not filter_stops(word):
                good_word.append(word)
    return good_words


TotalToken = rdd.map(lambda x: x[1]).flatMap(removePuncLower).map(lambda x: (x,1)).reduceByKey(add)
</code></pre>

## Analysis
In this case, the current python list looks like the following:  
        
[  
     [u'anchorage',  
      u'tutor',    
      u'teacher',  
      u'elementary',  
      u'k-6th',  
      u"i'm",  
      u'interested',  
      u'finding',  
      u'tutor',  
      u'son',  
      u'...'],  
     [u'girls', u'yous', u'diss', u'writing', u'letters', u'like', u'miss'],  
     [u'writing', u'lyrics', u'agonizing,', u'actually', u'[outfit]']  
]  


<pre><code>
counts_map = t_data.map(lambda word: (word, 1)).reduceByKey(lambda a, b: a+b)
count_map_rev = counts_map.map(lambda (x,y): (y,x))
top_100 = count_map_rev.top(100)
# OR
top_100 = counts_map.takeOrdered(100, key=lambda x: -x[1])

with open("./output.csv", "w") as f:
for line in top_100:
    s = str(line[0]) + ' ' + line[1].encode('ascii','ignore') + '\n'
    f.write(s)
</code></pre>

### Possible Error
<pre><code>
Py4JJavaError: An error occurred while calling z:org.apache.spark.api.python.PythonRDD.runJob.
: org.apache.spark.SparkException: Job aborted due to stage failure: Serialized task 4:0 was 17505618 bytes, which exceeds max allowed: spark.akka.frameSize (10485760 bytes) - reserved (204800 bytes). Consider increasing spark.akka.frameSize or using broadcast variables for large values.
</code></pre>
Check https://spark.apache.org/docs/latest/configuration.html  
ADVANCED: DEVOPS WITH APACHE SPARK WORKSHOP from 2015 Spark summit
() 

- solution 1.  
change parameter in conf/spark-defaults.conf
<pre><code>
spark.akka.frameSize  20 # 10 is the default value
</code></pre>


## Visualization
Using Tableau public, I made simple report for the popular words collected from twitter.

<script type='text/javascript' src='https://public.tableau.com/javascripts/api/viz_v1.js'></script><div class='tableauPlaceholder' style='width: 654px; height: 742px;'><noscript><a href='#'><img alt='Dashboard 1 ' src='https:&#47;&#47;public.tableau.com&#47;static&#47;images&#47;Po&#47;PopularWords&#47;Dashboard1&#47;1_rss.png' style='border: none' /></a></noscript><object class='tableauViz' width='654' height='742' style='display:none;'><param name='host_url' value='https%3A%2F%2Fpublic.tableau.com%2F' /> <param name='site_root' value='' /><param name='name' value='PopularWords&#47;Dashboard1' /><param name='tabs' value='no' /><param name='toolbar' value='yes' /><param name='static_image' value='https:&#47;&#47;public.tableau.com&#47;static&#47;images&#47;Po&#47;PopularWords&#47;Dashboard1&#47;1.png' /> <param name='animate_transition' value='yes' /><param name='display_static_image' value='yes' /><param name='display_spinner' value='yes' /><param name='display_overlay' value='yes' /><param name='display_count' value='yes' /><param name='showVizHome' value='no' /><param name='showTabs' value='y' /><param name='bootstrapWhenNotified' value='true' /></object></div>


References:

[1] Cuesta, Hector. Practical Data Analysis: Transform, Model, and Visualize Your Data through Hands-on Projects, Developed in Open Source Tools. Birmingham, UK: Packt, 2013. Print.  
[2] Perkins, Jacob. Python Text Processing with NTLK 2.0 Cookbook: Over 80 Practical Recipes for Using Python's NLTK Suite of Libraries to Maximize Your Natural Language Processing Capabilities. Birmingham: PACKT, 2010. Print.  
[3] Bird, Steven, Ewan Klein, and Edward Loper. Natural Language Processing with Python. Beijing: O'Reilly, 2009. Print.  
[4] Russel, Matthew A. Mining the Social Web: Data Mining Facebook, Twitter, Linkedin, Google , Github, and More. Sebastopol, CA: O'Reilly, 2014. Print.  