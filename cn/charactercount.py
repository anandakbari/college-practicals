totalframes=int(input("enter the total number of frames"))
stuffed=""

frames=[input("enter the frame") for i in range(totalframes)]
    
for i in frames:
    length=str(len(i)+1)
    stuffed=stuffed+str(length)+i
    
print(stuffed)