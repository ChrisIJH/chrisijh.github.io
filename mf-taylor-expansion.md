---
layout: level1default 
permalink: /mf/taylor-expansion/
---


#Intro

<p><strong>Taylor Expasion</strong> is very useful especially in measuring risk and returns of the portfolio with <strong>non-linear functions</strong>.</p>
<p>Definition: A Taylor expansion about a particular point $x_0$ provides an approximation from a polynomial function in the region of $x_0$.</p>

<p>$n^{th}$ order Taylor Approximation of $f(x)$ about $x_0$ :</p>

$$
f(x) \approx f(x_0) + (x-x_0){f}'(x_0) + \frac{(x-x_0)^2}{2!}{f}''(x_0) + ... + \frac{(x-x_0)^n}{n!}{f}^{(n)}(x_0)
$$

<p>Now, change a little bit as the below:</p>

$$
f(x+\Delta x) - f(x) \approx f'(x_0)\Delta x + \frac{1}{2}{f}''(x_0)(\Delta x)^2 + ... + \frac{f^{(n)}(x_0)}{n!}(\Delta x)^n
$$


## Applications

<ol>
    <li>delta-gamma approximation in Option</li>
    <li>duration-convexity aproximation in Bond</li>
    <li>datla-gamma-vega approximation in Options : Multivariate Taylor Expansion case</li>
</ol>



<blockquote>
<h4 id="references">References:</h4>
<p>[1] Alexander, Carol. Market Risk Analysis. Vol. I. Chichester, England: Wiley, 2008. Print.  </p> 
</blockquote>