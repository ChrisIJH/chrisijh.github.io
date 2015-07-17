---
layout: level1default 
permalink: /reference/ref_datastructure_02/
---
<h1>Data Structure 02</h1>

<h2>Anagram Detection Example</h2>

<table>

<tr>
	<td>Checking each character</td>
	<td>$$O(n^2)$$</td>
</tr>
<tr>
	<td>Sort and Compare</td>
	<td>Sorting part will dominate the complexity. sorting usuall $$O(n^2)$$ or $$O(nlog{n})$$</td>
</tr>
<tr>
	<td>Brute Force</td>
	<td>Worst...$$O(2^n)$$</td>
</tr>
<tr>
	<td>Count and Compare</td>
	<td>$$O(n)$$</td>
</tr>

</table>

<div class="light">
<h3>Solution 1 </h3>
<p>Check s1 character with s2 one by one</p>
</div><!-- end of light -->

<div class="dark">
<h3>Solution 2 </h3>
<p>
<pre>
def sol2(s1, s2):
    alist1 = list(s1)
    alist2 = list(s2)
    
    alist1.sort()
    alist2.sort()
    
    pos=0
    matches=True
    while pos < len(s1) and matches:
        
        if alist1[pos] == alist2[pos]:
            pos = pos+1
        else:
            matches = false
            
    return matches

print(sol2('abdc', 'dbca'))
</pre>


</p>
</div>
<div class="light">
<h3>Solution 3 </h3>
<p>Generate all possible string from s1. then check if s2 is one of them.</p>
</div><!-- end of light-->

<div class="dark">
<h3>Solution 4 </h3>
<p>Count number of times each character occurs. Check each character's number of occurent is same or not.</p>

<pre>
def sol4(s1, s2):
    c1= [0]*26
    c2= [0]*26
    
    for i in range(len(s1)):
        position = ord(s1[i]) - ord('a')
        c1[position] = c1[position]+1
        
    for i in range(len(s2)):
        position = ord(s2[i]) - ord('a')
        c2[position] = c2[position]+1
        
    j=0
    stillOK = True
    while j<26 and stillOK:
       if c1[j] == c2[j]:
           j=j+1
       else:
           stillOK=False
    
    return stillOK

print sol4('apple', 'elppa')	
</pre>
</div><!-- end of dark-->


<div class="light">
<h2>Performance of built-in data structures</h2>


<h3>List</h3>

<p>The append is O(1).</p>
<p>The concatenation is O(k) where k is the size of the list that is being concatenated.</p>

<h4>Before compare</h4>
<pre><p>To use <strong>timeit</strong></p>
from timeit import Timer
a = Timer( "statement that you want to time", "statement that will run once to set up the test")
print a.timeit(number=1000)

unit is milliseconds 
</pre>



<h4>Now compare 4 method</h4>

<table>
	<tr>
		<td>
			<pre>[concatenation]
def t1():
	l=[]
	for i in range(1000):
		l=l+[i]
			</pre>
		</td>
		<td>
<pre>
a1 = Timer("t1()", "from __main__ import t1")
print "concat" , a1.timeit(number=1000), "milliseconds"

concat  1.05430388451 milliseconds
</pre>
		</td>
	</tr>
	<tr>
		<td>
			<pre>[append]
def t2():
	l=[]
	for i in range(1000):
		l.append(i)	
			</pre>
		</td>
		<td>

<pre>a2 = Timer("t2()", "from __main__ import t2")
print"append ",a2.timeit(number=1000), "milliseconds"

append  0.0739841461182 milliseconds
</pre>

		</td>
	</tr>
	<tr>
		<td>
			<pre>[comprehension]
def t3():
	l=[i for i in range(1000)]
			</pre>
		</td>
		<td>
<pre>a3 = Timer("t3()", "from __main__ import t3")
print"comprehension ",a3.timeit(number=1000), "milliseconds"

comprehension  0.0312428474426 milliseconds
</pre>
		</td>
	</tr>
	<tr>
		<td>
			<pre>[comprehension]
def t4():
	l=list(range(1000))
			</pre>
		</td>
		<td>
<pre>
a4 = Timer("test4()", "from __main__ import t")
print"list range ",a4.timeit(number=1000), "milliseconds"

list range  0.00769090652466 milliseconds
</pre>
		</td>
	</tr>
</table>

<p>Best is [list range], next [comprehension], then [append], the worst is [concatenation]</p>
</div><!-- light -->


<div class="dark">
<h3>Dictionary</h3>
<table>
	<tr>
		<td>
		copy 
		</td>
		<td>
		O(n)
		</td>
	</tr>
	<tr>
		<td>
		iteration
		</td>
		<td>
		O(n)
		</td>
	</tr>
	<tr>
		<td>
		get item
		</td>
		<td>
		O(1)
		</td>
	</tr>
	<tr>
		<td>
		set item
		</td>
		<td>
		O(1)
		</td>
	</tr>
	<tr>
		<td>
		delete item
		</td>
		<td>
		O(1)
		</td>
	</tr>
	<tr>
		<td>
		contains (in)
		</td>
		<td>
		O(1)
		</td>
	</tr>
</table>


</div> <!-- dark -->
