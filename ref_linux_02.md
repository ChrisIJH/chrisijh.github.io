---
layout: level1default 
permalink: /reference/ref_linux_02/
---


# AWK

<p>By default, whitespace as delimiter.</p>

<table>
  <thead>
    <tr>
      <th>Action</th>
      <th>Command</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Print all columns separated by whitespace</td>
      <td><pre>awk '{print $0}' filename</pre></td>
    </tr>
    <tr>
      <td>Print first column separated by comma</td>
      <td><pre>awk -F "," '{print $1}' filename</pre></td>
    </tr>
    <tr>
      <td>Print second and third columns separated by colon</td>
      <td><pre>awk -F ":" '{print $2 $4}' filename</pre></td>
    </tr>
    <tr>
      <td>Print all columns except 2nd column separated by whitespace</td>
      <td><pre>awk '{$2=""; print $0}' filename</pre></td>
    </tr>
    <tr>
      <td>Print all columns except 2nd and 3rd column separated by whitespace</td>
      <td><pre>awk '{$2=$3=""; print $0}' filename</pre></td>
    </tr>
  </tbody>
</table>