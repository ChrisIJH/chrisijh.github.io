---
layout: level1default 
permalink: /mf/linear-algebra1/
---

# Introduction

<p>Matrices are used to represent the risk and returns of the varioius portfolio.</p>

<h3>Key Terms and Applications</h3>
<ol>
	<li><u class="light">Linear questions</u> --> the gamma and vega hedges for an options portfolio</li>
    <li><u class="light">Covariance Matrix</u> --> Variance of a linear portfolio</li>
    <li><u class="light">Cholesky decomposition</u> --> Simulating returns on correlated assets, Monte Carlo VaR</li>
    <li><u class="light">Eigenvalue, Eigenvector</u> --> Positive Definite of Matrix</li>
    <li><u class="light">Principal Component Analysis</u></li>
</ol>


<h2>Brief</h2>

<h4>Orthogonal</h4>
<p>When dot product of tow non-zero vector is 0. the vectors are called orthogonal.</p>

<h4>Singular matrices</h4>
<blockquote><p>Det = 0</p>
<p>then, No inverse matrix exist.</p>
<p>then, we call it a singular matrix.</p>
<p>That means there is a <u class="light">linear relationship between the rows (or columns)</u>.</p></blockquote>


<h4>Determinant</h4>
<p>$
\begin{vmatrix}
a & b\\
c & d
\end{vmatrix} = ad-bc$
</p>
<p>
$\begin{vmatrix}
1 & 2 & 3\\
4 & 5 & 6\\
7 & 8 & 9
\end{vmatrix} = (1) \begin{vmatrix}  5 & 6\\ 8 & 9 \end{vmatrix} - (2) \begin{vmatrix}  4 & 6\\ 7 & 9 \end{vmatrix} + (3) \begin{vmatrix}  4 & 5\\ 7 & 8 \end{vmatrix}$</p>
<p>$det(A)= a_{i1}C_{i1} + .... a_{in}C_{in}$</p>

<p>$det(A) = a_{1j}C_{1j} + .... a_{1j}C_{1j}$</p>

<p>where, $C_{ij} = (-1)^{i+j}M_{ij}$</p>
<p>$C_{ij}$ is cofactor , $M_{ij}$ is a minor (the determinant from det(A) by deleting the ith row and the jth column from A)</p>

<h4>Quadratic</h4>
<p>$A$ is a square matrix with dimension n. $x$ is an n-dimensional vector.</p>
<p>$x'Ax$ is a quadratic form.</p>
<p>$$\begin{pmatrix}
x_1 & x_2
\end{pmatrix}
\begin{pmatrix}
1 & 2 \\
3 & 4
\end{pmatrix}\begin{pmatrix}
x_1 \\ x_2
\end{pmatrix} = 1x_1^2 + (2+3)x_1x_2 + 4x_2^2
$$</p>
<p>We can change A to symetric matrix B.</p>
<p>$B = \frac{1}{2}(A+A') = \begin{pmatrix}
1 & 2.5 \\
2.5 & 4
\end{pmatrix}$</p>
<p>$$\begin{pmatrix}
x_1 & x_2
\end{pmatrix}
\begin{pmatrix}
1 & 2.5 \\
2.5 & 4
\end{pmatrix}\begin{pmatrix}
x_1 \\ x_2
\end{pmatrix} = 1x_1^2 + (2.5+2.5)x_1x_2 + 4x_2^2
$$</p>






<blockquote>
<h4 id="references">References:</h4>
<p>[1] Alexander, Carol. Market Risk Analysis. Vol. I. Chichester, England: Wiley, 2008. Print.  </p> 
</blockquote>
