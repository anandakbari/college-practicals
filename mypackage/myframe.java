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

public class myframe extends JFrame{
    JFrame frame=new JFrame("Registration Form");
    JLabel usernamelabel=new JLabel("username");
    JLabel passwordlabel=new JLabel("password");
    JLabel namelabel=new JLabel("name");
    JLabel sapidlabel=new JLabel("Sapid");

    JCheckBox male=new JCheckBox("male");
    JCheckBox female=new JCheckBox("female");
    JLabel genderlabel=new JLabel("gender");

    JTextField usernamefield=new JTextField(20);
    JTextField namefield=new JTextField(20);
    JTextField sapidfield=new JTextField(20);
    JPasswordField passwordfield= new JPasswordField(20);

    JTextArea rr=new JTextArea();

    

    JPanel panel=new JPanel();
    JPanel rPanel=new JPanel();

    String username,password,sapid,name;
    
    public myframe() throws IOException{
        JButton submitbutton=new JButton("submit");

        usernamelabel.setLabelFor(usernamefield);
        passwordlabel.setLabelFor(passwordfield);
        namelabel.setLabelFor(namefield);
        sapidlabel.setLabelFor(sapidfield);
    
        panel.setLayout(new GridBagLayout());
        Border blackline=BorderFactory.createLineBorder(Color.BLACK);
        panel.setBorder(blackline);

        GridBagConstraints c=new GridBagConstraints();

        c.insets=new Insets(10,10,0,0);
        //c.gridx=0;
        c.gridy=0;
        c.gridwidth=1;
        c.weightx=0;
        c.weighty=1;
        panel.add(usernamelabel,c);

        c.gridx=1;
        
        //c.gridy=0;
        panel.add(usernamefield,c);

        

        c.gridy=1;
        panel.add(passwordfield,c);

        c.gridx=0;
        c.gridwidth=1;
        c.weightx=0;
        c.weighty=1;
        panel.add(passwordlabel,c);

        c.gridx=0;
        c.gridy=2;
        panel.add(namelabel,c);

        c.gridx=1;
        panel.add(namefield,c);

        c.gridy=3;
        panel.add(sapidfield,c);

        c.gridx=0;
        panel.add(sapidlabel,c);

        c.gridx=1;
        c.gridy=4;

        panel.add(male,c);

        c.gridx=2;
        c.gridy=4;
        c.gridwidth=1;
        c.weighty=1;
        panel.add(female,c);

        c.gridx=0;
        c.gridy=4;
        c.gridwidth=1;
        c.weighty=1;
        panel.add(genderlabel,c);


        c.gridy=5;
        c.gridx=1;
        c.gridwidth=1;
        panel.add(submitbutton,c);

        ButtonGroup btn=new ButtonGroup();
        btn.add(male);
        btn.add(female);
        
        frame.setSize(800,800);

        frame.add(panel,BorderLayout.LINE_START);
        frame.add(rPanel);
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame.setVisible(true);
        rPanel.setLayout(new GridBagLayout());
        GridBagConstraints c2=new GridBagConstraints();
        c2.insets=new Insets(0,0,0,00);
        c2.fill = GridBagConstraints.BOTH;
        submitbutton.addActionListener(new ActionListener() {
            

            @Override
            public void actionPerformed(ActionEvent e) {
                username=usernamefield.getText();
                
                password=passwordfield.getText();
                
                name=namefield.getText();

                sapid=sapidfield.getText();
                rr.setText("username:"+ username+"\n"+"password:"+ password+"\n"+"name:"+ name+"\n"+"sapid:"+ sapid+"\n");
                rr.setText("username:"+ username+"\n"+"password:"+ password+"\n"+"name:"+ name+"\n"+"sapid:"+ sapid+"\n");
                
               
                rPanel.add(rr,c2);
                frame.invalidate();
                frame.revalidate();
                frame.repaint();
            }
        });

        

        //c2.gridx=0;
        //c2.gridy=0;
        //c2.gridwidth = 1;
                //c2.anchor = GridBagConstraints.CENTER;
             //   c2.fill = GridBagConstraints.BOTH;
                //c2.weightx = 1.0;
                //c2.weighty = 1.0;
       // rPanel.add(rr,c2);

    }   
    public static void main(String[] args) throws IOException {
        myframe m=new myframe();
    }

}
