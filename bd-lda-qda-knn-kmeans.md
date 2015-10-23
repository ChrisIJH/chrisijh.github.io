---
layout: level1default 
permalink: /bigdata/lda-qda-knn/
---

<h1>LDA</h1>

Implemented LDA introduced at "Introduction to Statistical Learning: With Applications in R. Chapter 4 Lab"

After we got the result from <a href="../logistic-regression">logistric regression</a>, LDA is tried to get the better result.
<h2>Using scikit-learn</h2>
<p>Direction as a response, "Lag1" and "Lag2" as predictors.</p>
<pre><code>
from sklearn.lda import LDA
lda = LDA()
lda.fit(X_train, y_resp_train)
lda.score(X_test, y_resp_test)
# 0.55952380952380953 correct rate
</code></pre>

<h1>QDA</h1>
<h2>Using scikit-learn</h2>
<pre><code>
from sklearn.qda import QDA
qda = QDA()
qda.fity(X_train, _resp_train)
qda.score(X_test, y_resp_test)
# 0.59920634920634919 correct rate

qda.means_
qda.priors_
qda.rotations_ 
qda.classes_ 
lda. priors_ 
lda. coef_ 

</code></pre>

<h1>KNN</h1>
<h2>Using scikit-learn</h2>
<pre><code>
from sklearn.neighbors import KNeighborsClassifier
knn = KNeighborsClassifier(3)
knn.fit(X_train, y_resp_train)
knn.predict(X_test)
knn.score(X_test,y_resp_test)
# 0.53174603174603174 correct rate
</code></pre>
<p>From this dataset and classification methods, QDA has the best correct rate.</p>
<!--
<h1>KMeans</h1>
<h2>Using scikit-learn</h2>
<pre><code>
from sklearn.cluster import KMeans
kmean = KMeans(n_clusters=2)
X_train.head()
y_resp_train.head()
kmean.fit(X_train, y_resp_train)


test_pred = kmean.predict(X_test)
print type(test_pred)
test_pred

y_pred_test = np.array(y_resp_test)
type(y_pred_test)
test_pred = np.where(test_pred==0, 'Down', 'Up')
(test_pred==y_resp_test).sum().astype(float)/len(y_resp_test)
# 0.48809523809523808 correct rate
</code></pre>
-->



<br>
<hr>
[References]
[1] James, Gareth, Daniela Witten, Trevor Hastie, and Robert Tibshirani. An Introduction to Statistical Learning: With Applications in R. Print.

[2] Hauck, Trent. Scikit-learn Cookbook. Packt, 2014. Print.