---
layout: level1default 
permalink: /bigdata/nlp1/
---

<h1>Natural Language Processing</h1>

<p>Study Note for "Text Mining and Analytics by ChengXiang Zhai, University of Illinois at Urbana Champaign" at Coursera.(https://class.coursera.org/textanalytics-001/wiki/Week1Overview)</p>
<h2>Basic Concepts in NLP</h2>
<ul>
    <li>Lexical Analysis (Part-of-speech tagging)</li>
    <li>Syntactic Analysis (Parsing)</li>
    <li>Semantic Analysis</li>
    <li>Inference</li>
    <li>Pragmatic Analysis (Speech act)</li>
</ul>

<img src="https://www.evernote.com/l/AAnm5QiKZetKnZ1MgkStHZ7tVrlTERyJaUkB/image.png">

<h2>Basic Word Relations: Paradigmatic vs. Syntagmatic</h2>
<table>
  <thead>
    <tr>
      <th>Paradigmatic</th>
      <th>Syntagmatic</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>If they can be substituted for each other. ('cat' and 'dog, 'Monday' and 'Tuesday')</td>
      <td>If they can be combined with each other. ('cat' and 'sit', 'car' and 'drive')</td>
    </tr>
    <tr>
      <td>
          <ul>
            <li>Represent each word by its context.</li>
            <li>Compute context similarity.</li>
            <li>Words with high context similarity likely have pradigmatic relation.</li>
          </ul>
      </td>

      <td>
      <ul>
        <li>Count how many times two words occur togetter in a context.</li>
        <li>Compare their co-occurrences with their individual occurrences.</li>
        <li>Words with high co-occurences but relatively lowindividual occurences likely have syntagmatic relation.</li>
      </ul></td>
    </tr>
    <p>Paradigmatically related words tend to have syntagmatic relation with the same word -> Joint Discovery of the two relations.</p>
  </tbody>
</table>
<p>This idea is implemented in many different ways.</p>

<h2>Paradigmatic Relation Discovery</h2>

<div class="piktowrapper-embed" pikto-uid="7459978-nlp1_1" >
    <div class="pikto-canvas-wrap">
        <div class="pikto-canvas"></div>
    </div>
</div>
<script>
    (function(d){
        var js, id="pikto-embed-js", ref=d.getElementsByTagName("script")[0];
        if (d.getElementById(id)) { return;}
        js=d.createElement("script"); js.id=id; js.async=true;
        js.src="https://magic.piktochart.com/assets/embedding/embed.js";
        ref.parentNode.insertBefore(js, ref);
    }(document));
</script>

<p>So, now Bag of Words --> Vector Space Model(VSM)</p>

<img src="https://www.evernote.com/l/AAm1QXdAu8JIJaOAcqHrtCo0v95utxntTmsB/image.png">
<img src="https://www.evernote.com/l/AAn0hVPkznhB8q8bShjo41GVssuVNujTuj0B/image.png">
<p>Next, Expected Overlap of words in context(EOWC) methods can be used.</p>
<p>But, there are still unsolved problem.
<ul><li>Better for frequent term than mathching more distinct term.<ul><li>Can ge improved by sublinear transformation of Term Frequency(TF)</li></ul></li>
<li>Treats 'the' and 'eats' equally. <ul><li>Can be improved by rewarding matching a rare word: IDF term weighting</li></ul></li></ul>
</p>

<h2>Systegmatic Relation</h2>
<p>Systegmatic Relation = Correlated Occurences</p>








<br>
<hr>
[References]
[1] Text Mining and Analytics by ChengXiang Zhai, University of Illinois at Urbana Champaign