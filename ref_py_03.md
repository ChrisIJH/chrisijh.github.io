---
layout: level1default 
permalink: /reference/ref_py_03/
---

<h1>Python 03</h1>

<h2>Enumerate</h2>


<pre><code>
<strong>def enum(**enums):
    return type('Enum', (), enums)</strong>
# class type(name, bases, dict)

# Now define enums as below:
SecurityType = enum(Unknown = "Unknown", Stock = "Stock", Option = "Option", Bond = "Bond",  Other = "Other")    
</code></pre>

<p>When using</p>

<pre><code>
class Security:
	def __init__(self, securityType, securityDesc,  currencyCode, exchangeCode, secType):
		self.SecurityType = <strong>SecurityType.Unknown</strong>
		self.Issuer = issuer
		self.SecurityCode = securityCode
		self.SecurityDesc = securityDesc
		self.CurrencyCode = currencyCode
		self.ExchangeCode = exchangeCode
		self.SecurityType = secType

</code></pre>


<h3>Built-in function: enumerate</h3>

<pre><code>
>>> seasons = ['Spring', 'Summer', 'Fall', 'Winter']
>>> list(enumerate(seasons))
[(0, 'Spring'), (1, 'Summer'), (2, 'Fall'), (3, 'Winter')]
>>> list(enumerate(seasons, start=1))
[(1, 'Spring'), (2, 'Summer'), (3, 'Fall'), (4, 'Winter')]
</code></pre>

<h2>Abstract Class</h2>

<pre><code>
<strong>import abc</strong>

class Security:

	<strong>__metaclass__ = abc.ABCMeta</strong>

	# Prevent instantiating this abstract class
	<strong>@abc.abstractmethod</strong>
	def __init__(self, securityType, securityDesc,  currencyCode, exchangeCode, secType):
		self.SecurityType = SecurityType.Unknown
		self.Issuer = issuer
		self.SecurityCode = securityCode
		self.SecurityDesc = securityDesc
		self.CurrencyCode = currencyCode
		self.ExchangeCode = exchangeCode
		self.SecurityType = secType
	...........
	...........

# Define a class to represent Stock security
class Stock(<strong>Security</strong>):
	def __init__(self, issuer, securityCode, securityDesc, currencyCode, exchangeCode, secType):
		<strong>super(Stock, self).__init__(issuer, securityCode, securityDesc, currencyCode, exchangeCode, secType)</strong>
		#initialize the member variables in the constructor. 
		self.SecurityType = SecurityType.Stock
</code></pre>

