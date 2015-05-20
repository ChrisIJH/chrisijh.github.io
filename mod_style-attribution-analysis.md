---
layout: level1default 
permalink: /modeling-analysis/style-attribution-analysis/
---


# Style Attribution Analysis

## Overview

The performance measurement and attribution provide important understanding about portfolio in various ways. The objective
is to access the performance of different investment strategies and also to identify the styles that are major risk factors
 in portfolio and fund. The very famous methods is **Style Attribution Analysis** developed by Sharpe (1992). Style Attribution Analysis starts from
**Multi Factor Model** with **style factors** which include growth/growth stocks and different cap size stocks.  
We can treat this as a method of reverse engineering in a sense that it shows the fund's strategy by identifying detailed choice of assets.

In this page, I analyze Vanaguard Large-Cap ETF (VV) which tracks crsp indexes.

Style fators are:  
<!--
  * CRSP US Large Cap Growth Index (^CRSPLCG1)
  * CRSP US Large Cap Value Index (^CRSPLCV1)
  * CRSP US Small Cap Growth Index (^CRSPSCG1)
  * CRSP US Small Cap Value Index (^CRSPSCV1)  
 --> 
## Methodology

Since style attribution analysis starts from Multi Factor Model, we need to consider the below:  

  ![multi](http://latex.codecogs.com/gif.latex?Y_t%20%3D%20%5Calpha%20&plus;%20%5Cbeta_1%20X_%7B1%2Ct%7D%20&plus;%20...%20&plus;%20%5Cbeta_k%20X_%7Bk%2Ct%7D%20&plus;%20%5Cepsilon_t) 
  ![a](http://latex.codecogs.com/gif.latex?where%2C%20%5C%20k%20%5C%20risk%5C%20factors%5C%20%28styles%29%20%5Cwith%5C%20returns%20%5C%20X_t)  
  ![b](http://latex.codecogs.com/gif.latex?return%20%5C%20Y%20%5C%20is%20%5C%20sum%20%5C%20of%20%5Csystematic%5C%20component.)  
  ![c](http://latex.codecogs.com/gif.latex?%5Cepsilon%20%5C%20is%20%5C%20idiosyncratic%20%5C%20component.)  
  
Sharpe suggested finding the weight of each style by minimizing the tracking error which can be written as quadratic programming as below with matrix form:  

  ![d](http://latex.codecogs.com/gif.latex?%5Cmathbf%7B%5Cepsilon%7D%20%3D%20%5Cmathbf%7BY-X%5Cbeta%7D)  
  


>#### References:
  >[1] Alexander, Carol. Market Risk Analysis. Vol. II. Chichester, England: Wiley, 2008. Print.  
  >[2] Jackson, Mary, and Staunton Mike, Advanced Modelling in Finance using Excel and VBA, Chichester, England: Wiley, 2001. Print.  
  >[3] Coggin, T. Daniel., and Frank J. Fabozzi. Handbook of Equity Style Management. Hoboken, NJ: Wiley, 2003. Print.  


