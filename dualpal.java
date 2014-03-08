package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: dualpal
*/
import java.io.*;
import java.util.*;

class dualpal {
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("dualpal.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("dualpal.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    StringTokenizer st = new StringTokenizer(f.readLine());
						  // Get line, break into tokens
    //int i1 = Integer.parseInt(st.nextToken());    // first integer
    //int i2 = Integer.parseInt(st.nextToken());    // second integer
    //out.println(i1+i2);                           // output result
    //out.close();                                  // close the output file
    
    String NUMBER = st.nextToken();
    String FIRST = st.nextToken();
    int number = Integer.parseInt(NUMBER);
    int first = Integer.parseInt(FIRST);
    int test = first;
    int counter = 0;
    int go = 0;
    
    while(counter<number){
    	
    	test++;
        for(int x = 2; x<11;x++){
        	
        	String temp = Integer.toString(test, x);
        	String storage = "";
        	for(int y = temp.length()-1; y>-1;y--){
        		storage += temp.charAt(y);
        	}
        	if(temp.equals(storage)) go++;
    
        
        
        
        }
        if(go>1){
        	out.println(test);
        	counter++;
        }
        go = 0;
    }
    
    
    
    
    //out.println();
    out.close();
    System.exit(0);                               // don't omit this!
  }
}