---
layout: level1default 
permalink: /reference/ref_datastructure_03/
---

<h1>Basic Datra Structures</h1>


<h2>Stack</h2>

<h2>Queue</h2>

<h2>Deque</h2>

<h2>List</h2>


<h1>Recursion</h1>

<p>Recursion is a method to solve a complex problem by breaking it down to smaller and smaller subproblems until uyou get to a samll enough problem that it can be solved trivially.</p>


<h4>example 1: Sum of list</h4>

<pre>
    def listsum(l):
        if len(l) == 1:
            return l[0]
        else:
            return l[0] + listsum( l[1:])
</pre>



<h4>example 2: Converting an integer to string </h4>
<img src="https://www.evernote.com/l/AAmECknYL81BGok8tof0zLVHbVMkn3ISXlcB/image.png"> 
<pre>
	def toStr(i, base):
	    if i//base == 0:
	        return str(i)
	    else:
	        return toStr(i//base, base) + str(i%base)
</pre>


<h4>example 3: Tower of Hanoi </h4>

<p>Things to consider: think about the final version</p>
<ul>
	<li>function 1 --> movetower(height, start, end, middle) </li>
	<li>function 2 --> movedisk(from, to)</li>
	<li>basecondition : height of tower</li>	
</ul>
<img src="https://www.evernote.com/l/AAmnGaX5zw9CY7rf5Kur8WYfqTJSgDGhD7oB/image.png">
<p>Algorithm <small>n: height of tower</small></p>
<ul>
	<li>Move a tower of n-1 to middle using the final pole</li>
	<li>Move the remaining disk to the final pole</li>
	<li>Move the tower of n-1 from the middle to the final using start pole</li>
</ul>
<pre>
def moveAll(n, pole1, pole3, pole2):
    if n >= 1:
        moveAll(n-1, pole1, pole2, pole3)
        moveDk(pole1, pole3)
        moveAll(n-1, pole2, pole3, pole1)
    else:
        pass
        
def moveDk(fromP, toP):
    print 'Moving disk from ', fromP, ' to ', toP
</pre>

<p>Output</p>
<pre>
moveAll(3, 'a', 'b', 'c')
Moving disk from  a  to  b
Moving disk from  a  to  c
Moving disk from  b  to  c
Moving disk from  a  to  b
Moving disk from  c  to  a
Moving disk from  c  to  b
Moving disk from  a  to  b
</pre>





