---
layout: level1default 
permalink: /reference/ref_matrix_01/
---


# Matrix in python






Introduction
============

The `re` module was added in Python 1.5, and provides Perl-style regular
expression patterns.  The earlier version, `regex` module was
removed completely in Python 2.5.


<h4>Match, Search, and more</h4>
<p>`match()` checks for a match only at the beginning of the string.</p>
<p>`search()` checks for a match anywhere of the string.</p>
<p>`findall()` find all substrings where the RE matches, and return them as a list</p>
<p>`finditer()` find all substrings where the RE matches, and return them as an iterator</p>



<pre><code>
import re

pat = [ 'first', 'second']
sent = 'What is first and second? what! *'

match = <font color="red">re.search(pat[0], sent)</font>
if match:
   print "found"
else:
   print "not found"
</code></pre>

<pre><code>
