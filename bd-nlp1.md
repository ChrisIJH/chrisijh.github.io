---
layout: level1default 
permalink: /bigdata/nlp1/
---

<h1>Natural Language Processing</h1>

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



<br>
<hr>
[References]
[1] Text Mining and Analytics by ChengXiang Zhai, University of Illinois at Urbana Champaign