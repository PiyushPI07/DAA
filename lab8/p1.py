class BinaryHeap:
	def __init__(self):
		self.l=[None]

	def size(self):
		return len(self.l)-1

	def buildHeap(self,a):
		for x in a:
			self.l.append(x)
		for i in range(len(self.l)-1,0,-1):
			self.heapify(i,len(self.l))

	def heapify(self,i,l):
		while 2*i<l:
			if l==2*i+1 or self.l[2*i].f<self.l[2*i+1].f:
				j=2*i
			else:
				j=2*i+1
			if self.l[i].f>self.l[j].f:
				self.swap(i,j)
			i=j


	def insert(self,k):
		self.l.insert(1,k)
		self.heapify(1,len(self.l))

	def printHeap(self):
		print (self.l[1:])


	def swap(self,a,b):
		t=self.l[a]
		self.l[a]=self.l[b]
		self.l[b]=t

	def maximum(self):
		return (self.l[1])

	def extractMin(self):
		if self.size()==1:
			return self.l.pop()
		max=self.l[1]
		self.l[1]=self.l.pop()
		self.heapify(1,len(self.l))		
		return max

	def traverse(self):
		i=1
		while i<len(self.l):
			if i in (2,4,8,16):
				print("")
			print(self.l[i].f,end=", ")
			i=i+1


class node:
	def __init__(self,s,f,l=None,r=None):
		self.s=s
		self.f=f
		self.left=l
		self.right=r
		self.code=[]

def fringe(root,l):
	if root.left:
		a=l[0:]
		a.append(0)
		fringe(root.left,a)
	if root.right:
		a=l[0:]
		a.append(1)
		fringe(root.right,a)
	if root.s:
		root.code=l

def main():
	S=['a','b','c','d','e','f']
	F=[20 ,12 , 10, 8 , 4 , 3 ]
	leaves=[]
	for i in range(len(S)):
		leaf=node(S[i],F[i])
		leaves.append(leaf)
	H=BinaryHeap()
	H.buildHeap(leaves)


	while H.size()>1:
		x=H.extractMin()
		y=H.extractMin()
		n=node(None,x.f+y.f,x,y)
		H.insert(n)

	root=H.extractMin()
	fringe(root,[])
	size=0
	for n in leaves:
		size=size+n.f*len(n.code)
		print(n.s,n.code)
	print("size=",size)



if __name__ == '__main__':
	main()