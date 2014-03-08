package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: barn1
*/
import java.io.*;
import java.util.*;

public class islands {
	
	private static int findislands(int[] map){
		int temp = 0; 
		if(map[0] != 0) temp++;
		
		for(int x = 1;x<map.length;x++){
		    	if(map[x]!=0){
		    		temp++;
		    	
			    	if(map[x-1]!=0){
			    		temp--;
			    	}
		    	}
		    }
		return temp;
	}
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("islands.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("islands.out")));                               // close the output file
     int NUMBER = Integer.parseInt(f.readLine());
     int land = 0;
     int record = 0;
     int[] islands = new int [NUMBER];
     int[] sorted = new int [NUMBER];
     int[] flooded = new int [NUMBER];
     ArrayList<Integer> level = new ArrayList<Integer>();
     
     for(int x = 0; x<NUMBER;x++){
    	 islands[x] = Integer.parseInt(f.readLine());
    	 flooded[x] = islands[x];
     }
     sorted = sort(islands);
   
     
     
     for(int x = 0; x<sorted.length; x++){
    	 if(level.contains(sorted[x])) continue;
    	 level.add(sorted[x]);
    	
    	 flooded = flood(flooded, sorted[x]);
    
    	 land = findislands(flooded);
    	 if(record<land) record = land;
     }
     if(record<land) record = land;
     
     
     
     
    out.println(record);
    out.close();
    System.exit(0);                               // don't omit this!
  }
  public static int[] flood(int[] farm, int level){
	  for(int x = 0;x<farm.length; x++){
		  if(farm[x]<=level) farm[x]= 0;
	  }
	  
	  return farm;
  }
  
  
	public static int[] sort(int[] stack) {
	    
		boolean go = true;
		int storage;
		while(go){
	  	   go = false;
	  	   for(int x = 1;x<stack.length;x++){
	  		   if(stack[x]<stack[x-1]){
	  			   storage = stack[x];
	  			   stack[x] = stack[x-1];
	  			   stack[x-1]=storage;
	  			   go = true;
	  		   }
	  	   }
	     }
		
		return stack;
	}
  
}
    