public class binary {
    public static void main(String[] args) {
        int num=10,num1=0,num2;
        int bin[]=new int[40];
        int index=0;
        while(num>0){
            num2=num%2;
            bin[index++]=num2;
            System.out.print(num2);
            num/=2;
        }
       
    }
}
