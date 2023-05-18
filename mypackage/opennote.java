import java.io.IOException;

public class opennote {
    public static void main(String[] args) {
        Runtime rt=Runtime.getRuntime();
        try {
            rt.exec("notepad");
        } catch (IOException e) {
            
            e.printStackTrace();
        }
       
    }
}
