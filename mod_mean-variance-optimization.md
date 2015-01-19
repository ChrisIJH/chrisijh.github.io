---
layout: default
permalink: /modeling-analysis/mvo/
---

# Mean Variance Optimization using VBA, Matlab, and Python

The classical mean variance optimization is keynote technique for all other porfolio optimization techniques. In this page,
I implemented it with various languages. 

## VBA implementation  
User simply get the historical price information with matlab and transfer it to 
Excel. The excel page consists of 2 buttons. The first button computes Mean Return and Standard Deviation of each assets.
The second button gets the variance covariance matrix and compute the efficient frontier using solver then graph it.


### Matlab fetch --> Excel 
There are several ways to get the historic price information using excel. Thanks to the simplicity and flexibility of 
Matlab [fetch function](http://www.mathworks.com/help/database/ug/fetch.html?refresh=true), I prefer to fetch the 
information using Matlab then dump to excel using xlswrite function.

### Initial Excel Page
 
 ![ini](https://www.evernote.com/shard/s9/sh/894559e8-36fc-4fd1-a05f-ded548ffc525/bec60fa65775f913f21b209c692ca3c2/deep/0/mean_variance_auto_temp2---Excel.png)
 
 
