import java.util.Scanner;

public class studentmarksmatrix {
    public static void main(String[] args) {
        int row=3,col=3;
        int matrix[][]=new int[row+1][col+1];
        Scanner sc=new Scanner(System.in);
        for(int i=0;i<row;i++){
            int sum=0;
            for(int j=0;j<col;j++){
                matrix[i][j]=sc.nextInt();
                sum+=matrix[i][j];
            }
            matrix[i][row]=sum;
        }

        for(int i=0;i<row+1;i++){
            int sum=0;
            for(int j=0;j<col+1;j++){
                 sum+=matrix[j][i];
            }
            matrix[col][i]=sum;
        }

        for(int i=0;i<row+1;i++){
            
            for(int j=0;j<col+1;j++){
                 System.out.print(matrix[i][j]+" ");
            }
           
            System.out.println();
    
            }    }
}
