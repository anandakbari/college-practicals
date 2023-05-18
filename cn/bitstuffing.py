data=input("enter the bit string")
print("og data",data)
counter=0
out=[]
stuffed=""

for i in data:
    out.append(i)
    if i=="0": counter=0
    elif i=="1": counter+=1
    if counter==5:
        out.append("0")
        counter=0
        
for i in out:
    stuffed+=i
    
print(stuffed)