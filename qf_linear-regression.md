---
layout: level1default 
permalink: /modeling-analysis/linear-regression/
---

# Simple Linear Regression

###Assumption

>The dependent variable --> A linear relationship with just one independent variable.<br> Ex) CAPM or single factor model.


### Simple Linear Regression Example from Alexander(2008)
 

#### Excel 
The excel implementation is introduced in the book. The result will be similar to the following:


![alt text](https://www.evernote.com/shard/s9/sh/57961f26-5016-4d12-9946-cb75344093c2/3d81ec1e471a9a24a02b4e31ef166e29/deep/0/alexander_linear_regression.png "Alexander linear Reg ")

<hr>
#### Matlab

The book contains only excel implementation. If it is implemented with **matlab**, it will be similar to the following:

<pre>
clear;
clc;
[num, txt] = xlsread('file', 'SheetName');

%% clean data
txtday = txt(2:end, 1);
datenumday = datenum(txtday, 'mm/dd/yyyy');
datestrday = datestr(datenumday, 'yyyymmdd');
tday = str2double(cellstr(datestrday));
idx = num(:,end);

%% Since the data is price, change it to return
r = diff(log(num));

%% Separate data
x = r(:,2); %SP
y = r(:,1); %Amex
list = {'R','beta', 'adjrsquare','rsquare', 'tstat'};
stats = regstats(y, x, 'linear', list);

%% Organize the result
cfs = stats.beta;
arsq = stats.adjrsquare;
rsq = stats.rsquare;
t = stats.tstat.t;
pv = stats.tstat.pval;

%% graph
p = polyfit(x,y,1);
f = polyval(p,x);
figure;
plot(x,y,'.');
hold on
plot(x,f,'-r');
xlabel('SP500');
ylabel('AMEX');
text(-0.02,0.6, ['y= ' , num2str(cfs(2)), 'x + ', num2str(cfs(1)), ', R^2 = ', num2str(rsq)]);
</pre>


![alt text](https://www.evernote.com/shard/s9/sh/de8fe090-4ef4-421b-92d5-96b56d81bf06/89003d6e68ecab935eac0d02a3c29fba/deep/0/alexander_matlab_lr.png "matlab result")


![alt text](https://www.evernote.com/shard/s9/sh/097de607-95cc-4bbe-8dee-7a4cb718dd2a/d38b833ed46c612fe80f1e7fe9051f65/deep/0/matlab_graph_lr.png "graph")

<hr>
#### R

<pre>
# Simple linear regression

# Data read from excel file
library(gdata)
data = read.xls("Filename", sheet = 2, header = TRUE) 

# See how it looks
names(data)
attach(data)
layout(1)
plot(SP500, Amex)

# Subsetting data
tickers = c("Amex", "SP500")
prices = data[tickers] 

returns = data.frame(diff(as.matrix(log(prices))))


# Regression
L1 = lm(returns$Amex ~ returns$SP500)
summary(L1)

# graph
plot(returns$Amex ~ returns$SP500)
abline(L1, col="red")

</pre>
![alt text](https://www.evernote.com/l/AAlOZAYF7HJOLaMEAPgrr4GM5diV3BHlSXEB/image.png "R result")
![alt text](https://www.evernote.com/l/AAkJL9M7ak1Pf5XnREynXPsoXkAFnGC007QB/image.png "R Summary")

<hr>
#### Python

## Method 1: scipy stats linregress
<pre>
import numpy as np
from scipy import stats
import pandas as pd

dts = pd.read_excel('filep path', 'Sheet2', index_col=0)
log_dts = np.log(dts)

log_rts = log_dts[1:].values-log_dts[:-1]
slope, intercept, r_value, p_value, std_err = stats.linregress( log_rts["SP500"], log_rts["Amex"])
print slope
print intercept
print "r-squared:", r_value**2
print "std error:", std_err
degrees_of_freedom = len(log_rts)-2
predict_y = intercept + slope*log_rts["Amex"]
pred_error = log_rts["SP500"] - predict_y
residual_std_error = np.sqrt(np.sum(pred_error**2)/degrees_of_freedom)

</pre>

## Method 2: pandas OLS
<pre>
import numpy as np
import pandas as pd
import statsmodels.api as sm

y = log_rts.Amex  # response
X = log_rts.SP500 # predictor
X = sm.add_constant(X) # Adds a constant term to the predictor
est = sm.OLS(y, X)
est = est.fit()
est.summary()
</pre>
<p>The summary result shows :</p>
![alt text](https://www.evernote.com/l/AAlNvSq5qbpJQa7s-oojrE86GrPfEtVIolsB/image.png "Python OLS result")




[References]
[1] Alexander, Carol. Market Risk Analysis. Vol. I. Chichester, England: Wiley, 2008. Print.