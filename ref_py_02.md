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
            return "%s, %s, /%s" % (tag, f(test), tag)
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



<h2>From Learning Python 5th ed</h2>

<pre><code>

def Deco(f):
    def wrapper(*args):
        return "decorated: " + str(args)
    return wrapper

@Deco
def f(*args):
    return args

f([1,2])  # 'decorated: ([1, 2],)'

</code></pre>

<pre><code>
class Decor:
    def __init__(self, f):
        self.f = f
        
    def __call__(self, *args):
        return "decorated with class: " + str(self.f(*args))
    
@Decor
def f(*args):
    return args

f( [4,3,95, 6])
# 'decorated with class: ([4, 3, 95, 6],)'
</code></pre>

<pre><code>
def decorator(cls):
    class wrapper:
        def __init__(self, *args):
            self.wrapped = cls(*args)
            
        def __getattr__(self, name):
            return "You requested : " + getattr(self.wrapped, name)
    return wrapper
        
@decorator
class C:
    def __init__(self, a, b):
        self.attr = 'spam'
        
x = C(6,7)
x.attr
</code></pre>

<h3>With built_in</h3>

<pre><code>
class Spam:
    numInstances = 0
    def __init__(self):
        Spam.numInstances += 1
        
    <strong>@staticmethod</strong>
    def printNumInstances(): # no instance passed
        print "Num of Instances: " + str(Spam.numInstances)

a = Spam()
b = Spam()
a.printNumInstances()
# Num of Instances: 2
<strong>Spam.printNumInstances()</strong>
# Num of Instances: 2
</code></pre>

<p>Without @staticmethod, there will be error for Spam.printNumInstances()</p>

<h2>Staticmethod, Classmethod</h2>

<pre><code>
class Method:
    def imeth(self,x):
        print self,  ": ",  str(x)
    
    @classmethod
    def cmeth(cls, x):
        print ": ", str(x)
        
    @staticmethod
    def smeth(x):
        print ": ", str(x)
        
    @property
    def name(self):
        return "Method has ", self.__class__.__name__

a = Method() 
a.imeth(2) # using normal call using instance
Method.imeth(a, 2) # using class name with instance as a first argument
Method.imeth(2) # cannot use without instance as a first argument

# class method
a.cmeth(3) # using instance
Method.cmeth(3) # using class without instance as a first argument
Method.cmeth(a,3) # error: cannot use instance as a first argument

# static method
a.smeth(3) # using instance
Method.smeth(3) # using class without instance as a first argument
Method.smeth(a, 3) # error: cannot use instance as a first argument
</code></pre>

<h1>Coding Function Decorator</h1>

<h2>Tracing calls</h2>

<pre><code>
class tracer:
    def __init__(self, func):
        self.calls = 0
        self.func = func
    
    def __call__(self, *args):
        self.calls +=1
        print('call %s to %s' % (self.calls, self.func.__name__))
        self.func(*args)

@tracer
def spam(a,b,c):
    print(a+b+c)

spam(1,2,3)
#call 1 to spam
#6

spam('a','b','c')
#call 2 to spam
#abc

spam.calls # Just like spam is the instance.
# 2
</code></pre>

<h1>Coding Class Decorators</h1>

<h2>Singleton</h2>

<pre><code>
instances= {}

def singleton(aClass):
    def onCall(*args, **kwargs):
        if aClass not in instances:
            instances[aClass] = aClass(*args, **kwargs)
        return instances[aClass]
    return onCall

@singleton
class Person:
    def __init__(self, name, hours, rate):
        self.name = name
        self.hours = hours
        self.rate = rate
        
    def pay(self):
        return self.hours*self.rate

@singleton
class Spam:
    def __init__(self, val):
        self.attr = val
</code></pre>

<pre><code>
bob = Person('Bob', 40,10)

instances
# {<class __main__.Person at 0x106881530>: <__main__.Person instance at 0x106911290>}

print(bob.name, bob.pay())
# ('Bob', 400)

sue = Person('Sue', 50, 20)

sue is bob
# True

print (sue.name, sue.pay())
# ('Bob', 400)

x = Spam(42)
instances
# {<class __main__.Person at 0x106881530>: <__main__.Person instance at 0x106911290>,
# <class __main__.Spam at 0x106881598>: <__main__.Spam instance at 0x106911488>}

x is y
# True


</code></pre>
