public class dectohex {
    public static void main(String[] args) {
        System.out.println(Integer.toHexString(10));
        String hexx="";
        char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
        int dec=289;

        while(dec>0){
            int x=dec%16;
            hexx+=hex[x];
            dec/=16;
        }
        System.out.println(hexx);
    }
}
