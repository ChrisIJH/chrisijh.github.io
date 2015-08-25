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




# ln  

<p>Better use absolute pathname.</p>

<table class="table table-bordered">
  <thead>
    <tr>
      <th>Action</th>
      <th>Command</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Create Soft Link</td>
      <td>
        <pre><code>
        $ ln -s /full/path/to/src /full/path/link(from)/file
        </code></pre>
        Softlink is only possible across different partitions.
      </td>
    </tr>
    <tr>
      <td>Create Hard Link</td>
      <td>
        <pre><code>
        $ ln /full/path/to/src /full/path/link(from)/file
        </code></pre>
        * . and .. are hardliked to the current and parent directory resepectively. Linux don't allow users to create hard link to <strong>directory.</strong>
        * No hard link across different partitions.
      </td>
    </tr>
    <tr>
      <td>When deleting original file to soft link.</td>
      <td>
       The soft link will still exist as broken link. 
      </td>
    </tr>
    <tr>
      <td>When deleting original file to hard link.</td>
      <td>
       The hard link will still exist. Can access to the content of the original file which is already deleted. 
      </td>
    </tr>
    <tr>
      <td>Soft linke is very useful to storage problem</td>
      <td>
       The Partition 1 is almost full. The additional space for log directory in the partition 1. Then move all log files to new partition, delete the original log file. 2. Create a soft link (as the same name to the original log directory) in the partition 1 so that the link points the new log directory in the partiion 2.
      </td>
    </tr>



  </tbody>
</table>

