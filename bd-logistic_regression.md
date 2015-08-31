---
layout: level1default 
permalink: /bigdata/logistic-regression/
---

<h1>Logistic Regression</h1>


<h2>Using scikit-learn</h2>

<pre><code>
from sklearn.linear_model import LogisticRegression
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from patsy import dmatrices
from sklearn import metrics
from sklearn.cross_validation import train_test_split
from sklearn.cross_validation import cross_val_score

a = pd.read_table('Smarket.txt', sep='\s+')
a.head()
a.corr()

# Data preparation
#
X_preds = a.ix[:,[1,2,3,4,5,6]]
y_resp = a['Direction']


# Response
y_resp_train = a[a['Year']!= 2005]
y_resp_train= y_resp_train['Direction']

y_resp_test = a[a['Year']== 2005]
y_resp_test = y_resp_test['Direction']

# Predictors
X_preds_train = a[a['Year']!= 2005]
X_preds_train = X_preds_train[ ['Lag1', 'Lag2','Lag3','Lag4','Lag5', 'Volume']]

X_preds_test = a[a['Year']== 2005]
X_preds_test = X_preds_test[ ['Lag1', 'Lag2','Lag3','Lag4','Lag5', 'Volume']]

# Fit

# First, Try whole thing
lrw = LogisticRegression()
lrw.fit(X_preds, y_resp)
lrw.intercept_
Out[194]: array([-0.11454962])
pd.DataFrame( zip(X_preds.columns, np.transpose(lrw.coef_)))

Lag1  [-0.072790352441]
Lag2  [-0.0422910156882]
Lag3  [0.0109579963982]
Lag4  [0.00921799170451]
Lag5  [0.0102303109716]
Volume  [0.127939308787]

# Now fit the train data
lr.fit(X_preds_train, y_resp_train )

y_train_predictions1 = lr.predict(X_preds_train)
(y_train_predictions1 == y_resp_train).sum().astype(float)/y_resp_train.shape[0]
# 0.52 correct rate
# using built-in method, get the same result
lr.score(X_preds_train,y_resp_train)
# or using the following
from sklearn import metrics
metrics.accuracy_score(y_resp_train,y_train_predictions1)
Out[114]: 0.52805611222444893

# Try on test data
y_test_predictions1 = lr.predict(X_preds_test)
(y_test_predictions1 == y_resp_test).sum().astype(float)/y_resp_test.shape[0]
# 0.48 correct rate
# using built-in method, get the same result
lr.score(X_preds_test,y_resp_test)

lr.coef_
Out[101]: array([[-0.05423894, -0.04542453,  0.00745773,  0.00675954, -0.00405469, -0.09769463]])

lr.intercept_
# train data intercept and coefficients
</code></pre>
<p>Test data correct rate is only 48% which is worse than train and whole data. The reason would be the predictors selected. The R shows the p-value for each coefficients and they are not good.</p>

<h3>Now, let's use 'Lag1' and 'Lag2' only as predictors</h3>
<pre><code>
X_l1l2_not2005 = a[a['Year'] != 2005]
X_l1l2_not2005.head()
X_train = X_l1l2_not2005[['Lag1', 'Lag2']]
X_train.head()  # Train Predictors

X_l1l2_2005 = a[ a['Year'] == 2005 ]
X_l1l2_2005.head()
X_test = X_l1l2_2005[ ['Lag1', 'Lag2'] ]
X_test.head() # Test Predictors

lr2= LogisticRegression()
X_train_fit = lr2.fit(X_train, y_resp_train)

X_train_fit.score(X_train, y_resp_train)
# 0.51703406813627251 : correct rate for train data

y_train_predictions2 = lr2.predict(X_train)
lr2.score(X_train,y_resp_train)

# Try test data
y_test_predictions2 = lr2.predict(X_test)
(y_test_predictions2 == y_resp_test).sum().astype(float)/y_resp_test.shape[0]
# 0.55952380952380953 : correct rate for test data --> same to p160


</code></pre>

<p>After using predictors which has better p-value from the result of regression using whole data, the correct rate for test data is improved to 56%. But, it is still not good. May need to try other algorithm.</p>

<p>Try Linear Dscriminant Analysis <a href="../lda-qda/"> here</a>.</p>


