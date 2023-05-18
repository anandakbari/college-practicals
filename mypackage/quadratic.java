public class quadratic {
    public static void main(String[] args) {
        int n=args.length;
        int x=Integer.parseInt(args[0]);
        int y=Integer.parseInt(args[1]);
        int z=Integer.parseInt(args[2]);
        
        System.out.println((x>y)?(x>z)?x:z:(y>z)?y:z);
    }
}
