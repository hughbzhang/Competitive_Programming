package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/
import java.io.*;

public class bbreeds {
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("bbreeds.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("bbreeds.out")));
     
     StringBuffer line = new StringBuffer(f.readLine());
     StringBuffer holder1 = new StringBuffer("");
     StringBuffer holder2 = new StringBuffer("");
     //holder2.append('c');
     
     System.out.println(holder2);
      
     int binary = (int)Math.pow(2, line.length());  
     int count = 0;
     int parity = 0;
     StringBuffer template;
     
     for(int x = 0; x<binary;x++){
    	 template = new StringBuffer(Integer.toBinaryString(x));
    	 int length = template.length();
    	 for(int z = 0; z<length;z++){
    		 if(template.charAt(z)=='1') parity++;
    	 }
    	 if(parity%2!=0){
    		 parity = 0;
    		 continue;
    	 }
    	 parity = 0;
    	 for(int y = length; y<line.length();y++){
    		 template.insert(0, '0');
    	 }
    	 
    	 for(int a = 0; a<line.length();a++){
    		 if(template.charAt(a)=='0') holder1.append(line.charAt(a));
    		 else holder2.append(line.charAt(a));
    	 }

    	 //System.out.println(holder1);
    	 //System.out.println(holder2);
    	 //System.out.println();
    	 
    	 
    	 
    	 
    	 if(matching(holder1)&&matching(holder2)){
    		 count++;
    		
    	 }
    	 holder1.delete(0, holder1.length());
    	 holder2.delete(0, holder2.length());
    	 
     }
     
     
    //System.out.println(count);
 
     out.println(count%2012);
     
    out.close();                             
    System.exit(0);                            
  }
  private static boolean matching(StringBuffer line){
	  
	  
	  int count = 0;
	  
	  for(int x = 0; x<line.length();x++){
		  if(count<0) return false;
		  
		  if(line.charAt(x)=='(') count++;
		  else count--;
		  
	  }
	  
	  if(count==0) return true;
	  else return false;
	  
  }
  
  
  
  
  
}