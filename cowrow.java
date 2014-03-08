package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: barn1
*/
import java.io.*;
import java.util.*;

public class cowrow {
	
	
  public static void main (String [] args) throws IOException {
   
	 BufferedReader f = new BufferedReader(new FileReader("cowrow.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cowrow.out")));         
    int counter = 0;
    int banned = -1;
    int record = 1;
    int initial = -1;
    int NUMBER = Integer.parseInt(f.readLine());
    int[] cows = new int[NUMBER];
    ArrayList<Integer> removed = new ArrayList<Integer>();
    for(int x = 0; x<cows.length;x++){
    	cows[x] = Integer.parseInt(f.readLine());
    }
    
    for(int x = 0; x<cows.length;x++){
    	if(removed.contains(cows[x])==false){
    		removed.add(cows[x]);
    		banned = cows[x];
    		counter = 0;
    		initial = cows[0];
    		for(int y = 0; y <cows.length; y++){
    			if(cows[y]== banned) continue;
    			if(cows[y]==initial){
    				counter++;
    				//System.out.println(initial);
    			}
    			else{
    				initial = cows[y];
    				if(record<counter){
    					record = counter;
    				}
    				counter = 1;
    			}
    		}
    		if(record<counter){
    			record = counter;
    		}
    	}
    		
    		
    		
    		
    		
    		
    		
    		
    		
    	}
    
    
    out.println(record);
    out.close();
    System.exit(0);                             
  }
}
    