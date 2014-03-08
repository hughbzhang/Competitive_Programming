package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/
import java.io.*;

public class clumsy {
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("clumsy.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("clumsy.out")));
     
     StringBuffer line = new StringBuffer(f.readLine());
    
     int forward = 0;
     int backward = 0;
     int change = 0;
     
     for(int x = 0;x<line.length();x++){
    	 if(line.charAt(x)=='(') forward++;
    	 else backward++;
    	 
    	 
    	 if(backward>forward){
    		 
    		 //line.setCharAt(x, '(');
    		 change++;
    		 forward++;
    		 backward--;
    		 	 
    		 
    	 }

        
     }
    // System.out.println(change);
 	
     change += Math.abs(forward-backward)/2;
	 
    // System.out.println(change);
     
     
     
     
    out.println(change);
     
     
     
    out.close();                             
    System.exit(0);                            
  }
}