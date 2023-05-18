import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.*;
import java.awt.GridBagConstraints;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.util.Formatter;
import java.util.*;
import javax.swing.*;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import javax.swing.border.Border;


public class butttons extends JFrame{
    JFrame frame=new JFrame("buttons example");
    JLabel passwordlabel=new JLabel("password");
    JLabel usernamelabel=new JLabel("username");
    JButton btn1=new JButton("button1");
    JButton btn2=new JButton("button2");

    JTextField usernamefield=new JTextField(20);
    JPasswordField passwordfield=new JPasswordField(20);
    JTextArea msg=new JTextArea();

    public butttons(){

        JPanel panel=new JPanel();
        usernamelabel.setLabelFor(usernamefield);
        passwordlabel.setLabelFor(passwordfield);
        panel.setLayout(new GridBagLayout());
        GridBagConstraints c=new GridBagConstraints();
        c.insets=new Insets(5,5,5,5);

        c.gridx=0;
        c.gridy=0;
        
        panel.add(usernamelabel,c);
        

        c.gridx=1;
        c.gridy=0;
        panel.add(usernamefield,c);

        c.gridx=0;
        c.gridy=1;
        panel.add(passwordlabel,c);

        c.gridx=1;
        c.gridy=1;
        panel.add(passwordfield,c);

        c.gridy=2;
        c.gridx=0;       
        panel.add(btn1,c);

        c.gridx=1;
        c.gridy=2;
        panel.add(btn2,c);

        c.gridx=2;
        c.gridy=0;
        panel.add(btn2,c);

        c.gridx=3;
        c.gridy=0;
        panel.add(btn1,c);

    btn1.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent e){
        JOptionPane.showMessageDialog(frame, "login successfull!!!");
        usernamefield.setText("");
        passwordfield.setText("");
    }
}
    );

    btn2.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            usernamefield.setText("");
            passwordfield.setText("");
        }
    }
        );

       

    



        frame.add(panel);
        frame.setSize(600,600);
        
        frame.setVisible(true);

    }
    public static void main(String[] args) {
        new butttons(); 
    }
}
