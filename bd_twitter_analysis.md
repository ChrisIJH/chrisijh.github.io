---
layout: level1default
permalink: /bigdata/twitter-analysis/
---

Introduction
------------

**_Twitter_** 

[1]: http://spark.apache.org
[2]: http://spark.apache.org/docs/1.0.2/api/python/index.html
[3]: https://cloud.google.com
[4]: https://hadoop.apache.org


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



## Data Procedure
0. Twitter Data acquired pre process before MongoDB

        # Last line can be not done correctly if it was taken in the middle of receiving twitter stream. So, remove the last line.
        head -n -1 pre.json > test.json
        

1. Actuired data go to MongoDB

    
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

    2.a. Spark

        data_raw = sc.parallelize(tobe_parallelized)

3. Data Cleaning

        def split_lines(docs):
            result = []
            for line in docs:
                a = line.split()
                result.append(a)
            return result

        def to_lowr(docs):
            i=0
            for words in docs:
                docs[i] = [w.lower() for w in words]
                i +=1

        # sample
        [u'Novel writing tips- Eric J Gates http://t.co/Doz5HUxSlS',
         u'Bitches love writing r.i.p \U0001f629\U0001f629\U0001f629 they jus want act like they kno ppl',
         u"Anchorage AK - Tutor or Teacher - Elementary K-6th - I'm interested in finding a tutor for my son who will be ... http://t.co/lxIJSguo9m"]

        def elim_url(line):
            for lstOfWords in tmp:
                i=0
                for word in lstOfWords:
                    if word.find("http")!= -1:
                        lstOfWords.pop(i)
                        # since one is popped, need to maintain i as same as before
                    else:
                        i +=1

        # sample
        [ [u'Novel', u'writing', u'tips-', u'Eric', u'J', u'Gates'],
          [u'Bitches',
          u'love',
          u'writing',
          u'r.i.p',
          u'\U0001f629\U0001f629\U0001f629',
          u'they',
          u'jus',
          u'want',
          u'act',
          u'like',
          u'they',
          u'kno',
          u'ppl'] ]

        def elim_at(line):
            for lstOfWords in line:
                i=0
                for word in lstOfWords:
                    if word.startswith("@"):
                        lstOfWords.pop(i)
                    i +=1

        def elim_hash(line):
            for lstOfWords in line:
                i=0
                for word in lstOfWords:
                    if word.startswith("#"):
                        lstOfWords.pop(i)
                        # since one is popped, need to maintain i as same as before
                    else:
                        i +=1

        def find_not(docs):
            # Apostrophe
            i=0
            for listOfWords in docs:
                docs[i] = [ "not" if word.find("'t")!=-1 else word for word in listOfWords]
                i += 1


        def stop_word(doc):
            stopset = set(nltk.corpus.stopwords.words('english'))
            filter_stops = lambda a: len(a) < 3 or a in stopset
            for lstOfWords in doc:
                for word in lstOfWords:
                    if filter_stops(word):
                        lstOfWords.remove(word)

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
It is much easier to have one flat string list at least for this example.  

    total=[]
    for lstOfWords in tmp:
        for word in lstOfWords:
            total.append(word)

    t_data = sc.parallelize(total).cache()

Now, Use apply map and reduce to Spark RDD.

    counts_map = t_data.map(lambda word: (word, 1)).reduceByKey(lambda a, b: a+b)
    count_map_rev = counts_map.map(lambda (x,y): (y,x))

## Visualization
Using D3.js, write the result to output.csv file. 

    top_50 = count_map_rev.top(50)
    with open("output.csv", "w") as f:
    for line in top_50:
        s = str(line) + '\n'
        f.write(s)


References:

[1] Cuesta, Hector. Practical Data Analysis: Transform, Model, and Visualize Your Data through Hands-on Projects, Developed in Open Source Tools. Birmingham, UK: Packt, 2013. Print.  
[2] Perkins, Jacob. Python Text Processing with NTLK 2.0 Cookbook: Over 80 Practical Recipes for Using Python's NLTK Suite of Libraries to Maximize Your Natural Language Processing Capabilities. Birmingham: PACKT, 2010. Print.  
[3] Bird, Steven, Ewan Klein, and Edward Loper. Natural Language Processing with Python. Beijing: O'Reilly, 2009. Print.  
[4] Russel, Matthew A. Mining the Social Web: Data Mining Facebook, Twitter, Linkedin, Google , Github, and More. Sebastopol, CA: O'Reilly, 2014. Print.  