

class prime extends Thread{

    public void run(){
        long startTime = System.nanoTime();



        int number=0;
        for(int i=2;i<100;i++){
            int count=0;
            for(int j=2;j<i;j++){
                if(i%j==0){

                    count=1;
                    break;
                }
                
                
            }
            
            if(count==0&&number++<20) {
                System.out.println(i);
            }
        }
        long endTime   = System.nanoTime();
        long totalTime = endTime - startTime;
        System.out.println((double)totalTime);
    }
}

class fibonacci extends Thread{
    public void run(){
        int num1=0;
        int num2=1;
        int numb=num1+num2;
        for(int i=0;i<15;i++){
            System.out.println(numb);
            num1=num2;
            num2=numb;
            numb=num1+num2;
        }
    }
}


public class childt {
    public static void main(String[] args) {
        prime t=new prime();
   // t.start();
        new fibonacci().start();
    }
    
}
