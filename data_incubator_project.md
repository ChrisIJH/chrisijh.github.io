---
layout: default 
permalink: /data-incubator-project/
---

# Projects Proposal


## Dynamic Portfolio Construction on Black-Litterman Framework - Using the performance history of analysts' view

### Motivation  


In quantitative investing strategy and construction of portfolio, **Black-Lietterman model** is one of the widely used framework which combines quantitative method such as Mean Variance Optimization and Investors' view toward the market. Its flexibility of construction of portfolio gives a lot of benefits to the portfolio managers and investors.

Nowadays **sentiment analysis using Tweeter data** is very famous and popular methods in investing. Tweeter data and other news articles are used as a medium for it. This result can be **good resource for 'investor's view part of Black-Litterman model.** 

### Main Point of this project  
**I will focus on creating investor's view effectively in this project.**
In addition to the above sentiment analysis, I want to study the **pattern and characteristics of professional analysts' view** 
toward market and specific stock, **then determine the unique paramenter(weight) for specific stock** which we will use 
as an investor's view part of Black-Litterman framework.   
Different analysts may have very different opinion to the same stock at a same time. by comparing these and 
finding a pattern and correlation between analysts and between any other aspect of fundamental or quantitative data. The analysis will be
performed considering multiple aspects - **per stock, per sector, per holding period, and etc.** We can make
the most of this result for different investing purpose.

#### Data source and Analysis
- Data 1. Price data will be obtained from Yahoo finance. However, we might need to find different public data to avoid survivorship bias.
- Data 2. Tweeter data will be used as Sentiment Analysis
- Data 3. For the analysts' view, one example is analysis articles from **SeekingAlpha.com.** 

This project will focus on data 3 - the analysis article of industry experts. This data is different from tweet or other news article. Tweeter data is from anonymous users and news article is usually a mixture of market views of various 
professionals. But, this data is organized as professional analyst and easy to track of his/her opinion about specific 
stock resulting in easily understand analyst's pattern and historic performance. **Natural Language Processing, clustering and classification** will be the key analysis methods.
Consequently, each analyst's view to specific stock will result in different weight when we construct Black-Litterman Portfolio. For example, in the future portfolio construction, 
we will take a higher weight on analysis of analyst 'A' for stock 'b', but lower weight for stock 'c'.

Let's look at the data 3 more. In case of analysis of only one stock - Amazon, we can obtain the articles from this web site "http://seekingalpha.com/symbol/AMZN/focus".  

Once we perform web scraping on this site, we can find that there are total of 640 articles of 253 analysts about Amazon from 2/6/2013 to 2/2/2015. Each article also has comments from readers and industry experts which will be another good resource for the analysis.
During this period, there were total of 30437 comments. Average number of article from analyst is 2.52. The maximum number of article
 from one analyst is 87. Standard deviation of number of articles from one analyst is 5.85. If we consider only analysts who wrote more than 2 articles, there were 100 analysts who wrote average of
 4.86 articles. This is from one stock. If we consider more stocks we will have enough information from more articles for our analysis. 
 