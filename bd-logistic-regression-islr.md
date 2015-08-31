---
layout: level1default 
permalink: /bigdata/logistic-regression-islr/
---

<h1>Logistic Regression</h1>

<h2>ISLR ch4 R code</h2>


<pre><code>
# From textbook
setwd("~/Box Sync/EBOOK-A-J/bigdata/courses/statistical learning")

# Default data set is in ISLR package
names(Default)
dim(Default)
pairs(Default)
attach(Default)

glm.Default = glm(default ~ student+balance+income, data=Default, family=binomial)
summary(glm.Default)

glm.default_prob = predict(glm.Default, Default, type="response")
summary(glm.default_prob)
plot(balance, glm.default_prob)
boxplot(student,balance)
boxplot(default, balance)
boxplot(default, income)

# Lab
library(ISLR)
names(Smarket)
dim(Smarket)
summary(Smarket)
pairs(Smarket)
cor(Smarket[,-9])

write.table(Smarket, file="Smarket.txt", row.names=FALSE)

attach(Smarket)
plot(Volume, pch=20)

glm.fit = glm(Direction~Lag1+Lag2+Lag3+Lag4+Lag5+Volume,data=Smarket,family=binomial)
summary(glm.fit)
coef(glm.fit)
summary(glm.fit)$coef
names(summary(glm.fit))

glm.probs=predict(glm.fit, type="response")
summary(glm.probs)
glm.probs[1:20]
contrasts(Direction)
?contrasts

# Now divide the data to 2 groups: one is 2001~ 2004 for training, the other is 2005 for test data.

# Divide part
train = (Year<2005)
train
Smarket.2005 = Smarket[!train,]
dim(Smarket.2005)
Direction.2005 = Direction[!train]

# Training part
glm.fit = glm(Direction~Lag1+Lag2+Lag3+Lag4+Lag5+Volume,data=Smarket,family=binomial, subset=train) 
summary(glm.fit)
glm.prob = predict(glm.fit, Smarket.2005, type="response")
glm.prob
glm.pred=rep("Down", 252)
glm.pred[glm.prob>0.5] = "Up"
glm.pred
table(glm.pred, Direction.2005)
mean(glm.pred==Direction.2005)

# Since the result is still not good, find a better way. So, this time use only flausible variables
# which are Lag1 and Lag2.

glm.fit = glm(Direction ~ Lag1+Lag2, data=Smarket, family=binomial, subset=train)
glm.probs = predict(glm.fit, Smarket.2005, type="response")
glm.pred = rep("Down", 252)
glm.pred[glm.probs>0.5] = "Up"
table(glm.pred, Direction.2005)
mean(glm.pred==Direction.2005)

# LDA

library(MASS)
lda.fit = lda(Direction~Lag1+Lag2, data=Smarket, subset=train)
lda.fit
plot(lda.fit)

lda.pred = predict(lda.fit, Smarket.2005)
names(lda.pred)
lda.class = lda.pred$class
table(lda.class, Direction.2005)

# QDA

qda.fit = qda(Direction~Lag1+Lag2, data=Smarket, subset=train)
qda.fit
qda.class=predict(qda.fit, Smarket.2005)$class
table(qda.class,Direction.2005)
mean(qda.class==Direction.2005)

# KNN
library(class)
train.X = cbind(Lag1, Lag2)[train,]
test.X = cbind(Lag1, Lag2)[!train,]
train.Direction=Direction[train]

set.seed(1)
knn.pred=knn(train.X, test.X, train.Direction, k=1)
table(knn.pred, Direction.2005)
mean(knn.pred == Direction.2005)

knn.pred=knn(train.X, test.X, train.Direction, k=3)
table(knn.pred, Direction.2005)
mean(knn.pred == Direction.2005)

</code></pre>