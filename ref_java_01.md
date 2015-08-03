---
layout: level1default 
permalink: /reference/ref_java_01/
---


# String vs. StringBuffer vs. StringBuilder

<h3>String</h3>
<ul>
    <li>Immutable --> when used, it will be copied.</li>
    <li>Stored in the Constant String Pool</li>
    <li>Thread safe: can not be used by two threads simultaneously.</li>
    <li><pre>String a="test word";
a = "another test word";
</pre>
"test word" exists in Constant String pool. But, the reference is lost.</li>
    <li>Performance: Fast</li>
</ul>


<h3>StringBuffer</h3>
<ul>
    <li>mutable</li>
    <li>Stored in heap.</li>
    <li>Thread safe</li>
    <li>Syncrhonization</li>
    <li><pre>
StringBuffer a = new StringBuffer("word");
a = new StringBuffer("another word");
    </pre>First, it is stored in heap. Then, the value changed to "another word"</li>
    <li>Performance: Very Slow</li>
</ul>

<h3>StringBuilder</h3>
<ul>
    <li>Same to StringBuffer. But, Not Thread Safe, No synchronization</li>
    <li>Performance: Fase</li>
</ul>