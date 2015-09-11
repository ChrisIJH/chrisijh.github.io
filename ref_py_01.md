---
layout: level1default 
permalink: /reference/ref_py_01/
---

<h1>Python 01</h1>
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

