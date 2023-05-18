import javax.annotation.processing.SupportedOptions;

public class revpattern {
    public static void main(String[] args) {
        for(int i=1;i<=3;i++){
            for(int k=0;k<3-i;k++) System.out.print("  ");
            for(int j=1;j<=(2*i)-1;j++){
                System.out.print("* ");
            }
            System.out.println();
        }

        for(int i=2;i>=1;i--){
            for(int k=1;k<=3-i;k++) System.out.print("  ");
            for(int j=(2*i)-1;j>=1;j--){
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
