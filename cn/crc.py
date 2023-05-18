
def crc(data,divisor):
    data=[int(bit) for bit in data]
    divisor=[int(bit) for bit in divisor]
    for i in range(len(data)-len(divisor)+1):
        if data[i]==1:
            for j in range(len(divisor)):
                data[i+j]^=divisor[j]
                
    return ''.join([str(bit) for bit in data[-(len(divisor)-1):]])


def checkcrc(data,divisor):
    xoordiv=crc(data,divisor)
    if(int(xoordiv)==0): return 0
    else : return -1
    print(xoordiv)



data=str(input("enter the data"))

divisor=str(input("enter the divisor"))

datau=data+'0'*(len(divisor)-1)

ans=checkcrc(data,divisor)
print(ans)