---
layout: level1default 
permalink: /reference/ref_matrix_01/
---


# Matrix in python






Introduction
============

<h3>Fake Covariance Matrix then convert it to table</h3>

<pre><code>
factor_cols = [u'DIV', u'EARN', u'GR', u'LEV']
n = len(factor_cols)
Sigma = np.random.randn(n, n)
Sigma = Sigma.T.dot(Sigma)  # symmetric matrix
factor_cov_all = pd.DataFrame(columns=factor_cols, index=factor_cols, data=Sigma)  # dataframe
idx_triu  = np.triu(np.ones(factor_cov_all.shape)).astype(bool)  # upper triangular index, others are np.nan
factor_cov_triu = factor_cov_all.where(idx_triu).stack().reset_index()  # only upper triangular elements --> stack()
factor_cov_triu.columns = ['factor1', 'factor2', 'factor_value']
factor_cov_triu['date'] = '2016-01-02'

</code></pre>

<h3>Covariance Matrix from table to numpy matrix</h3>

<pre><code>
del factor_cov_triu['date']
factor_cov_triu_indxd = factor_cov_triu.set_index(['factor1', 'factor2'])
factor_df = factor_cov_triu_indxd.unstack(level=1)  ## matrix like dataframe with only upper triangular values and others nan.
cov_n = factor_df.values
idx = np.triu(cov_n).astype(bool)
cov_n.T[idx] = cov_n[idx]
</code></pre>
