package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: ctiming
*/
import java.io.*;
import java.util.*;

public class ctiming {
	
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("ctiming.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ctiming.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    StringTokenizer st = new StringTokenizer(f.readLine());
	
    int d = Integer.parseInt(st.nextToken());
    int h = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());
    int minutes = 0;
    //int temp = 0;
    //System.out.println(d);
    //System.out.println(m);
    //System.out.println(s);
    
    if(d<11){
    	out.println(-1);
    	out.close();
    	System.exit(0); 
    }
    if(d==11&&h<11){
    	out.println(-1);
    	out.close();
    	System.exit(0); 
    }
    if(d==11&&h==11&&m<11){
    	out.println(-1);
    	out.close();
    	System.exit(0); 
    }
    //temp = d-11;
    minutes += (d-11)*1440;
    minutes += (h-11)*60;
    minutes += (m-11);
    
    
    
    
    
    
    /*					  // Get line, break into tokens
    int i1 = Integer.parseInt(st.nextToken());    // first integer
    int i2 = Integer.parseInt(st.nextToken());    // second integer
    out.println(i1+i2);                           // output result
    out.close();  */	
    // close the output file
    out.println(minutes);
    out.close();
    System.exit(0);                               // don't omit this!
  }
}