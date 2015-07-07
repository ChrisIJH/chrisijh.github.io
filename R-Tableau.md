---
layout: level1default
permalink: /R-Tableau/
---

# Integrating R and Tableau Case 1:  Principal Component Analysis


Performed Principal Component Analysis of High School students performances of 3 major subjects in Maryland State 2014.


## Data 
**Variables**:  

School Name  
Algebra Adv Pct  
Algebra Proficient Pct  
Algebra Basic Pct  
English Adv Pct  
English Proficient Pct  
English Basic Pct  
Biology Adv Pct  
Biology Pforiceint Pct  
Biology Basic Pct  

###Data Sources
[Maryland State][1]
[1]: http://www.mdreportcard.org  
Files:
Algebra_2014.csv  
Biology_2014.csv  
English2_2014.csv  


## Steps

### Environment Setting

* /etc/Rserv.conf  
I used the minimal configuration for this project. By default, Rserve don't allow remote access. So, it should be in
config file. I used all others as default value.  

At /etc/Rserv.conf  

```sh
remote enable
```  
* Start the Rserve  
I started Rserve in daemon mode.  

```sh
> Rserve(args ="--no-save")
```   

* Check the connection from Tableau   
![alt text](https://www.evernote.com/shard/s9/sh/1ffc93a8-b50d-4256-a98a-555d288e8744/dcf0cd48e62336cd68ed249f83b55b11/deep/0/Windows-8.1---Parallels-Desktop.png)
![alt text](https://www.evernote.com/shard/s9/sh/db3ee21b-38ac-408f-adc7-6efe68870a19/ba39fa720ffaf1aa319cf9f6ce45d592/deep/0/Windows-8.1---Parallels-Desktop.png)

### Data Cleansing   
  - Collect the target columns only   
  In case of algebra data    
  
  ```sh
  alg = read.csv('files/algebra_2014.csv', header=T)
  names(alg) # Check all names
  keeps = c("School.Name","Advanced.Pct", "Proficient.Pct", "Basic.Pct" ) # The colomuns to keep
  alg = alg[keeps]
  names(alg)[2]= "alg.Advanced.Pct"
  names(alg)[3] = "alg.Proficient.Pct"
  names(alg)[4] = "alg.Basic.Pct"
  ```  
  
  - Change School Name to the format of "[School Name].[School Number]" since there are schools with same names.
  
  ```sh
  alg$School.Name = as.character(alg$School.Name)
  alg$School.Number = as.numeric(as.character(alg$School.Number))
  alg$School.Name = paste(alg$School.Name, alg$School.Number, sep=".")
  alg$School.Name = as.factor(alg$School.Name)
  alg=alg[,-1]
  ```
  
  - Delete the rows with '*' which don't have values  
  
  ```sh
  alg_df = subset(alg, alg.Advanced.Pct!="*" )
  eng_df = subset(eng, eng.Advanced.Pct!="*" )
  bio_df = subset(bio, bio.Advanced.Pct!="*" )
  ```  
  
  - Replace "<= 5.0" to 5.0  
  
  ```sh
  # English
  for (i in 2:dim(eng_df)[2]) {
    eng_df[,i] = as.character(eng_df[,i])
    eng_df[,i][eng_df[,i]=="<= 5.0"] = "5.0"
    eng_df[,i] = as.factor(eng_df[,i])
  }
  ```  
  
  - Merge 3 data frames and write a table  
  
  ```sh
  total = merge(alg_df, eng_df, by="School.Name")  
  total = merge(total, bio_df, by="School.Name")  

  write.table(total, file='total.csv', sep=',')  
  ```   
### Analysis and Visualization
  
* The frist one is simple visualizaion of data obtained from 3 different files about students performance per school per subject.
I created one parameter which selects "School" to see the data and one parameter which selects the variable.
 Then I created a Measure which takes the aggregate of the selected variable to show.  
The other is Principal Component Analysis. It gets factor scores from R and visualize at Tableau.  
The simple PCA routine used here is as below:  

```sh
pc.cr <- princomp(df, cor=TRUE) # PCA 
pc.cr # print PCA object
summary(pc.cr) # summarize results
loadings(pc.cr) # list loadings
res =pc.cr$sdev^2/sum(pc.cr$sdev^2)
scores = pc.cr$score
as.numeric(scores[,1])
```  

Tableau will call R with SCRIPT_*() at "calculated Fields" modifying the above R code as below:  

```sh
SCRIPT_REAL(
"n <- max(.arg10)
df <- data.frame(.arg1,.arg2,.arg3,.arg4, .arg5, .arg6, .arg7, .arg8, .arg9)
pc <- princomp(df, cor = TRUE) 
as.numeric(pc$scores[,n])
", 
SUM([alg.Advanced.Pct]),SUM([alg.Proficient.Pct]),SUM([alg.Basic.Pct]),
SUM([bio.Advanced.Pct]), SUM([bio.Proficient.Pct]), SUM([bio.Basic.Pct]),
SUM([eng.Advanced.Pct]), SUM([eng.Proficient.Pct]), SUM([eng.Basic.Pct]),[Component x]
)
```  

 
 Overall look is as below:
 
![alt text](https://www.evernote.com/shard/s9/sh/0b5eaac0-1f4d-469d-bc3e-6fd54c72c397/eaf34dec981d2667bf2b34930348e27d/deep/0/Windows-8.1---Parallels-Desktop.png)

![alt text](https://www.evernote.com/shard/s9/sh/3c16112a-f7bd-4751-a9f1-55cc7b21b22b/ea3250e1a61e9045c5c7dcbca6992a45/deep/0/Windows-8.1---Parallels-Desktop.png)
 
  
You can donwload the workbook at my github page or from direct link in the upper-left side.

### References:
[http://kb.tableausoftware.com/articles/knowledgebase/r-implementation-notes](http://kb.tableausoftware.com/articles/knowledgebase/r-implementation-notes)
[http://www.tableausoftware.com/about/blog/2013/10/tableau-81-and-r-25327](http://www.tableausoftware.com/about/blog/2013/10/tableau-81-and-r-25327)
[http://www.r-bloggers.com/dream-team-combining-tableau-and-r/](http://www.r-bloggers.com/dream-team-combining-tableau-and-r/)
[http://www.tableausoftware.com/learn/whitepapers/tableau-and-r-faq](http://www.tableausoftware.com/learn/whitepapers/tableau-and-r-faq)

  
  

