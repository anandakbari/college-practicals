def checkpartiy(a,n,p,m):
    l=[]
    for i in range(2**(n-1)-1,len(a),2**n):
        l=l+a[i:i+2**(n-1)]
        print(l)
def transmit(d,par,m):
    ds=str(d)[::-1]
    p=0
    for i in range(len(ds)):
        if(2**i>=len(ds)+i+1):
            p=i
            break
        
    data=[]
    j=0
    k=0
    for i in range(0,len(ds)+p):
        
        if(i==2**j):
            data.insert(i-1,9)
            j=j+1
        else:
            data.insert(i,int(ds[k]))
            k=k+1
        
        for i in range(0,p):
            checkpartiy(data,i+1,par,m)
    trans = ''.join(str(i) for i in data)
    print(trans)
    
transmit(1011,1,1)