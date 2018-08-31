---
layout: level1default 
permalink: /reference/ref_mongodb_01/
---



<h1>MongoDB</h1>

<h2>Installation</h2>
<ol>
  
  <li><pre>sudo apt-get install -y mongodb-org</pre></li>
  <li>start MongoDB (if it didnt' start yet)<pre>sudo service mongod start</pre></li>
  <li>enable remote access from my server. Edit /etc/mongodb.conf <pre># Listen to local interface only. Comment out to listen on all interfaces. 
#bind_ip = 127.0.0.1</pre></li>
  <li><pre>$ sudo service mongod stop
mongod stop/waiting
$ sudo service mongod start
mongod start/running, process 14087</pre></li>
  <li></li>
</ol>

<div class="dark">
<h2>
Quick reference
</h2> 
<h3>1. Import exercise file</h3>
<p>https://docs.mongodb.org/getting-started/shell/import-data/</p>
<p>
https://raw.githubusercontent.com/mongodb/docs-assets/primer-dataset/dataset.json	
</p>
<p>save to a file named primer-dataset.json.</p>
<h3>2. dump to mongoDb</h3>
<p>Now, Import data into the collection from bash shell (not mongo shell)</p>
<p>db name: test</p>
<p>collection name: restaurants</p>
<p>if there is a same collection, drop it first</p>
<pre>
$ mongoimport --db test --collection restaurants --drop --file primer-dataset.json
</pre>

<h3>3. <strong>Insert</strong> in mongo shell</h3>
from the shell
<pre>
$ mongo
</pre>
Now, in the mongo shell
<pre>
use test

db.restaurants.insert(
   {
      "address" : {
         "street" : "2 Avenue",
         "zipcode" : "10075",
         "building" : "1480",
         "coord" : [ -73.9557413, 40.7720266 ],
      },
      "borough" : "Manhattan",
      "cuisine" : "Italian",
      "grades" : [
         {
            "date" : ISODate("2014-10-01T00:00:00Z"),
            "grade" : "A",
            "score" : 11
         },
         {
            "date" : ISODate("2014-01-16T00:00:00Z"),
            "grade" : "B",
            "score" : 17
         }
      ],
      "name" : "Vella",
      "restaurant_id" : "41704620"
   }
)
</pre>

<h3>4. <strong>Find</strong> in mongo shell</h3>

<pre>
db.restaurants.find( { "borough": "Manhattan" } )
</pre>
<pre>
db.restaurants.find( { "address.zipcode": "10075" } )
db.restaurants.find( { "grades.grade": "B" } )
</pre>
<pre>
db.restaurants.find( { "grades.score": { $gt: 30 } } )
db.restaurants.find( { "grades.score": { $lt: 10 } } )
db.restaurants.find( { "cuisine": "Italian", "address.zipcode": "10075" } )
db.restaurants.find(
   { $or: [ { "cuisine": "Italian" }, { "address.zipcode": "10075" } ] }
)
db.restaurants.find().sort( { "borough": 1, "address.zipcode": 1 } )
</pre>

<h4>Read Operation</h4>
<p><strong>db.collection.find()</strong> method from MongoDB shell, returns a cursor to the matching documents.</p>
<img src="https://www.evernote.com/l/AAld-yKZsaVMGL2RlwXVHd8y4kTb82szSMEB/image.png">

<h4>Cursor</h4>
<ul>
  <li>
The returned cursor must be assigned to a variable. Otherwise ti is automatically iterated up to 20 times. So, it shows the first 20 matching documents.</li>
  <li>Query results returned are in batches. Batch size will not exceed maximum BSON size. The rist batch returns 101 documnets or 1 megabyte. Subsequent batch size is 4 megabytes. (see batchSize() and limit())</li>
</ul>
    <pre>
var myCursor = db.inventory.find();

var myFirstDocument = myCursor.hasNext() ? myCursor.next() : null;

myCursor.objsLeftInBatch();
    </pre>
    <pre>var myCursor = db.inventory.find( { type: 'food' } );

while (myCursor.hasNext()) {
   print(tojson(myCursor.next()));
}   </pre>
<pre>var myCursor = db.inventory.find( { type: 'food' } );

while (myCursor.hasNext()) {
   printjson(myCursor.next());
}</pre> 
<p>The toArray() method loads into RAM all documents returned.</p>
<pre>var myCursor =  db.inventory.find( { type: 'food' } );

myCursor.forEach(printjson);</pre>
<pre>var myCursor = db.inventory.find( { type: 'food' } );
var documentArray = myCursor.toArray();
var myDocument = documentArray[3];</pre>
<pre>var myCursor = db.inventory.find( { type: 'food' } );
var myDocument = myCursor[3];
# The last line is same to the below:
myCursor.toArray()[3];</pre>

<h3>5. <strong>Update</strong> in mongo shell</h3>

<pre>
# first document matched. $currentDate operator is useful.
db.restaurants.update(
    { "name" : "Juni" },
    {
      $set: { "cuisine": "American (New)" },
      $currentDate: { "lastModified": true }
    }
)


db.restaurants.update(
  { "restaurant_id" : "41156888" },
  { $set: { "address.street": "East 31st Street" } }
)

# Multiple documents. This case will change ALL document matched.
db.restaurants.update(
  { "address.zipcode": "10016", cuisine: "Other" },
  {
    $set: { cuisine: "Category To Be Determined" },
    $currentDate: { "lastModified": true }
  },
  { multi: true}
)

# Replace a document
db.restaurants.update(
   { "restaurant_id" : "41704620" },
   {
     "name" : "Vella 2",
     "address" : {
              "coord" : [ -73.9557413, 40.7720266 ],
              "building" : "1480",
              "street" : "2 Avenue",
              "zipcode" : "10075"
     }
   }
)
</pre>

<h3>5. <strong>Remove</strong> in mongo shell</h3>
<pre>
# remove all document matched by default
db.restaurants.remove( { "borough": "Manhattan" } )

# remove only one document matched.
db.restaurants.remove( { "borough": "Queens" }, { justOne: true } )

# remove all docs
db.restaurants.remove( { } )

# drop a collection
db.restaurants.drop()

</pre>

<h3>6. <strong>Data Aggregation</strong> in mongo shell</h3>

<pre>
# Using group stage and $sum accumulator
db.restaurants.aggregate(
   [
     { $group: { "_id": "$borough", "count": { $sum: 1 } } }
   ]
);

# The result will be:
{ "_id" : "Staten Island", "count" : 969 }
{ "_id" : "Brooklyn", "count" : 6086 }
{ "_id" : "Manhattan", "count" : 10259 }
{ "_id" : "Queens", "count" : 5656 }
{ "_id" : "Bronx", "count" : 2338 }
{ "_id" : "Missing", "count" : 51 }

# Filter and Group docs
db.restaurants.aggregate(
   [
     { $match: { "borough": "Queens", "cuisine": "Brazilian" } },
     { $group: { "_id": "$address.zipcode" , "count": { $sum: 1 } } }
   ]
);

# The result will be:
{ "_id" : "11368", "count" : 1 }
{ "_id" : "11106", "count" : 3 }
{ "_id" : "11377", "count" : 1 }
{ "_id" : "11103", "count" : 1 }
{ "_id" : "11101", "count" : 2 }
</pre>


<h3>7. <strong>Indexs</strong> with the mongo shell</h3>

<pre>
# Index on "cuisine" field.
db.restaurants.createIndex( { "cuisine": 1 } )


# Create a compound index.
db.restaurants.createIndex( { "cuisine": 1, "address.zipcode": -1 } )
</pre>

</div><!-- dark -->

<div class="light">

<h2>MongoDB-php driver</h2>

<h3>In shared-hoting</h3>
<img src="https://www.evernote.com/l/AAkX9EWoWjROyI_OD4b-EDUAClablnmw3cgB/image.png">
<p>Download php.ini and put it in "~/www", then check phpinfo.() again, Loaded configuration file</p>


</div> <!-- light -->

<div class="dark">
<h2>MongoDB project plan</h2>

<div class="piktowrapper-embed" pikto-uid="7080165-mongodb_notable01" >
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


<h3>1. MongoDB remote access enable</h3>

<ol>
	<li>
		<p>Check mongeDB setting</p>
		<p>In /etc/mongod.conf </p>
		<pre>
bind_ip= 127.0.0.1 , mongoDB's private ip , mongoDB's public ip 
#caution: no space between comma
		</pre>
		if you got this error,

	</li>

	<li>Then, restart the service
		<pre>
sudo service mongod stop
sudo service mongod start
		</pre>

	</li>Then, check the log
		<pre>
tail -f /var/log/mongodb/mongod.log 
		</pre>
		It should shows <pre>I NETWORK  [initandlisten] waiting for connections on port 27017</pre>
	<li>If error occurs, comment out the <strong>bind_ip</strong> above. Let aws handle the incoming security. At AWS server, make sure security has open to port 27017, 28017.
	</li>
</ol>

<h3>Examples with mongo shell</h3>
<pre>
use nota

db.mstudents.insert(
    {
        "name": {
            "first":"Finst",
            "last" :"goodstud",
        },
        "sql_id": 143294,
        "username":"Finst"
    }
 )
    
db.mstudents.insert(
    {
        "name": {
            "first":"Kimmer",
            "last" :"Goods",
        },
        "sql_id": 143295,
        "username":"Kimmer"
    }  
)

#### Multiple documents --> use array.
db.mstudents.insert(
  [
    {
        "name": {
            "first":"Finst",
            "last" :"goodstud",
        },
        "sql_id": 143294,
        "username":"Finst"
    },
    {
        "name": {
            "first":"Kimmer",
            "last" :"Goods",
        },
        "sql_id": 143295,
        "username":"Kimmer"
    }
  ]  
)

    
db.mstudents.find({"sql_id": 143295 })
 
#### Add new fields. 
db.mstudents.update(
    {"sql_id": 143295},
    {
        $set: { "temp": "temp_value" },
        $currentDate: { "lastModified": true }
    }
)

#### Remove fields one by one.
db.mstudents.update(
    {"sql_id": 143295},
    {
        $unset: { "temp": "" }
    }
)
    
db.mstudents.update(
    {"sql_id": 143295},
    {
        $unset: { "lastModified":""}
    }
)

</pre>
</div> <!-- dark -->

