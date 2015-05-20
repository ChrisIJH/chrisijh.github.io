---
layout: level1default 
permalink: /quantitative-finance/linear-regression/
---

# Simple Linear Regression

###Assumption

>The dependent variable --> A linear relationship with just one independent variable.<br> Ex) CAPM or single factor model.


### Simple Linear Regression Example from Alexander(2008)
 

#### Excel 
The excel implementation is introduced in the book. The result will be similar to the following:


![alt text](https://www.evernote.com/shard/s9/sh/57961f26-5016-4d12-9946-cb75344093c2/3d81ec1e471a9a24a02b4e31ef166e29/deep/0/alexander_linear_regression.png "Alexander linear Reg ")

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

#### R

R



[References]
[1] Alexander, Carol. Market Risk Analysis. Vol. I. Chichester, England: Wiley, 2008. Print.