package cn;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.*;
import java.util.*;

public class tcpserver{
    public static void main(String[] args) throws IOException {
        ServerSocket ss=new ServerSocket(8000);
        Socket s=ss.accept();
        DataInputStream din=new DataInputStream(s.getInputStream());
        DataOutputStream dout=new DataOutputStream(s.getOutputStream());
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String str1="",str2="";

        System.out.println("server started");

        while(!str1.equals("close")){
            str1=din.readUTF();
            System.out.println("client: "+str1);
            str2=br.readLine();
            dout.writeUTF(str2);
            //dout.flush();
        }
        din.close();
        dout.close();
        s.close();
        ss.close();
    }
    

}

