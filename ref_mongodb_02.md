---
layout: level1default 
permalink: /reference/ref_mongodb_02/
---


# Data Model

<h2>Normalized vs Embeded Data Models</h2>

<div class="piktowrapper-embed" pikto-uid="7097638-mongodb_datamodel" >
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

<h2>MongoGridFS</h2>

<ul>
<li>Utilities for storing and retrieving files from the database.</li>
<li>It defines two collections: files (for file metadata) and chunks (for file content).</li>
    <li>Automatically split file into smaller chuncks --> saved as a document in the chunks collection.</li>
    <li>Each doc contains filename, upload date, and md5 hash, and _id field.</li>
    <li>MongoGridFS extends MongoCollection, and an instance of MongoGridFS has accenss to all of MongoCollection methods.</li>

</ul>

<div class="dark">
<h3>To MongoDB</h3>
<h4>Example</h4>
<pre>
$m = new MongoClient("mongodb://ipaddress");
$db = $m->mydb;

$grid = $db->getGridFS();

$name = $_FILES['file_upload']['name']; // the name of the uploades file
$id = $grid->storeUpload('Filedata', $name);
</pre>
<h4>Example</h4>

<pre><xmp>
<?php
if(isset($_POST['submit'])) {
    $m = new MongoClient("mongodb://ipaddress");
    $gridfs = $m->selectDB('test')->getGridFS();

    $input =  array('sql_id' => 143294 , 'question_id' => 900, 'filetype'=> 'image');
    $gridfs->storeUpload('pic', $input);
}
?>

<form method="POST" enctype="multipart/form-data" action='test.php'>
    <label for="username">Username:</label>
    <input type="text" name="username" id="username" />

    <label for="pic">Please upload a profile picture:</label>
    <input type="file" name="pic" id="pic" />

    <input type="submit" name="submit" />
</form>
</xmp></pre>

<p>Result at MongoDB</p>

<img src="https://www.evernote.com/l/AAkdEcHUiThCN4jWhJITzRvr_3XCdwTa4IQB/image.png">

<p>This makes normalized data which can be accessed by the additional information put when uploading.</p>

</div> <!-- dark -->

<div class="light">
<h3>From MongoDB</h3>

</div> <!-- light -->


<div class="dark">

<h3>Authentication</h3>
<p>http://docs.mongodb.org/master/MongoDB-security-guide.pdf</p>

<ol>
    <li>Start without authentication.
    <pre>$ sudo service mongod start</pre>
    Check if it started correctly.
    <pre>2015-07-27T21:12:20.253+0000 D INDEX    [initandlisten] checking complete
2015-07-27T21:12:20.253+0000 I NETWORK  [initandlisten] waiting for connections on port 27017
2015-07-27T21:12:20.253+0000 D COMMAND  [PeriodicTaskRunner] BackgroundJob starting: PeriodicTaskRunner
2015-07-27T21:12:20.253+0000 D COMMAND  [ClientCursorMonitor] BackgroundJob starting: ClientCursorMonitor
2015-07-27T21:12:20.253+0000 D COMMAND  [TTLMonitor] BackgroundJob starting: TTLMonitor
2015-07-27T21:13:20.227+0000 I STORAGE  [DataFileSync] flushing mmaps took 0ms  for 8 files</pre></li>
    <li>Create Adminisgtrative  user first. (initially under localexception) The following operations will create two users: <mark>a user administrator</mark> that will be able to create and modify users (siteUserAdmin), and <mark>a root user (siteRootAdmin)</mark> that you will use to complete the remainder of the tutorial

        <pre>
mongo
> use admin
> db.createUser( {
    user: "siteUserAdmin",
    pwd: "password",
    roles: [ { role: "userAdminAnyDatabase", db: "admin" } ]
  });
  Successfully added user: {
    "user" : "siteUserAdmin",
    "roles" : [
        {
            "role" : "userAdminAnyDatabase",
            "db" : "admin"
        }
    ]
}
</pre>
        <pre>db.createUser( {
    user: "siteRootAdmin",
    pwd: "password",
    roles: [ { role: "root", db: "admin" } ]
});
Successfully added user: {
    "user" : "siteRootAdmin",
    "roles" : [
        {
            "role" : "root",
            "db" : "admin"
        }
    ]
}
</pre>
    </li>
    <li>stop the mongod instance
    </li> 
    <li>Create the key file to be used by each member of the replica set. To generate pseudo-random data to use for a keyfile, issue the following openssl command:
<pre>openssl rand -base64 741 > mongodb-keyfile
chmod 600 mongodb-keyfile</pre>
You may generate a key file using any method you choose. Always ensure that the password stored in the key file is both long and contains a high amount of entropy. Using openssl in this manner helps generate such a key.</li>  
    <li>Start the mongoDB with security key:
    First, edit /etc/mongod.conf.
    <pre># path to a key file storing authentication info for connections
# between replica set members
keyFile=/home/ubuntu/.ssh/mongodb-keyfile
</pre>
    <pre>$ sudo mongod --config /etc/mongod.conf &</pre></li>
    Check if it started correctly.    
<pre> I CONTROL  [initandlisten] allocator: tcmalloc
 I CONTROL  [initandlisten] options: { config: "/etc/mongod.conf", security: { keyFile: "/home/ubuntu/.ssh/mongodb-keyfile" }, storage: { dbPath: "/var/lib/mongodb" }, systemLog: { destination: "file", logAppend: true, path: "/var/log/mongodb/mongod.log" } }
 I NETWORK  [initandlisten] waiting for connections on port 27017</pre>
    <li>Create user for specific database.
<pre>
    <li>connect to mongo shell<pre>$ mongo --port 27017 -u siteUserAdmin -p password --authenticationDatabase admin</pre></li>

use nota
db.createUser( { user: "jinna", pwd: "password", roles: [ {role: "readWrite", db: "nota"} ]}  ) </pre></li>

    
</ol>

</div> <!-- dark -->


