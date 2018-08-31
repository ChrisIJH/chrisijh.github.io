---
layout: level1default 
permalink: /bigdata/classification/
---

<h1>Classification</h1>

<div class="piktowrapper-embed" pikto-uid="7341773-classification01" >
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

<h2>Logistic Regression</h2>

<p>Rather than modeling resoponse Y directly, Logistic regression <strong class="mark">models the probability that Y belongs to a particular category.</strong></p>

<p>ex)</p>

$$
Pr(default = Yes|balance)
$$


$$
p(X) = \beta_0 + \beta_1X
$$
<p>p(X) must fall between 0 and 1. So, we need to model p(X) using a function that gives outputs between 0 and 1.</p>
<p>Logistic Function</p>

$$
p(X) = \frac{e^{\beta_0+\beta_1X}}{1+e^{\beta_0+\beta_1X}}
$$

$$
\frac{p(X)}{1-p(X)} = e^{\beta_0+\beta_1X}
$$

$$
log(\frac{p(X)}{1-p(X)}) = \beta_0+\beta_1X
$$



<p>That is, increasing X by one unit changes the log odds by $\beta_1$</p>

<p>If $\beta_1 > 0$:</p>
<p>X increase --> p(x) increase</p>

<p>If $\beta_1 < 0$:</p>
<p>X increase --> p(x) decrease</p>



<p>Regression coefficients are estimated using <strong>maximum likelihood</strong>. Find the coeeficients that makes p(X) as close as 1 or 0 based on the information.</p>

$$
l(\beta_0, \beta_1) = \prod_{i:y_i=1}p(x_i)\prod_{i':y_{i'}=0}(1-p(x_{i'}))
$$
<p>The estimates $\beta_0$ and $\beta_1$ are chosen to maximize the likelihood function.</p>


<h2>Linear Discriminant Analysis</h2>


$\pi_k $ Prior Probability. A randomly chosen observation comes from the kth class  
$f_k(X) = Pr(X=x|Y=k)$  
$$
Pr(X=x|Y=k) = \frac{Pr(X=x,Y=k)}{Pr(Y=k)}  
$$
$$
Pr(Y=k| X=x) = \frac{Pr(X=x,Y=k)}{Pr(X=x)}    
$$


$$
Pr(Y=k| X=x)
$$ is refered to Posterior probability.

$$
Pr(Y=k| X=x) = \frac{Pr(X=x|Y=k) Pr(Y=k)}{Pr(X=x)}  
$$
<p>When:</p>

<ul><li>the classes are well-separated.</li>
<li>n is small and distribution of each X is normal.</li>
<li>more than 2 response classes.</li>
</ul>
<p>Steps:</p>
<ol>
    <li>Model the distribution of repdictors (X)</li>
    <li>Flip it using Bayes' theorem. </li>
</ol>


<h2>K-Nearest Neighbors</h2>

<p>KNN is a completely non-parametric approach, that is no assumptions are made about the shape of the decision boundary.
: boundary is highly non-linear</p>

<p>Steps:</p>

<ol>
    <li>Identify the K points in the training data that are closest to $x_0$, represented by $N_0$.</li>
    <li>Estimates the conditional probability for class j as the fraction of points in $N_0$ whose response values equal j:  
    $$
Pr(Y=j|X=x_0) = \frac{1}{K}\sum_{i\ in \ N}(Y_i=j)
    $$</li> 
    <li>KNN applies Bayes rule and classifies the test observation $x_0$ to the class with the largest probability.</li>
</ol>

<table>

  <tbody>
    <tr>
      <td>K=1</td>
      <td>Flexible, Low bias, high variance</td>
    </tr>
    <tr>
      <td>K grows</td>
      <td>Less flexible, a decision boundary is becoming linear. Low variance, high bias.</td>
    </tr>
  </tbody>
</table>


<h2>Maximal Margin Classifier</h2>

<p>p-dimensional hyperplan</p>
$$
\beta_0 + \beta_1X_1 + ...+\beta_pX_p = 0
$$

<p>Stpes:</p>
<ul>
  <li>Compute the distance from each training observation to a given separating hyperplane.</li>
  <li>margin(the minimal distance from the observations to the hyperplane</li>
  <li>Maximal margin hyperplane that has the farthest minimum distance to the training observations.</li>
  <li>Although the maximal margin classifier is oten successful, it can also lead to overfitting when p is large.</li>
</ul>  

<p>The maximal margin hyperplane is the solutino to the optimzation problem.</p>
<!--
$$\begin{align}
max_{\beta_0, \beta_1,....,\beta_p}M  \\
s.t. \sum_{j=1}^{p}\beta_j^2 = 1 \newline \\


y_i(\beta_0 + \beta_1x_{i1} + \beta_2x_{i2}+ ..... + \beta_px_{ip})  \geq M \\

where, \ i=1,....,n
\end{align}

$$
-->
<img src="https://www.evernote.com/l/AAlRN_pAkMtCHK7vtpFgu6Nb4CNDJ-kGurYB/image.png">

<p>Problems:</p>

<ul>
  <li>The distance can be seen as a measure of the confidence.</li>
  <li>Extremely sensitive to a change in a single observation.</li>
</ul>

<h2>Support Vector Classifier</h2>
<p>Rather than completely separate the observations, it could be worthwhile to misclassify a few training obsevations in order to do a better job in classifying the remaining observations.</p>



<img src="https://www.evernote.com/l/AAmf7pUFzxhMyLhivpeBfIV1Kbarmj173ewB/image.png">


<p>The hyperplane is chosen to separate most of the training observations into the two classes, but may misclassify a few observations.</p>
<h4>The differece from maximal margin classifier.</h4>
<p>An observation that lies strictly on the correct side of the margin does not affect the support vector classifier. Changing the position of that obsrvation would not change the classifier at all as long as its position remains on the correct side fo the margint.</p>

<h4>The difference from LDA</h4>
<p>LDA depends on the mean of all of the observations within each class as well as within-class covariance amtrix computed using all of the observations. However, Support Vector Classifier is robust to the behavior of observations that are far away from the hyperplane.</p>


<h2>Support Vector Machine</h2>
<p>For non-linearity, fit a support vector classifier using 2p features.</p>
$$
X_1, X_1^2, X_2, X_2^2, .... , X_p, X_p^2
$$
<img src="https://www.evernote.com/l/AAl0FpuNEFRCC7luNnqz3G8g3zqmEyZIlLkB/image.png">

<p>The <strong>support vector machine</strong> is an extension of the support vector classifier using <strong>kernels</strong>. We want to enlarge our feature space in order to accommodate a non-linear boundary between the classes.</p>
<img src="https://www.evernote.com/l/AAkKhhCqUgZOqYFP2R_Zz7IWpXYKkFvRp_sB/image.png">




<br>
<hr>
[References]
[1] James, Gareth, Daniela Witten, Trevor Hastie, and Robert Tibshirani. An Introduction to Statistical Learning: With Applications in R. Print.
>>>>>>> 826899093220eaf984aa72f25e91acd80491894a
