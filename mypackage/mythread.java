import java.awt.*;
import java.net.MalformedURLException;
import javax.swing.*;
import javax.swing.JFrame;
import javax.swing.JLabel;

class mythread extends JFrame{

   
    public mythread() throws MalformedURLException{
        JFrame frame=new JFrame("menu and bar");
        JLabel l1=new JLabel("username",JLabel.LEFT);
        JLabel l2=new JLabel("password",JLabel.LEFT);
        JTextField field1=new JTextField(10);
        JPasswordField field2=new JPasswordField(10);
        JPanel panel=new JPanel();
        
        panel.setLayout(new GridLayout(2,2,1,5));

        
        //l1.setLabelFor(field);
       // l2.setLabelFor(field2);
        panel.add(l1);
        panel.add(field1);
        panel.add(l2);
        panel.add(field2);
       
            frame.setContentPane(panel);
            frame.pack();
        frame.setSize(600,600);
        
        frame.setVisible(true);
         frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
       
    }
    public static void main(String args[]) throws MalformedURLException {
         mythread mt=new mythread();
}
}
    