---
layout: level1default 
permalink: /reference/ref_re_01/
---


# Regular Expression 






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
import re

pat = [ 'first', 'second']
sent = 'What is first and second? what! *'

for p in pat:
   if re.search(p, sent):
      print "found"
   else:
      print "not found"
</code></pre>

<h5>Deal with return value</h5>
<pre><code>
import re

pat =  'first'
sent = 'What is first and second? what! *'

match = re.search(pat, sent)
s = <font color="red">match.start()</font>
e = <font color="red">match.end()</font>

print '"%s" is found in "%s" from index %d to %d ("%s")' % \
    (<font color="red">match.re.pattern</font>, <font color="red">match.string</font>, s, e, sent[s:e])
print "match.group(): " , <font color="red">match.group()</font>
</code></pre>

<p>output</p>
<pre><code> 
"first" is found in "What is first and second? what! *" from index 8 to 13 which is "first"

match.group():  first</code></pre>


<h5>Replace</h5>
<pre><code>
import re

pat =  'first'
sent = 'What is first and second? what! *'

<font color="red">match</font> = re.sub(pat, "1st", sent)

print <font color="red">match</font>

</code></pre>
<p>output</p>
<pre><code> 
What is 1st and second? what! *</code></pre>

<table>
  
  <tr>
    <td>\d</td>
    <td>[0-9]</td>
  </tr>
  <tr>
    <td>\D</td>
    <td>[^0-9]</td>
  </tr>
  <tr>
    <td>\s</td>
    <td>Any whitespace-> [ \t\n\r\f\v]</td>
  </tr>
  <tr>
    <td>\S </td>
    <td>Any non-whitespace-> [^ \t\n\r\f\v] </td>
  </tr>
  <tr>
    <td>\w</td>
    <td>Any alphanumeric-> [a-zA-Z0-9_]</td>
  </tr>
  <tr>
    <td>\W</td>
    <td>Any non-alphanumeric-> [^a-zA-Z0-9_]</td>
  </tr>
  <tr>
    <td>[s,.]</td>
    <td>Any whitespace or ',' or '.'</td>
  </tr>
  <tr>
    <td>[..]</td>
    <td>Anythin exceprt new line</td>
  </tr>
</table>

<h5>Repeating things</h5>

<table>
  
  <tr>
    <td>ca*t</td>
    <td>ct, cat, caaat, etc</td>
  </tr>
  <tr>
    <td>a[bcd]*b</td>
    <td>a + zero or more letter from [bcd] + b</td>
  </tr>
  <tr>
    <td>ca+t</td>
    <td>cat, caat, but won't match ct</td>
  </tr>
  <tr>
    <td>home-?brew </td>
    <td>homebrew or home-brew </td>
  </tr>
  <tr>
    <td>a/{1,3}b</td>
    <td>a/b, a//b, a///b, but won't match ab</td>
  </tr>
</table>

<h5>Compile</h5>

<pre><code>p = re.compile('ab*c')
p.search("Where is abc?")
print match.group()</code></pre>

<p>output</p>
<pre><code>abc</code></pre>


<h5>More Metacharacters</h5>

<table> 
  <tr>
    <td>a|b</td>
    <td>"or" operator. any string that matches either a or b</td>
  </tr>
  <tr>
    <td>^</td>
    <td>Matches at the beginning of lines.</td>
  </tr>
  <tr>
    <td>$</td>
    <td>Matches at the end of a line.</td>
  </tr>
  <tr>
    <td>\A </td>
    <td>Matches only at the start of the string. </td>
  </tr>
  <tr>
    <td>\Z</td>
    <td>Matches only at the end of the string.</td>
   <tr>
    <td>\b</td>
    <td>Word boundary, empty string at the beginning or end of a word</td>
   <tr>
    <td>\B</td>
    <td>empty string not at the beginning or end of a word</td>
  </tr>
</table>


<h5>Grouping</h5>

<p>Groups are marked by the '(', ')' metacharacters. (ab)* will match zero or more repetitions of ab.</p>

<pre><code>p = re.compile('(ab)*')
print p.match('ababababab').span()</code></pre>
<p>output</p>
(0,10)
<br>
<pre><code>p = re.compile('(a)b')
m = p.match('ab')
m.group()
</code></pre>
<p>output</p>
'ab'

<br>






