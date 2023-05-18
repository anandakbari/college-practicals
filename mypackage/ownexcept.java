import java.io.IOException;

/*class ownexecption extends Exception{
   public ownexecption(String err){
        super(err);
        sendmes(err);
        
    }public void sendmes(String err){
        System.out.println(err);
    }
}

class studentmarks {
    int marks;

    public studentmarks(int marks) throws IOException{
        this.marks=marks;
        checkmarks(marks);
    }

    public void checkmarks(int marks) throws IOException{
        
            if(marks>100){
                //throw new ownexecption("marks greater than 100");
                System.out.println("haha");
            }
        
        
            
        
    }
} */

public class ownexcept {
    public static void main(String[] args)  {
       

        double x=Math.sqrt(-20);
        System.out.println(x);
    }
}
