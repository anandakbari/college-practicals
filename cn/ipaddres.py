ip=str(input("enter the ip address"))

ipl=ip.split(".")
class1=""
subnet_mask=""
subnet_add=""

if(len(ipl)==4):
    if(int(ipl[0])) in range(0,127):
        class1=class1+"A"
        subnet_mask="255.0.0.0"
    elif(int(ipl[0])) in range(128,191):
        class1=class1+"B"
        subnet_mask="255.255.0.0"
        
    elif(int(ipl[0])) in range(192,223):
        class1=class1+"C"
        subnet_mask="255.255.255.0"
    
    elif(int(ipl[0])) in range(224,239):
        class1=class1+"D"
        subnet_mask="multicast"
        
    elif(int(ipl[0])) in range(240,255):
        class1=class1+"E"
        subnet_mask="reserved"
        
    else:
        print("enter correct ip")
        
mask=subnet_mask.split(".")

for i in range(len(ipl)):
    subnet_add=subnet_add+str((int(ipl[i])&int(mask[i])))+"."
subnet_add=subnet_add[:len(subnet_add)-1] 
print(subnet_add,ip,subnet_mask)