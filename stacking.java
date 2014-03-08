package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: stacking
*/
import java.io.*;
import java.util.*;

public class stacking {
  public static void main (String [] args) throws IOException {
    BufferedReader f = new BufferedReader(new FileReader("stacking.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("stacking.out")));
    StringTokenizer st = new StringTokenizer(f.readLine());
    
    int number = Integer.parseInt(st.nextToken());    
    int instructN = Integer.parseInt(st.nextToken());  
    
    int[] stack = new int[number];
    int[][] instruct = new int[instructN][2];
    for(int x = 0;x<instructN;x++){
    	StringTokenizer holder = new StringTokenizer(f.readLine());
    	instruct[x][0] = Integer.parseInt(holder.nextToken())-1;   
    	instruct[x][1] = Integer.parseInt(holder.nextToken())-1;    
    }
    
    for(int x = 0;x<instructN;x++){
    	for(int y = instruct[x][0];y<=instruct[x][1];y++){
    		stack[y]++;
    	}
    }
   boolean go = true;
    int storage= -1;
    
   
    
    
    
    
    while(go){
 	   go = false;
 	   for(int x = 1;x<number;x++){
 		   if(stack[x]<stack[x-1]){
 			   storage = stack[x];
 			   stack[x] = stack[x-1];
 			   stack[x-1]=storage;
 			   go = true;
 		   }
 	   }
    }
   /* for(int x = 0;x<number;x++){
    	System.out.println(stack[x]);
    }*/
    int holder = (number-1)/2;
    
    
    
    out.println(stack[holder]);          
    out.close();                                 
    System.exit(0);                       
  }
}