import java.util.Vector;

public class metastri {
    public static void main(String[] args) {
        int arr[]=new int[26];
        Vector vc=new Vector<>();
        vc.add("hello");
        
        
        //vc.removeElementAt(0);

        String str1="keegs",str2="geeks";
        int count=0;
        StringBuffer help1=new StringBuffer();
        StringBuffer help2=new StringBuffer();
        for(int i=0;i<str1.length();i++){
            if(str1.charAt(i)!=str2.charAt(i)){
                count++;
                help1.append(str1.charAt(i));
                help2.append(str2.charAt(i));
            }
            
            
        }
        str1.replace('e', '#');
        System.out.println(str1);
        help2.reverse();
        System.out.println(count);
        System.out.println(help1+"  "+help2);
        if(help2.equals(help1)) {
            System.out.println("yes"); 
        }
        else System.out.println("no");

        System.out.println(vc);
    }
}
