def mergeSort(alist):
	print "Splitting" , alist

	if len(alist) > 1:
		mid  = len(alist)//2
		lefthalf = alist[:mid]
		righthalf=alist[mid:]

		mergeSort(lefthalf)
		mergeSort(righthalf)

		i=0
		j=0
		k=0

		while i<len(lefthalf) and j<len(righthalf):
			if  lefthalf[i]<righthalf[j]:
				alist[k]=lefthalf[i]
				i+=1
			else:
				alist[k] = righthalf[i]
				j+=1
				pass
	else:
		pass