import java.util.*;

public class ramdomgame {
    public static void main(String[] args) {
        Random rc=new Random();

        int player1=0,player2=0;
        float mean=0.0f;

        for(int i=0;i<5;i++){
            player1+=rc.nextInt(1000);
            player2+=rc.nextInt(1000);
        }

        for(int i=0;i<10;i++){
            mean+=rc.nextFloat(15,20);
           // System.out.println(mean);
        }
        System.out.println(mean/10);

        if(player1>player2) System.out.println("player1");
        else System.out.println("player2");
    }
}
