---
layout: level1default 
permalink: /reference/ref_datastructure_04/
---

<h1>Sorting</h1>

<div class="light">
<h2>Sequantial Search</h2>

<p>If list is unordered, the number of comparison is</p>
<p>Worst case = n</p>
<p>Best case = 1</p>
<p>Average = n/2</p>
<br>
</div>

<div class="dark">
<h2>Binary Search</h2>

<p>To analyze the binary search algorithm, we need to recall that each comparison eliminates about half of the remaining items from consideration. What is the maximum number of comparisons this algorithm will require to check the entire list? If we start with n items, about $\frac{n}{2}$ items will be left after the first comparison. After the second comparison, there will be about $\frac{n}{4}$, Then \(\frac{n}{8}\), $\frac{n}{16}$, and so on. How many times can we split the list? Table 3 helps us to see the answer.</p>

<img src="https://www.evernote.com/shard/s9/sh/e3a69ac6-1742-4c88-8915-faaccd1356a3/4321c7b78683e2b27818ac771f5ce4ad/deep/0/The-Binary-Search---Problem-Solving-with-Algorithms-and-Data-Structures.png">
<img src="https://www.evernote.com/l/AAnKFgTB189L166_AZB3-Jc9pg0kMAvbPeQB/image.png">

</div>
<div class="light">
<h2>Hashing</h2>
<p><strong>A hash table</strong> is a collection of items which are stored in such a way as to make it easy to find them later. Each position of the hash table, often called a slot, can hold an item and is named by an integer value starting at 0. For example, we will have a slot named 0, a slot named 1, a slot named 2, and so on. <strong>Initially, the hash table contains no items</strong> so every slot is empty. We can <strong>implement a hash table by using a list with each element initialized to the special Python value None.</strong> Figure 4 shows a hash table of size m=11. In other words, there are m slots in the table, named 0 through 10.</p>
<img src="https://www.evernote.com/shard/s9/sh/4ba6863a-5a3a-4e16-ac4a-f1a99628f336/ec55378f51811e5757504605d580659e/deep/0/Hashing---Problem-Solving-with-Algorithms-and-Data-Structures.png">
<p>The mapping between an item and the slot where that item belongs in the hash table is called the <strong>hash function.</strong> The hash function will take any item in the collection and return an integer in the range of slot names, between 0 and m-1. Assume that we have the set of integer items 54, 26, 93, 17, 77, and 31. Our first hash function, sometimes referred to as the <strong>“remainder method,”</strong> simply <strong>takes an item and divides it by the table size, returning the remainder as its hash value (h(item)=item%11)</strong>. Table 4 gives all of the hash values for our example items. Note that this remainder method (modulo arithmetic) will typically be present in some form in all hash functions, since the result must be in the range of slot names.</p>

<img src="https://www.evernote.com/shard/s9/sh/eb69813b-adcf-4b3a-bd46-c04bebd0557d/685b7061bfd511704873c4258a1981cc/deep/0/Hashing---Problem-Solving-with-Algorithms-and-Data-Structures.png">
<p>Once the hash values have been computed, we can <strong>insert each item into the hash table at the designated position</strong> as shown in Figure 5. Note that <strong>6 of the 11 slots are now occupied.</strong> This is referred to as the <strong>load factor</strong>, and is commonly denoted by $\lambda=\frac{number\, of\, items}{table\,size}$. For this example, $\lambda = \frac{6}{11}$.</p>


<p>Due to collisions, the number of comparison cannot be measured easily. The best is O(1). The load factor $\lambda$ is important.</p>
</div>

<div class="dark">
<h2>Bubble Sort</h2>
<p>Starting from the first one in the list, it continuosly compares with next term. After the first pass, the largest one will be in place which is the last slot. Same way, continue the pass until it finally is sorted.</p>
<img src="https://www.evernote.com/l/AAkUFgqenxZCrYTJO9w5GpQJ4ylEDXVxKKQB/image.png">
<p>Bubble sort would be the most inefficient sorting method. But, because it maeks passes through th entire unsorted portion, it has the capabililty to do something that other algorithms cannot. If a bubble sort is modifed to stop early, it may have an advantage.</p>
<p>In Python,  
it is possible to perform simultaneous assignment. The statement <strong>a,b=b,a</strong> will result in two assignment statements being done at the same time. Using simultaneous assignment, the exchange operation can be done in one statement.</p>

</div> 

<div class="light">
<h2>Selection sort</h2>
<p>In each pass, it looks for the largest value, then place it in the correct location. So, the number of swap reduced. $O(n^2)$, same as bubble sort. But, the number of swap reduced. So, typically faster than bubble sort.</p>
</div>

<div class="dark">
<h2>Insertion Sort</h2>
<p>Still $O(n^2)$. </p>
<img src="https://www.evernote.com/l/AAkdwf8tTRRD7L47POqsj69cYVD_GCF2pTYB/image.png">
</div>

<div class="light">
<h2>The Shell Sort</h2>
<ul>
	<li>Improved on the insertion sort by breaking the original list into a small sublists.</li>
	<li>uses an increment i, called the gap to create a sublist by choosing all items.</li>
</ul>
<img src="https://www.evernote.com/l/AAmTNgSKE5VFyJnIa_DxWOwlOOJh1PzVhFQB/image.png">
<p>After this, we simply do a standard insertion sort.</p>
<img src="https://www.evernote.com/l/AAlxbiHqDYNAcp9ekjLBecMP8FmhG8l5GwAB/image.png">
<p>Because the list is pre sorted, the above final insetion sort is very quick. It tends to be between O(n) and $O(n^2)$.</p>


<div class="dark">
<h2>Merge Sort</h2>
<p>Divide and Conquer startegy </p>
<img src="https://www.evernote.com/l/AAlwmLQlTchAaZBIQlj-mM4qmXAmOgQplJUB/image.png">
<ul>
	<li>First step, diving costs $\log{n}$</li>
	<li>Second step, merge results in a list of size n requires n operations.</li>
</ul>
<p>That is, it is $O(n\log{n})$</p>
</div>

</div>
