---
layout: level1default 
permalink: /reference/ref_linux_01/
---


# Linux Command Quick Reference


<div class="light">
<h2>find</h2>
find is inherently recursive and is intended to descent through directories looking for files with certain attributes or executing commands.


cf) -type f --> plain file; 	d --> directory p --> fifo or named pipe
1.) Find all files modified between 50 ~ 100 days

<pre><code>
	find . -mtime +50 -mtime -100
</code></pre>

2.) Find all files permission 777  

<pre><code>
	find . -type f -perm 0777
</code></pre>

3.) Find all read-only file

<pre><code>
	find . -perm /u=r
</code></pre>


4.) Find all excutable file

<pre><code>
	find . -perm /a=x
</code></pre>

5.) Find all empty file
<pre><code>
	find . -type f -empty
</code></pre>

6.) Find all files basedon user
<pre><code>
	find . -user "username"
</code></pre>

7.) Find all c files then change mode 
<pre><code>find . -name "*.c" -exec chmod g+w {} \;</code></pre>
</div>
<hr>
<hr>
<div class="dark">

<h2>grep</h2>

<strong>
grep [options] pattern [files]
</strong>


-c 		::count. With -v, count nonmatching lines  
-d 	read ::read directories like ordinary files (default)
	skip ::skip directories
	recurse:: recursively ... same as -r  

examples:

1.)
<pre><code>$ cat a
this is line 1 UNIX UNIX
this is line 2 unix
this is line 3 Unix Unix
this is line 4 hello
</code></pre>

2.)
<pre><code>$ grep unix a
this is line 2 unix
</code></pre>

<pre><code>$ grep -c -a unix a
1
</code></pre>

3.)Ignore upper and lower case

<pre><code>$ grep -i unix a
this is line 1 UNIX UNIX
this is line 2 unix
this is line 3 Unix Unix
</code></pre>

4.)Add line number  
<pre><code>$ grep -i -n unix a
1:this is line 1 UNIX UNIX
2:this is line 2 unix
3:this is line 3 Unix Unix
</code></pre>

<pre><code>$ grep -i -n hello a
4:this is line 4 hello
</code></pre>

5.)Print only patter parts

<pre><code>$ grep -o unix a
unix
</code></pre>

<pre><code>$ grep -oi unix a
UNIX
UNIX
unix
Unix
Unix
</code></pre>

6.)Print lines not containing patterns

<pre><code>$ grep -vin unix a
4:this is line 4 hello
</code></pre>

7.)Search file for multiple patterns or for pattern beginning with hyphen

<pre><code>grep -n -e unix -e hello a
2:this is line 2 unix
4:this is line 4 hello
</code></pre>

8.)Multiple files

<pre><code>$ cat a
this is line 1 UNIX UNIX
this is line 2 unix
this is line 3 Unix Unix
this is line 4 hello
</code></pre>
<pre><code>$ cat b
this is line 1 hello
this is line 2 Unix
this is line 3 UNIX UNIX
this is line 4 unix unix
</code></pre>

<pre><code>$ grep -in unix a b
a:1:this is line 1 UNIX UNIX
a:2:this is line 2 unix
a:3:this is line 3 Unix Unix
b:2:this is line 2 Unix
b:3:this is line 3 UNIX UNIX
b:4:this is line 4 unix unix
</code></pre>

<pre><code>$ find .
.
./a
./b
$ grep -r unix .
./a:this is line 2 unix
./b:this is line 4 unix unix

</code></pre>
Print 3 lines before, 2 lines after term "unix".
<pre>
$ grep -B 3 -A 2 unix .
</pre>
</div>

<hr>
<hr>

<div class="light">
## Serching pattern


<table class="table table-striped">
    <thead>
      <tr>
        <th>What it does</th>
        <th>Pattern</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td>The string <small>bag</small></td>
        <td>bag</td>
      </tr>
      <tr>
        <td>"bag" at the begining of line or string.</td>
        <td>^bag</td>
      </tr>
      <tr>
        <td>"bag" at the end of line or string.</td>
        <td>bag$</td>
      </tr>
      <tr>
        <td>"bag" as the only text on line</td>
        <td>^bag$</td>
      </tr>
      <tr>
        <td>"Bag" or "bag"</td>
        <td>[Bb]ag</td>
      </tr>
      <tr>
        <td>Second character is vowel</td>
        <td>b[aeiou]g</td>
      </tr>
      <tr>
        <td>Second character is NOT vowel</td>
        <td>b[^aeiou]g</td>
      </tr>
      <tr>
        <td>Second character is any character except new line</td>
        <td>b.g</td>
 	  </tr>
 	  <tr>
 	  	<td>Any line containing exactly three characters.</td>
 	  	<td>^...$</td>
 	  </tr>
 	  <tr>
 	  	<td>Any line that begins with a dot</td>
 	  	<td>^\.</td>
 	  </tr>
 	  <tr>
 	  	<td>Any line that doesn't begin with a dot</td>
 	  	<td>^[^.]</td>
 	  </tr>
 	  <tr>
 	  	<td>"bug", "bugs", "bugss", etc</td>
 	  	<td>bugs*</td>
 	  </tr>
 	  <tr>
 	  	<td>A word in quotes</td>
 	  	<td>"word"</td>
 	  </tr>
 	  <tr>
 	  	<td>A word, with or without quotes</td>
 	  	<td>"*word"*</td>
 	  </tr>
 	  <tr>
 	  	<td>One or more uppercase letters</td>
 	  	<td>[A-Z][A-Z]*</td>
 	  </tr>
 	  <tr>
 	  	<td>An uppercase letter, followed by zero or more characters</td>
 	  	<td>[A-Z].*</td>
 	  </tr>
 	  <tr>
 	  	<td>Zero or more uppercase letters.</td>
 	  	<td>[A-Z]*</td>
 	  </tr>
 	  <tr>
 	  	<td>Any letter.</td>
 	  	<td>[a-zA-Z]</td>
 	  </tr>
 	  <tr>
 	  	<td>Any alphanumeric sequence</td>
 	  	<td>[0-9A-Za-z]+</td>
 	  </tr>
    </tbody>
</table>
</div>

<div class="dark">

<h1>Showing large files</h1>

1.) Using head and tail command
default : read 10 lines
<pre><code>$ cat a
this is line 1 UNIX UNIX
this is line 2 unix
this is line 3 Unix Unix
this is line 4 hello
</code></pre>

<pre><code>$ head -n 2 a
this is line 1 UNIX UNIX
this is line 2 unix
</code></pre>

<pre><code>$ head -n +2 a
this is line 1 UNIX UNIX
this is line 2 unix
</code></pre>

read last 2 lines
<pre><code>$ tail -n 2 a
this is line 3 Unix Unix
this is line 4 hello
</code></pre>

read from 2nd line to last
<pre><code>$ tail -n +2 a
this is line 2 unix
this is line 3 Unix Unix
this is line 4 hello
</code></pre>

read 3rd line only
<pre><code>$ tail -n +3 a | head -n 1 
this is line 3 Unix Unix
</code></pre>

2.)Using "cut"  
<br>
[options] <br>
+ -d --> delimiter, special character should be quoted " ". with -f1 --> 1st column <br>
+ -c --> print characters in list columns  
<br>

<pre><code>$ cat a
this is line 1 UNIX UNIX
this is line 2 unix
this is line 3 Unix Unix
this is line 4 hello
</code></pre>


<pre><code>$ cut -c 1 a
t
t
t
t</code></pre>


<pre><code>$ cut -c 1,4 a
ts
ts
ts
ts</code></pre>

<pre><code>$ cut -c 1-4 a
this
this
this
this
</code></pre>
<pre><code>$ cut -d" " -f1 a
this
this
this
this
</code></pre>

3.)Using sed<br>  

Read 2nd and 4th line
<pre><code>$ sed -n -e 2p -e 4p a
this is line 2 unix
this is line 4 hello
</code></pre>

Read 2nd to 4th line
<pre><code>$ sed -n 2,4p a
this is line 2 unix
this is line 3 Unix Unix
this is line 4 hello
</code></pre>

</div> <!-- end of dark -->


<div class="light">

<h2>sed</h2>

<h3>Syntax</h3>

<quotes>
sed [options] 'command' file(s)
sed [options] -f scriptfile file(s)
</quotes>


From lynda
<quotes>
sed 's/a/d'
</quotes>

<p>s: substitution</p>
<p>a: search string</p>
<p>b: replacement string</p>

ex)

<pre>$ echo 'upstarem' | sed 's/up/down/'
downstarem</pre>

<pre>$ cat a | sed 's/is/are/'
thare is line 1 UNIX UNIX
thare is line 2 unix
thare is line 3 Unix Unix
thare is line 4 hello</pre>
That is, it is not global default. 'g' should be added. However, remember that each line is a stream. So, 'is' in each stream (line) is changed not second one.

<pre>$ cat a | sed 's/is/are/g'
thare are line 1 UNIX UNIX
thare are line 2 unix
thare are line 3 Unix Unix
thare are line 4 hello</pre>

<pre>$ cat a | sed -e 's/this/that/g' -e 's/is/are/g' -e 's/line/line number/g'
that are line number 1 UNIX UNIX
that are line number 2 unix
that are line number 3 Unix Unix
that are line number 4 hello
</pre>



<h4>options</h4>
<ul>
  <li>-n  Suppress the default output</li>
  <li>-e  editing command are followed. </li>
</ul>

<h4>commands</h4>
<p>[address [,address]][!]command[arguments]</p>

<ul>
  <li>a\  Append text after a line</li>
  <li>c\  Replace text(usually text block)</li>
  <li>i\  Insert text before a line.</li>
  <li>d   Delete lines.</li>
  <li>s   Make substitutions</li>
  <li>y   Translate characters </li>

</ul>
</div><!-- end of light -->






