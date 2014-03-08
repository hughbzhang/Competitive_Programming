package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: palsquare
*/
import java.io.*;

class palsquare {
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("palsquare.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("palsquare.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    //StringTokenizer st = new StringTokenizer(f.readLine());
						  // Get line, break into tokens
    //int i1 = Integer.parseInt(st.nextToken());    // first integer
    //int i2 = Integer.parseInt(st.nextToken());    // second integer
    //out.println(i1+i2);                           // output result
    //out.close();                                  // close the output file
    
    String BASE = f.readLine();
    
    int base = Integer.parseInt(BASE);
    for(int x = 1; x<301;x++){
    	
    	int squared = x*x;
    	String temp = Integer.toString(squared, base);
    	String storage = "";
    	for(int y = temp.length()-1; y>-1;y--){
    		storage += temp.charAt(y);
    	}
    System.out.println(temp + " " + storage );
    
    String print = Integer.toString(x, base);
    
    if(temp.equals(storage)) out.println(print.toUpperCase() + " " + temp.toUpperCase());
    }
    
    
    //String number = "5";
    //number.t
    
    
    //out.println();
    out.close();
    System.exit(0);                               // don't omit this!
  }
}