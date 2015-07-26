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
