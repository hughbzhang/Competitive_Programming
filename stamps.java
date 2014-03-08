package Solved;
/*
ID: bigfish2    
LANG: JAVA
TASK: stamps
*/
import java.io.*;
import java.util.*;

class stamps {
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("stamps.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("stamps.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    StringTokenizer st = new StringTokenizer(f.readLine());
                          // Get line, break into tokens
    int total = Integer.parseInt(st.nextToken());    // first integer
    int number = Integer.parseInt(st.nextToken());    // second integer
    int[] stamps = new int[number];
    int end = 1;
    StringBuffer line = new StringBuffer("");
    String temp = f.readLine();
    while(temp!=null){
    	line.append(temp);
    	line.append(" ");
    	temp = f.readLine();
    }
    
    
    st = new StringTokenizer(line.toString());
    for(int x = 0;x<number;x++) stamps[x]=Integer.parseInt(st.nextToken());
    boolean go = true;
    while(go){
    go = false;
        for(int x = 1;x<stamps.length;x++){
            if(stamps[x]<stamps[x-1]){
                int holder = stamps[x];
                stamps[x] = stamps[x-1];
                stamps[x-1] = holder;
                go = true;

            }
            

        }





    }






    
    long dp[] = new long[total*stamps[number-1]+1];
    for(int x = 0;x<dp.length;x++) dp[x] = total+1;

    for(int x = 0;x<number;x++) dp[stamps[x]] = 1;
    
    for(end = 1;end<dp.length;end++){
    
	    for(int y = 0;y<stamps.length;y++){
	
	        int index = end-stamps[y];
	        if(index<0) break;
	        if(dp[index]+1<dp[end]) dp[end] = dp[index]+1;
	    }
	    if(dp[end]>total){
	        break;
	    }
    }
    

    out.println(end-1);

                           // output result
    out.close();                                  // close the output file
    System.exit(0);                               // don't omit this!
  }
}