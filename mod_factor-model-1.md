---
layout: level1default 
permalink: /modeling-analysis/factor-model-1/
---

#  Factor Model

**Factor Models** are applied to analyze the potential retursn on a portfolio of risky assets to choose the **optimal allocation** of ther funds to different assets and to measure the **portfolio risk**.



<hr>

### Risk Decomposition 
- Assumption:
<pre><code>The bnechmark or index is  
uncorrelated with  
the specific returns on a potfolio
</code></pre>
This is a strong restriction. Without the ristriction, factor model is simply a definition of the residuals.

So, the restrictions on residuals :

1.) $$E(\varepsilon) = 0$$  
2.) Mutually uncorrelated  
3.) Uncorrelated with factors  
4.) $$\varepsilon$$ is i.i.d.  

$$ note^*$$ number 4. is acutally not a restriction. It just shows how samples are distributed.


<div class="piktowrapper-embed" pikto-uid="6938336-ii-1-3factors" >
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

## Brief view

N varialbles   
K factors  

$$X_{it} = \alpha_i + \sum_{j=1}^K \beta_{ij}f_{jt} + \varepsilon_{it}$$  
$$i = 1,2,3,.....,N$$  
$$j = 1,2,3,.....,K$$  
$$t = 1,2,3,.....,T$$  

Assumption:  
$$ N >> K $$

<img src="https://www.evernote.com/l/AAn5lMa9jJ1PeJoMnB-CbnVASXMS_sv8XQUB/image.png">

Now, we can write the model in regression form as  

$$X = FB' + E$$  

(ex: N=4 va, K=5)  
<img src="https://www.evernote.com/l/AAmnmZqWDX9I9ZewEvlKqD2WRtpzkpZhIQMB/image.png">  


<blockquote>
<h4 id="references">References:</h4>
  <p>[1] Alexander, Carol. Market Risk Analysis. Vol. II. Chichester, England: Wiley, 2008. Print.  </p>
<p> [2] Tsay, Ruey S. Analysis of Financial Time Series. Hoboken, NJ: Wiley, 2005. Print.  </p>
<p> [3] Fabozzi, Frank J., Sergio M. Focardi, and Petter N. Kolm. Quantitative Equity Investing Techniques and Strategies. Hoboken, NJ: John Wiley, 2010. Print.  </p>
<p> [4] Cornuejols, Gerard, and Reha Tütüncü. Optimization Methods in Finance. Cambridge, UK: Cambridge UP, 2007. Print.  </p>
<p> [5] Coggin, T. Daniel., and Frank J. Fabozzi. Handbook of Equity Style Management. Hoboken, NJ: Wiley, 2003. Print.</p>  </blockquote>


