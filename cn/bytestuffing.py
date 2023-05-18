def characterstuffing(sflag,eflag,escape,x):
    stuffed=""
    data=[]
    data.append(sflag)
    
    for i in x:
        if(i==sflag or i==eflag): data.append(escape)
        elif(i==escape): data.append(escape)
        
        data.append(i)
    data.append(eflag)
    for i in data: stuffed+=i
    return stuffed


sflag=input("enter the start flag")
eflag=input("enter the end flag")
escape=input("enter the escape")
x=input("enter the data")

print(characterstuffing(sflag,eflag,escape,x))
    