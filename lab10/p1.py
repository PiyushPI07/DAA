inf=float('Inf')

def path(i,j,p):
	if p[i][j] == None:
		print(None,end=" ")
		return 
	if i==j:
		print(i+1,end=" ")
		return 
	path(i,p[i][j],p)
	print(j+1,end=" ")
	return

def main():
	n=6

	a=[	[ 0 ,inf,inf,inf, -1,inf],
		[ 1 , 0 ,inf, 2 ,inf,inf],
		[inf, 2 , 0 ,inf,inf,-8 ],
		[-4 ,inf,inf, 0 , 3 ,inf],
		[inf, 7 ,inf,inf, 0 ,inf],
		[inf, 5 , 10,inf,inf, 0 ]	]
	
	m1=a

	p1=[[None for _ in range(n)] for _ in range(n)]

	for k in range(n):
		m2=[[None for _ in range(n)] for _ in range(n)]
		p2=[[None for _ in range(n)] for _ in range(n)]

		for i in range(n):
			for j in range(n):
				if m1[i][j]<=(m1[i][k]+m1[k][j]):
					m2[i][j]=m1[i][j]
					if p1[i][j]==None and m2[i][j]!=inf :
						p2[i][j]=i
					else:
						p2[i][j]=p1[i][j]
				else:
					m2[i][j]=m1[i][k]+m1[k][j]
					if p1[k][j]==None and m2[i][j]!=inf :
						if k==j:
							p2[i][j]=i
						else:
							p2[i][j]=k
					else:
						p2[i][j]=p1[k][j]
					
		for i in range(n):
			for j in range(n):
				m1[i][j]=m2[i][j]
				p1[i][j]=p2[i][j]


	for i in range(n):
		for j in range(n):
			print("Path from ", i+1," to ", j+1)
			path(i,j,p2)
			print("\n weight:",m2[i][j])


if __name__ == '__main__':
	main()