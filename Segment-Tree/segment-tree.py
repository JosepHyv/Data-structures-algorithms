st = []
INT_MIN = int( ( 1 << 32 )) * -1

def build( node, i, f, *array):
	if i == f:
		st[node] = array[f]
		return st[node]
	middle = ( i+f)//2
	left = ( node * 2)+1
	right = ( node * 2 ) + 2
	st[node] = ( build( left, i, middle ) + build(right, middle+1, f))
	return st[node]

def querry( node, i, f, li, ld, *array):

	 if i>ld or f < li:
		 return INT_MIN

	 if i >= li and f <= ld:
		 return st[node]

	 middle = ( i+f)//2
	 left = ( node * 2 )+1
	 rigth = ( node * 2)+2

	 return ( querry( left, i, middle, li, ld, array ) + querry( left, middle+1, f, li, ld, array) )

if __name__ == "__main__":
	task = [2,1,3,4,2,3,4]
	build(0, 0, (len(task)-1), *task )

	print( str( querry(0,0, (len(task))-1, 0, 4, *task) )  )
