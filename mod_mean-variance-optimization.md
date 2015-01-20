---
layout: level1default
permalink: /modeling-analysis/mvo/
---

# Mean Variance Optimization using VBA, Matlab, and Python

The classical mean variance optimization is keynote technique for all other porfolio optimization techniques. In this page,
I implemented it with various languages with boundary constraints with -0.5 and 1.

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

Return Data is stored in this way from matlab.  
![data](https://www.evernote.com/shard/s9/sh/6f85072a-87c4-4c44-ba54-24a787918842/991a4b7fbaf53c8c07f38fb2d34d7fbf/deep/0/Windows-8.1---Parallels-Desktop.png)  
The worksheet name is "DATA" and data is names as "returnData".

#### Average returns and Standard Deviations  

First step is to get the data size for preceding work. The worksheet 'MV' is the workspace in this case.   

    'Step 1: Get the  number of Assets
    Set returnRange = Range("returnData")
    nofAssets = returnRange.Columns.Count
    
    Worksheets("MV").Activate
    ActiveSheet.Range("A2").Value = "Number of Assets:"
    ActiveSheet.Range("A2").Select
    ActiveCell.Offset(0, 1).Value = nofAssets
    
    ReDim arrAssets(nofAssets)
    ReDim arrMeanReturns(nofAssets)
    ReDim arrStds(nofAssets)
    
    
Then, find the size of the data.

    nofData = returnRange.Rows.Count  
    
Next, read the symbols from "DATA" worksheet and write them on "MV" worksheet. 

    'Step 3: locate the Assets in worksheet MV
    'workshet MV "B5" vertically
        'First read the Asset names
    Worksheets("DATA").Activate
    ActiveSheet.Range("A1").Select
    For i = 1 To nofAssets
        arrAssets(i - 1) = ActiveCell.Offset(0, i).Value
    Next i
        'Second write the assets names in worksheet MV
    Worksheets("MV").Activate
    ActiveSheet.Range("B4").Select
    For i = 1 To nofAssets
        ActiveCell.Offset(i, 0).Value = arrAssets(i - 1)
    Next i
 
Now, compute average returns and standard deviations.

    'Step 4: Compute returns and stds
    Worksheets("DATA").Activate
    ActiveSheet.Range("returnData").Select
    nofRows = Selection.Count() / nofAssets
    'Another way of get the number of rows --> Selection.count() is rows * columns. So divide it by columbs to get # of rows
    ReDim arrAllReturns(nofRows, nofAssets)
        'Find the mean
    ActiveSheet.Range("A1").Select
    For j = 1 To nofAssets
        Sum = 0
        For i = 1 To nofRows
            Sum = Sum + ActiveCell.Offset(i, j).Value
        Next i
        mean = Sum / nofRows
        arrMeanReturns(j - 1) = mean
    Next j
    
        'Find the Stds
    For j = 1 To nofAssets
        squareSum = 0
        For i = 1 To nofRows
            squareSum = squareSum + (ActiveCell.Offset(i, j).Value - arrMeanReturns(j - 1)) ^ 2
        Next i
        Std = Sqr(squareSum / (nofRows - 1))
        arrStds(j - 1) = Std
    Next j
    
Then, write the average returns and standard deviations.

    'Step 5: Write the mean value from column "C5" for mean, from column "D5" for Stds vertically
    Worksheets("MV").Activate
    ActiveSheet.Range("C4").Select
    For i = 1 To nofAssets
        ActiveCell.Offset(i, 0).Value = arrMeanReturns(i - 1)
        ActiveCell.Offset(i, 1).Value = arrStds(i - 1)
    Next i
    Range(ActiveCell.Offset(1, 0), ActiveCell.Offset(nofAssets, 0)).Name = "meanRet"

#### Variance Covarianve Matrix, Solver, and Graph


    'Find correlations and Covariance
        'Create the 2 dim all data array

    Worksheets("DATA").Activate
    ActiveSheet.Range("A1").Select
    
    For i = 1 To nofAssets
        For j = 1 To nofData
            arrAllReturns(j - 1, i - 1) = ActiveCell.Offset(j, i).Value
        Next j
    Next i

    For i = 1 To nofAssets ' columns
        arrX = IJfuncTakeCol(arrAllReturns, i - 1)
        For j = 1 To nofAssets
            arrY = IJfuncTakeCol(arrAllReturns, j - 1)
            arrCorrelations(i - 1, j - 1) = IJfuncCorrArr(arrX, arrY)
            arrCov(i - 1, j - 1) = IJfuncCovArr(arrX, arrY)
        Next j
    Next i

        'write  corr
    Worksheets("MV").Activate
    ActiveSheet.Range("F4").Select
    For i = 1 To nofAssets ' row
        For j = 1 To nofAssets ' column
            ActiveCell.Offset(i, j).Value = arrCorrelations(i - 1, j - 1)
        Next j
    Next i
    
        'write Cov with Assets names
    ActiveCell.Offset(nofAssets + 3, 0).Select
    Selection.Value = "VCV"
        ' vertically
    For i = 1 To nofAssets
        ActiveCell.Offset(i, 0).Value = arrAssets(i - 1)
    Next i
        ' horizontally
    For i = 1 To nofAssets
        ActiveCell.Offset(0, i).Value = arrAssets(i - 1)
    Next i
        ' write vcv
    For i = 1 To nofAssets ' row
        For j = 1 To nofAssets ' column
            ActiveCell.Offset(i, j).Value = arrCov(i - 1, j - 1)
        Next j
    Next i
    
    Range(ActiveCell.Offset(1, 1), ActiveCell.Offset(nofAssets, nofAssets)).Name = "vcv"

In order to find efficient frontier, solver is used. solver can be used this way in VBA.

    'Efficient Frontier
    ActiveCell.Offset(nofAssets + 3, 0).Select
    Selection.Value = "Solver"
    
    Maxi = 0.035
    Mini = Application.Max(WorksheetFunction.Min(arrMeanReturns), 0)
    'Find mean returns and stds
    n = 10 ' iteration number
    interval = (Maxi - Mini) / n
    ReDim weight(n)
    ActiveCell.Offset(1, 0).Value = "Target Return"
    'write asset names
    For i = 1 To nofAssets
        ActiveCell.Offset(i + 1, 0).Value = arrAssets(i - 1)
    Next i
    ActiveCell.Offset(nofAssets + 2, 0).Value = "Weight Sum"
    ActiveCell.Offset(nofAssets + 3, 0).Value = "Exp Return"
    ActiveCell.Offset(nofAssets + 4, 0).Value = "Std"
    ActiveCell.Offset(nofAssets + 5, 0).Value = "Var"
    
    targetReturn = Mini
    
    'solver initialize
    
    ActiveCell.Offset(1, 1).Value = targetReturn
    ActiveWorkbook.Names.Add Name:="targetRet", RefersTo:=ActiveCell.Offset(1, 1)
        'write weight
    For j = 2 To (nofAssets + 1)
        ActiveCell.Offset(j, 1) = 1 / nofAssets
    Next j
    Range(ActiveCell.Offset(2, 1), ActiveCell.Offset(nofAssets + 1, 1)).Name = "w"
    
        'weight sum
    ActiveCell.Offset(nofAssets + 2, 1).Formula = "=sum(w)"
    ActiveWorkbook.Names.Add Name:="weightSum", RefersTo:=ActiveCell.Offset(nofAssets + 2, 1)
        'Expected return
    ActiveWorkbook.Names.Add Name:="expRet", RefersTo:=ActiveCell.Offset(nofAssets + 3, 1)
    ActiveCell.Offset(nofAssets + 3, 1).Formula = "=sumproduct(w,meanRet)"
    
     'variance
    ActiveCell.Offset(nofAssets + 5, 1).FormulaArray = "=MMULT(Transpose(w),MMULT(vcv,w))"
    ActiveWorkbook.Names.Add Name:="var", RefersTo:=ActiveCell.Offset(nofAssets + 5, 1)
    
        'Std
    ActiveCell.Offset(nofAssets + 4, 1).Formula = "=sqrt(var)"
    ActiveWorkbook.Names.Add Name:="std", RefersTo:=ActiveCell.Offset(nofAssets + 4, 1)
   
       
    
    For i = 0 To n ' column side
        ActiveCell.Offset(1, 1).Value = targetReturn
        
        Call IJmainSolver
        
        ActiveCell.Offset(1, i + 2) = targetReturn
        'write weight
        For j = 2 To (nofAssets + 1)
            ActiveCell.Offset(j, i + 2) = ActiveCell.Offset(j, 1).Value
        Next j
       
        'weight sum
        ActiveCell.Offset(nofAssets + 2, i + 2).Formula = ActiveCell.Offset(nofAssets + 2, 1).Value
        'Expected return
        ActiveCell.Offset(nofAssets + 3, i + 2) = ActiveCell.Offset(nofAssets + 3, 1).Value
        'Std
        ActiveCell.Offset(nofAssets + 4, i + 2) = ActiveCell.Offset(nofAssets + 4, 1).Value
        'variance
        ActiveCell.Offset(nofAssets + 5, i + 2) = ActiveCell.Offset(nofAssets + 5, 1).Value
        targetReturn = targetReturn + interval
    Next i
    
Then, graph it.

        'x-axis
    Range(ActiveCell.Offset(nofAssets + 4, 2), ActiveCell.Offset(nofAssets + 4, n + 2)).Name = "xStd"
        'y-axis
    Range(ActiveCell.Offset(nofAssets + 3, 2), ActiveCell.Offset(nofAssets + 3, n + 2)).Name = "yExpRet"
    
    Call createChart
    

### Result
 ![res](https://www.evernote.com/shard/s9/sh/5fc2ba11-fada-40c5-8503-e8c2108051a8/b6dcea9aa352729ce4aa59bcca6bab72/deep/0/mean_variance_auto_temp2---Excel.png)  
 
 
### Find Global Minimum Variance Portfolio(GMVP)

    Sub findGMVP()

    Dim nofAssets As Integer
    Dim margin As Integer
    Dim columnUnitVec() As Integer
    Dim columnGMVP() As Integer
    Dim i As Integer

    margin = 18
    nofAssets = Range("B2").Value
    
    ActiveSheet.Range("F2").Select
    ActiveCell.Offset(margin + 3 * nofAssets, 0).Select
    ActiveCell.Value = "Unit Vector"
    ActiveCell.Offset(0, 1).Value = "GMVP"
    
    ReDim columnUnitVec(nofAssets)
    ReDim columnGMVP(nofAssets)
    
    For i = 1 To nofAssets
        columnUnitVec(i - 1) = 1
        ActiveCell.Offset(i, 0) = 1
    Next i
    Range(ActiveCell.Offset(1, 0), ActiveCell.Offset(nofAssets, 0)).Name = "unitColumnVector"
    ActiveCell.Offset(1, 1).Select
    Range(ActiveCell, ActiveCell.Offset(nofAssets - 1, 0)).FormulaArray _
    = "=MMULT(vcv,unitColumnVector)/SUM(MMULT(vcv,unitColumnVector))"

    End Sub  


 ![gmvp](https://www.evernote.com/shard/s9/sh/992f377d-45a8-40c0-98e0-039d48211635/c8a3e5b011792e33d6534d5013523cba/deep/0/Windows-8.1---Parallels-Desktop.png)  
 
### Compare Indifference Curves  
 
 ![ind](https://www.evernote.com/shard/s9/sh/cb691a8c-5be4-4a77-8d89-8e5ede4d4122/27ccfde997c227ff43d3d51085469ba8/deep/0/Windows-8.1---Parallels-Desktop.png)  
 
### Complete Portfolio with risk free return 0.009 and risk averse index A = 4  

 ![com](https://ee54942d-a-62cb3a1a-s-sites.googlegroups.com/site/chrisijhwang/calendar/mvo/Windows%208.1%20-%20Parallels%20Desktop-3.jpg?attachauth=ANoY7croafu1bHY8XpQ5sRuwyqeLfbg-hkeXb9IXqXy_oXDm8G40vzOPXTQzZANmqKXzNPUV3aFalsCvaCVvbusAUCnJ_lfBFsm9RwFJ8I9Hge8ZzsRnTZjE7J_X1NW2e-Q2znRymypav7FVEl1AVD1hcKZqcw0Hnf8TsfUCL2I-jehby9MzEt5XvD45IyIouAAj_txbzGebHUcE4w0FcZVrKbbu5MQ9pHJ7CYkO8jUG0VBqukwNjrm7EwHqQ3w_Fy_gIPVnlPE9G3CAePLaArjmBdzaqz0REg%3D%3D&attredirects=0)  
 
 
<hr>

## Matlab Implementation

 ![mat](https://www.evernote.com/shard/s9/sh/958f24ae-57eb-424a-a415-8d5db80dcac9/6218e537b681b0f5d6737add6585c7a7/deep/0/Editor---Z--Documents-Dev-Matlab-Mathworks-portfoliodemo-MVO_forweb.m.png)  
 ![gra](https://www.evernote.com/shard/s9/sh/55acb1e8-1d9d-4b34-954e-16a686c8fe33/2e1011a3a42f1d6d3a32b1626afcf29e/deep/0/-Student-Version--Figure-3.png)  
 
<hr>
## Python Implementation

    __author__ = 'hwang'

    import pandas as pd
    import numpy as np
    from cvxopt import matrix, solvers
    import matplotlib.pyplot as plt
    from pandas import Series
    
    # Read return data from Excel
    data = pd.read_excel('data.xlsx', 'Sheet1', index='Date')
    data = data.drop('Date', 1)
    
    meanRets_ls=[] # mean return values
    for tic in data.columns.values:
        meanRets_ls.append(data[tic].mean())
    
    
    # Varianca Covariance Matrix
    CVC =data.cov()
    CORR = data.corr() # Correlation matrix
    
    # Prepare CVXOPT optimization
    np_cvc = np.matrix(CVC)
    Q = matrix(np_cvc)
    print(Q)
    
    p = matrix(np.zeros(10), (10,1))
    print(p)
    IDE = np.eye(10)
    
    G = matrix(IDE)
    print(G)
    
    h = matrix(np.ones(10))
    print(h)
    
    meanRets_arr = np.array( [meanRets_ls])
    
    temp =np.array( [np.ones(10)] )
    
    A = np.concatenate( (temp, meanRets_arr), axis=0)
    A = matrix(A)
    
    print(A)
    b = matrix([ 1.0, 0 ])
    print(b)
    
    # Efficient Frontier
    idex = [data.columns.values]
    weight_df = pd.DataFrame(index=idex)
    stds=[]
    finalMean=[]
    
    targetRet = [0, 0.0035 ,0.007, 0.0105, 0.014, 0.0175, 0.021, 0.0245, 0.028, 0.0315, 0.035]
    
    for tr in targetRet:
        b = matrix( [1.0, tr])
        sol = solvers.qp(Q, p, G, h, A, b)
        solv = sol['x']
        weight_df[str(tr)] = Series(sol['x'], index=data.columns.values)
        stds.append(np.ndarray.tolist(np.dot(np.dot(solv.T,CVC),solv)))
        finalMean.append(np.ndarray.tolist(np.dot(solv.T,meanRets_ls)))
    
    stds = np.sqrt(stds)
    stds = [stds[i][0][0] for i in range(10)]
    finalMean = [ finalMean[i][0] for i in range(10) ]
    plt.figtext(0.15,0.6,"Efficient Frontier")
    plt.xlabel("Standard Deviation")
    plt.ylabel("Returns")
    plt.plot(stds,finalMean)
    plt.show()
    
    
 ![mat](https://ee54942d-a-62cb3a1a-s-sites.googlegroups.com/site/chrisijhwang/calendar/mvo/Figure%201-3.jpg?attachauth=ANoY7co6UXaBF4Lb60SWmWBdZfeZHCvoiYM8fNTqWuICeeq5Ns_2mRf6kPp0p_3xNKKL98chK9A66I851MXI2BG_lZQHMp0Yv6ipSjjBcZBOi0Cv73ex7vOwtwqixr2iRvcogNrOWHE1HzFjQ2W4VwB2gmMcMg5Sa-Q6Er-2hxMqKJ-_AiQY6owOCPKOsXIrTRRiIhnL3bTffhjKuA3k3i46j64BlkvLoU8B8kHoV4pOEW9jxa56Sf4%3D&attredirects=0)  
 
 
 
 
 
References:

[1] Matlab R2014a Document  
[2] Markowitz, H. (1952) Portfolio Selection. The Journal of Finance, Vol. 7, No. 1, pp. 77-91. March. 1952.  
[3] Benninga, Simon. Financial Modeling. Cambridge, MA: MIT, 2014. Print.  
[4] Bodie, Zvi, Alex Kane, and Alan J. Marcus. Investments. Boston, MA: McGraw-Hill Irwin, 2005. Print.    