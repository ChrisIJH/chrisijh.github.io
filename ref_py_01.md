---
layout: level1default 
permalink: /reference/ref_py_01/
---

<h1>Python 01</h1>

<h2>Generator</h2>
<p>Generator can provide a simpler alternative to manually saving the state between iterations in class objects. Same as normal function except it uses <strong class="mark">'yield'</strong> not 'return' by wwreturning results one at a time. It is suspending and resuming their state between each. It is one-shot iteration just like __iter__(). It saves memory by slicing the job. Use it when dealing with large data sets. It is slightly slower than list comprehension.</p>
<h3>Generator Function</h3>

<h5>a.next() and next(a)</h5>
<pre><code>
def A(n):
    for i in range(n):
        yield i
a = A(3)
a
# <generator object A at 0x1042aafa0>
a.next()
# 0
a.next()
# 1
a.next()
# 2
a.next()
# StopIteration 

-----
b=A(3)
next(b)
# 0 
next(b)
# 1
next(b)
# 2
next(b)
# StopIteration 
</code></pre>

<h5>send(number)</h5>
<p>Useful when caller wants to terminate by seding termination code or redirect by passing a new position in data being processed inside the genrator.</p>
<pre><code>
def D():
    for i in range(5):
        X = yield i
        print(X)
d=D()
d
# <generator object D at 0x10477c7d0>
next(d)
# 0
d.send(10)
# 10
# 1
d.send(21)
# 21
# 2
</code></pre>

<h3>Generator Expressions</h3>

<p>Same as list comprehension except using '( )' instead of '[ ]'. List comprehension creates the result list in memory. But generator returns a generator object - an automatically created iterable.</p>
<pre><code>
[x for x in range(2)] # simple list comprehension
# [0, 1]
(x for x in range(2)) # Generator expression
# <generator object <genexpr> at 0x10477cc30>

K = (x for x in range(2))
next(K)
# 0
</code></pre>

<h3>Similar behavior in built-in</h3>
<h4>Dictionary</h4>>
<img src="https://www.evernote.com/l/AAn-lS3VBudCFLW2OizY5t2g4G1s2ejI-2QB/image.png">

<h4>In function</h4>
<h5>func(*....)</h5>
<img src="https://www.evernote.com/l/AAlHNUs4Wb5K_7N3SD8vs80fuZDBTdFEdiIB/image.png">






<h2>__iter__ , next</h2>

<p>You should prefer __iter__ to __getitem__ because __iter__ supports general iteration contexts better.</p>

<pre><code>
class A:
    def __init__(self, start, stop):
        self.value = start - 1
        self.stop = stop 
    def __iter__(self):
        return self
    def next(self): # if 3.x then use __next__(self):
        if self.value == self.stop: 
            raise StopIteration
        self.value += 1
        return self.value
</code></pre>

<p>When using:</p>

<pre><code>
a = A(1,3)
a.next()
# 1
a.next()
# 2
a.next()
# 3
a.next()
# StopIteration Traceback (most recent call last)

for i in A(4,5):
    print i
# 4
# 5
</code></pre>
<p>This is one time scan. Once it reaches the end, the iteration will not work any more. For multiple, you need __iter__() and next() to be in separted classes.</p>

