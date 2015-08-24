---
layout: level1default
permalink: /bigdata/data-cleaning/
---

Introduction
------------

## Data Clean
<div class="piktowrapper-embed" pikto-uid="6835991-data_clean" >
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

<h2>Removing Punctuation</h2>

<h4>string.translate(s, table[, deletechars])</h4>
<p><strong>Delete</strong> all characters <strong>from s</strong> that are <strong>in deletechars</strong>, then translate the characters using table, which must be a 256-character string giving the translation for each character value, indexed by its ordinal. If table is None, then only the character deletion step is performed.</p>
<h4>string.maketrans(from, to)</h4>
<p>Return a translation <strong>table</strong> for passing to translate(), that will map each character in from into the character at the same position in to; from and to must have the same length.</p>

<p>Example 1:</p>
<pre><code>
import string
table1 = string.maketrans('xyz', 'abc')
sample = "x and y and z can be abc."
sample.translate(table1)
</code></pre>
<p>output:<br>
a and b and c can be abc.</p>


<p>Example 2:</p>
<pre><code>
import string

def removePunct(text):
    tbl = string.maketrans("","")
    out = text.translate(tbl, string.punctuation)
    out = out.strip()
    out = out.lower()
    return out
</code></pre>


## 



References:

[1] Cuesta, Hector. Practical Data Analysis: Transform, Model, and Visualize Your Data through Hands-on Projects, Developed in Open Source Tools. Birmingham, UK: Packt, 2013. Print.  
[2] Perkins, Jacob. Python Text Processing with NTLK 2.0 Cookbook: Over 80 Practical Recipes for Using Python's NLTK Suite of Libraries to Maximize Your Natural Language Processing Capabilities. Birmingham: PACKT, 2010. Print.  
[3] Bird, Steven, Ewan Klein, and Edward Loper. Natural Language Processing with Python. Beijing: O'Reilly, 2009. Print.  
[4] Russel, Matthew A. Mining the Social Web: Data Mining Facebook, Twitter, Linkedin, Google , Github, and More. Sebastopol, CA: O'Reilly, 2014. Print.  