package mypackage;

abstract class calarea{
    abstract void area();
}


class sqaure extends calarea{
   protected int side;

public sqaure(int side){
    this.side=side;
}

public void area(){
    System.out.println(side*side);
}
}

class traingle extends calarea{
    int side,base;
    
    public traingle(int side,int base){
        this.side=side;
        this.base=base;
        
    }
    
    public void area(){
        System.out.println((float)(0.5*side*base));
    }
    }



public class sqaureabt {
    public static void main(String[] args) {
        sqaure s=new sqaure(4);
        s.area();
        s.side=3;
        traingle d=new traingle(4, 2);
        d.area();
    }
}
