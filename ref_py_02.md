---
layout: level1default 
permalink: /reference/ref_py_02/
---

<h1>Python 02</h1>

<h2>Decorator</h2>

<h3>ex 1</h3>
<pre><code>
def A(arg1):
    return "The arg1 is: " + arg1
    
a = A
print a("arg1 is this") # The arg1 is: arg1 is this
</code></pre>

<p>Functions can be arguments of other functions.</p>

<pre><code>
def A(arg1):
    return "The arg1 is: " + arg1

def B(f):
    other_arg = 'test'
    return f(other_arg)

print B(A)
</code></pre>

<p>Functions return other functions.</p>

<pre><code>
def C():
    def D():
        return "Hi world"
    return D

print C() # <function D at 0x1043e4140> 
a = C()
print a() # Hi world
</code></pre>
<pre><code>
def C(test):
    def D():
        return "Hi world " + test 
    return D

print C("test") # <function D at 0x1043b4ed8> 
a = C("test")
print a() # Hi world test
</code></pre>

<pre><code>
def B(f):
    def C(test):
        return "<p>%s</p>" % f(test)
    return C

def A(test):
    return "This is test for decorator. The arg is %s" % test

a = B(A)

print a("testArg") # <p>This is test for decorator. The arg is testArg</p>
</code></pre>

<h2>Now, let's use Decorator Syntax.</h2>

<pre><code>
def B(f):
    def C(test):
        return "<p>%s</p>" % f(test)
    return C
@B
def A(test):
    return "This is test for decorator. The arg is %s" % test

print A("ThisArg1") 
# <p>This is test for decorator. The arg is ThisArg1</p>
</code></pre>

<pre><code>
def B(f):
    def C(test):
        return "<p>%s</p>" % f(test)
    return C
def D(f):
    def C(test):
        return "<div>%s</div>" % f(test)
    return C

@D
def A(test):
    return "This is test for decorator. The arg is %s" % test

print A("ThisArg1") 
# <div>This is test for decorator. The arg is ThisArg1</div>
</code></pre>
<pre><code>
def B(f):
    def C(test):
        return "<p>%s</p>" % f(test)
    return C
def D(f):
    def C(test):
        return "<div>%s</div>" % f(test)
    return C

@D # div tag: This one later
@B # p tag: This one first
def A(test):
    return "This is test for decorator. The arg is %s" % test

print A("ThisArg1") 
# <div><p>This is test for decorator. The arg is ThisArg1</p></div>
</code></pre>
<p>Using decorator with class</p>

<pre><code>
def D(f):
    def C(test):
        return "<div>%s</div>" % f(test)
    return C

class A:
    def __init__(self):
        self.arg1 = "arg1"
        self.arg2 = "arg2"

    @D
    def E(self):
        return "Arg1 is: %s , Arg2 is: %s " % (self.arg1 , self.arg2)


a = A()
print a.E() # <div>Arg1 is: arg1 , Arg2 is: arg2 </div>
</code></pre>

<h2>Passing arguments to decorators</h2>

<pre><code>
def R(tag):
    def D(f):
        def C(test):
            return "<%s>, %s, </%s>" % (tag, f(test), tag)
        return C
    return D

class A:
    def __init__(self):
        self.arg1 = "arg1"
        self.arg2 = "arg2"

    @R("p")
    def E(self):
        return "Arg1 is: %s , Arg2 is: %s " % (self.arg1 , self.arg2)

a = A()
print a.E() # <p>, Arg1 is: arg1 , Arg2 is: arg2 , </p>
</code></pre>
