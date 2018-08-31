---
layout: level1default 
permalink: /reference/ref_datastructure_01/
---

<h1>Python</h1>

<div>
<h2>Built-in Atomic Data Types.</h2> <br>
<ul>
<li>2**10 = 1024</li>  
<li>6/3 = 2.0</li>
<li>7/3 = 2.33333333  </li>
<li>7//3 = 2  </li>
<li>7%3 = 1  </li>
<li>3/6 = 0.5  </li>
<li>3%6 = 3  </li> 

<li>True   </li> 
<li>False  </li>  

<li>and, or , not  </li>  
</ul>
</div>

<div>
<h3>Built-in Collection Data Types.</h3> <br>

<h4><strong>List</strong></h4>

Methods Provided by Lists in Python


<table class="table table-striped">
    <thead>
      <tr>
        <th>What it does</th>
        <th>Use</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td>Adds a new item to the end of a list</td>
        <td>mylist.append(item)</td>
      </tr>
      <tr>
        <td>Inserts an item at the ith position in a list</td>
        <td>mylist.insert(i, item)</td>
      </tr>
      <tr>
        <td>Removes and returns the last item in a list</td>
        <td>mylist.pop()</td> </tr>
      <tr>
        <td>Removes and return the ith item in a list</td>
        <td>mylist.pop(i)</td>
      </tr>
      <tr>
        <td>Modifies a list to be sorted</td>
        <td>mylist.sort()</td>
      </tr>
       <tr>
        <td>Reverse order</td>
        <td>mylist.reverse()</td>
      </tr>
      <tr>
        <td>Delete ith one</td>
        <td>del mylist[i]</td>
      </tr>
      <tr>
        <td>Returns the index of the first occurrence of item</td>
        <td>mylist.index(item)</td>
      </tr>
      <tr>
        <td>Returns the number of occurences of item</td>
        <td>mylist.count(item)</td>
      </tr>
      <tr>
        <td>Removes the first occurence of item</td>
        <td>mylist.remove(item)</td>
      </tr>
    </tbody>
</table>

<h4><strong>String</strong></h4>
One difference between list and string is that string is not mutable.

<br>
<h4><strong>Tuple</strong></h4>
myTuple = (1, True, 0.83)

<br>
<h4><strong>Set</strong></h4>
<br>
<h4><strong>Dictionary</strong></h4>

key in mydict  : Returns True if key is in the dictionary.
del mydict[key] : Removes the entry from the dictionary

<table class="table table-striped">
    <thead>
      <tr>
        <th>What it does</th>
        <th>Use</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td>Rerturns the keys of the dict.</td>
        <td>mydict.keys()</td>
      </tr>
      <tr>
        <td>Returns the values of the dict</td>
        <td>mydict.values()</td>
      </tr>
      <tr>
        <td>Returns the key-value pairs</td>
        <td>mydict.items()</td>
      </tr>
      <tr>
        <td>Returns the value associated with k, None otherwise</td>
        <td>mydict.get(k)</td>
      </tr>
      <tr>
        <td>Returns the value associated with k, alt otherwise</td>
        <td>mydict.get(k, alt)</td>
      </tr>
    
    </tbody>

</table>


<h4>List Comprehension</h4>

<pre>
mylist = [ x*x for x in range(1,11) ]
[1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
</pre>
<pre>
mylist = [ x*x for x in range(1,11) if x%2 != 0]
[1, 9, 25, 49, 81]
</pre>
<pre>
[ch.upper() for ch in 'comprehension' if ch not in 'aeiou']
['C', 'M', 'P', 'R', 'H', 'N', 'S', 'N']
</pre>


<h4>Exception handling</h4>

<pre>a = int(input("Please enter an integer"))
try:
    print(math.sqrt(a))
except:
    print("Bad value for square root")
    print("Using absolute value instead")
    print(math.sqrt(abs(a)))</pre>
Output
<pre>Please enter an integer : -23
Bad value for square root
Using absolute value instead
4.79583152331</pre>

<div class="light">
<h3>Class</h3>

<p>The constructor method is always called __init__. "self" is a special parameter that will always be used as a reference back to the object itself. It must always be the first formal parameter.</p>

<pre>
class Fraction:
	__init__(self, top, bottom):
		self.num = top
		self.den = bottom
</pre>

Create an instance by invoking the constructor.

<pre>
myfraction = Fraction(2,9)
print(myfraction)
<__main__.Fraction instance at 0x1047c3a28>
</pre>
<p>
If we print the instance, it will show the above information which is a reference to object. Because print function requires that the object converts itself to a string, it will just show the reference.</p>
<p>There are 2 ways to do this.</p>
<p>1.) Create custom method.


<pre>class Fraction:

    def __init__(self,top,bottom):

        self.num = top
        self.den = bottom
        
    def show(self):
        print self.num,"/",self.den 

myfraction = Fraction(2,9)
myfraction.show()</pre>
<pre>2 / 9</pre>
<pre>print(myfraction)</pre>
<pre><__main__.Fraction instance at 0x1047c7830></pre>
<p>In general, ths does not work.</p>
<p>In order to make printing work properly, we need to override __str__ function which is one of the standard methods provided by python.</p>

<pre>class Fraction:

    def __init__(self,top,bottom):

        self.num = top
        self.den = bottom
        
    def __str__(self):
        return str(self.num)+ '/' + str(self.den)</pre>

<pre>myfraction = Fraction(2,9)
print(myfraction)</pre>

<pre>2/9</pre>

<p>Same way, __add__ for addition ( myfaction + myfraction ), __eq__ for deep equality</p>

</div> <!-- end of ligth -->


