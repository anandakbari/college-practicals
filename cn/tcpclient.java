package cn;

import java.io.*;
import java.net.*;

public class tcpclient {
    public static void main(String[] args) throws UnknownHostException, IOException {
        
        Socket s=new Socket("localhost",8000);
        DataInputStream din=new DataInputStream(s.getInputStream());
        DataOutputStream dout=new DataOutputStream(s.getOutputStream());
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String str1="",str2="";

        System.out.println("server started");

        while(!str1.equals("close")){
            System.out.println("write msg");
            str1=br.readLine();
            dout.writeUTF(str1);
           // dout.flush();
           
            str2=din.readUTF();
            System.out.println("client: "+str2);
            
            
        }
        din.close();
        dout.close();
        s.close();
        
    }
}
