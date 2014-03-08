package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: cowfind
*/
import java.io.*;
import java.util.*;

public class cowfind {
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("cowfind.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cowfind.out")));
     
     StringBuffer line = new StringBuffer(f.readLine());
     ArrayList<Integer> forward = new ArrayList<Integer>();
     ArrayList<Integer> backward = new ArrayList<Integer>();
     boolean mark;
     int total = 0;
     
     if(line.charAt(0)=='(') mark = true;
     else mark = false;
     
     for(int x = 1;x<line.length();x++){
    	 char key = line.charAt(x);
    	 if(key=='('){
    		 if(mark) forward.add(x-1);
    		 else mark = true;
    	 }
    	 else if(key==')'){
    		 if(mark==false) backward.add(x-1);
    		 else mark = false;
    	 }
     }
     for(int x = 0;x<forward.size();x++){
    	 int a = forward.get(x);
    	 int y;
    	 for(y = 0;y<backward.size();y++){
    		 if(backward.get(y)>a) break;
    	 }
    	 total+=(backward.size()-y);
     }
     out.println(total);
    out.close();                             
    System.exit(0);                            
  }
}