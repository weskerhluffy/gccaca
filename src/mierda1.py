i=1
n=3628800
m=n+111
while i*i<=n:
	x=n//i
	y=n//x
	x1=m//i
	y1=m//x1
	print("{} {} {} {} {}".format(i,x,y,x1,y1))
	i+=1
