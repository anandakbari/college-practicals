import javax.print.attribute.standard.PrinterInfo;

class printing extends Thread{
    synchronized public void run() {
        for(int i=0;i<5;i++){
        System.out.print("*");
        try{
            Thread.sleep(1000);

        }catch(Exception e){}
        

    }
    
    }
}

class printingslash extends Thread{
    synchronized public void run(){
        for(int i=0;i<5;i++){
        System.out.print("/");
        try{
            Thread.sleep(1000);
            new printing().notify();


        }catch(Exception e){}
        

    }
    }
}



public class synchornisedth {
    public static void main(String[] args) {
        new printing().start();
       new printingslash().start();
    }
}
