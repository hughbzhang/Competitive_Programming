package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: digits
*/
import java.io.*;
import java.util.*;

public class digits {
	
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("digits.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("digits.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
   //StringTokenizer st = new StringTokenizer(f.readLine());
						  // Get line, break into tokens
    String B2 = f.readLine();    // first integer
    String B3 = f.readLine();    // second integer
    ArrayList<String> b2 = new ArrayList<String>();
    ArrayList<String> b3 = new ArrayList<String>();
   // counter = 0;
    //char[] temp2 = new char[B2.length()];
    //char[] temp3 = new char[B3.length()];
    String temp = "";
    //b2[0]= B2;
    //b3[0]= B3;
    //out.println(i1+i2);                           // output result
    //out.close();  							  // close the output file
    b2.add(B2);
    b3.add(B3);
    	for(int x = 0;x<B2.length();x++){
    	
    		if(B2.charAt(x)=='0'){
    		temp = replace(B2, '1', x);
    		b2.add(temp);
    		//System.out.println("1");
    		
    		}
    		//System.out.println(b2[counter]);
    		//counter++;
    		else{
    		temp = replace(B2, '0', x);
    		b2.add(temp);
    		//System.out.println("0");
    		
    		}
    		//System.out.println(b2.[counter]);
    		//counter++;
    }
    	
    	for(int x = 0;x<B3.length();x++){
        	
    		if(B3.charAt(x)=='0'){
    		temp = replace(B3, '1', x);
    		b3.add(temp);
    		
    		temp = replace(B3, '2', x);
    		b3.add(temp);
    		//System.out.println("1");
    		}
    		//System.out.println(b2[counter]);
    		//counter++;
    		else if(B3.charAt(x)=='1'){
        		temp = replace(B3, '0', x);
        		b3.add(temp);
        		
        		temp = replace(B3, '2', x);
        		b3.add(temp);
        		//System.out.println("1");
        		}
    		else if(B3.charAt(x)=='2'){
        		temp = replace(B3, '0', x);
        		b3.add(temp);
        		
        		temp = replace(B3, '1', x);
        		b3.add(temp);
        		//System.out.println("1");
        		}
    		//System.out.println(b2.[counter]);
    		//counter++;
    }	
    //	for(int x = 0; x<b3.size();x++){
    	//	System.out.println(b3.get(x));
    	//}
    /*
    for(int x = 0;x<B3.length();x++){
    	temp3[x]=B3.charAt(x);
    }
    for(int x = 0;x<temp2.length;x++){
    	
    }*/
    	Integer storage;
    	String str;
    for(int x = 0; x<b3.size();x++){
    	storage = Integer.parseInt(b3.get(x), 3);
    	str = Integer.toBinaryString(storage);
    	if(b2.contains(str)){
    		out.println(storage);
    		out.close();
    	    System.exit(0); 
    	}
    	//str = storage.toString();
    	//str = 
    	//str = storage.toBinaryString(storage);
    	
    }
    
    
    
    
    out.close();
    System.exit(0);                               // don't omit this!
  }
  
 private static String replace(String first, char r, int index){
		  char[] temp = new char[first.length()];
		  String next = "";
		  for(int x = 0;x<temp.length;x++){
			  temp[x]=first.charAt(x);
		  }
		  temp[index] = r;
		  for(int x = 0;x<temp.length;x++){
			 next+=temp[x];
		  }
		  
		  
		  return next;
	  }
}