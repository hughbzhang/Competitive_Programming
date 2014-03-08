package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: milk2
*/
import java.io.*;
import java.util.*;

class milk2 {
	
	
	
	private static int findlength(boolean[] calender, boolean time, int startTime, int endTime){
		
		int length = 0;
		int record = 0;
		for(int x=startTime;x<endTime;x++){
			if(calender[x]!=time){
				if(record<length) record = length;
				length = -1;
			}
			length++;
			
		
		}
		if(record<length) record = length;
		
		return record;
	}
	
	
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("milk2.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk2.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    
						  // Get line, break into tokens
    //int i1 = Integer.parseInt(st.nextToken());    // first integer
    //int i2 = Integer.parseInt(st.nextToken());    // second integer
    //out.println(i1+i2);                           // output result
    //out.close();                                  // close the output file
    //System.out.println(f.readLine());
   
    String cows = f.readLine();
    int COWS = Integer.parseInt(cows);
    int highest = 0;
    int lowest = 6000;
    int empty = 0;
    int full = 0;
    int[] startTime = new int[COWS];
    int[] endTime = new int[COWS];
    
    for(int x = 0; x < COWS; x++){
    	StringTokenizer st = new StringTokenizer(f.readLine());
    	int i1 = Integer.parseInt(st.nextToken());    // first integer
        int i2 = Integer.parseInt(st.nextToken());    // second integer
        if(i1<=lowest) lowest = i1;
        if(i2>highest) highest = i2;
        startTime[x]=i1;
        endTime[x]=i2;    	
       
    }    
    
    boolean[]calender = new boolean[highest+1];
    System.out.println(lowest);
    for(int x = 0; x<calender.length;x++){
    	calender[x]=false;
    }
    
  
    
    for(int x = 0;x<startTime.length;x++){
    	for(int y = startTime[x];y<endTime[x];y++){
    	
    		calender[y] = true;
    	
    	
    	}
    	
    
    }
      
    
    full = findlength(calender, true, lowest, highest);
    empty = findlength(calender, false, lowest, highest);
    
    System.out.println(full + " " + empty);
   // for(int x = 0;x<calender.length;x++) System.out.println(calender[x] + "" + x);
    out.println(full + " " + empty);
    out.close();
   
    System.exit(0);                               // don't omit this!
  }
}