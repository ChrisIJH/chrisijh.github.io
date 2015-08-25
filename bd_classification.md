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

$Pr(Y=k| X=x)$ is refered to Posterior probability.

$$
Pr(Y=k| X=x) = \frac{Pr(X=x|Y=k) Pr(Y=k)}{Pr(X=x)}  
$$
