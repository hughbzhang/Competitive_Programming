package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/
import java.io.*;
import java.util.*;

public class wifi{
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("wifi.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("wifi.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     ArrayList<Double> stations = new ArrayList<Double>();
     ArrayList<Double> rad = new ArrayList<Double>();
     
     
     
     
     
     int cows = Integer.parseInt(st.nextToken());
     int build = Integer.parseInt(st.nextToken());
     int range = Integer.parseInt(st.nextToken());
    
     int[] temp = new int[cows];
     
     for(int x = 0;x<cows;x++){
    	 
    	 int index = Integer.parseInt(f.readLine());
    	 temp[x] = index;
    	 //if(index<start) start = index;
     }
     
     
     	boolean go = true;
		int storage;
		while(go){
	  	   go = false;
	  	   for(int x = 1;x<temp.length;x++){
	  		   if(temp[x]<temp[x-1]){
	  			   storage = temp[x];
	  			   temp[x] = temp[x-1];
	  			   temp[x-1]=storage;
	  			   go = true;
	  		   }
	  	   }
	     }
		
		for(int x = 0;x<temp.length;x++){
			rad.add(0.0);
			stations.add((double)temp[x]);
		}
		
		
		
		
     go = true;
     while(go){
    	 go = false;
    	 for(int x = 1; x<stations.size();x++){
    		 double start = stations.get(x-1);
    		 double end = stations.get(x);
    		 double first = rad.get(x-1);
    		 double sec = rad.get(x);
    	     double cost = 0.5*range*(end-start+first+sec);
    	     if(cost<build){
    	    	 stations.set(x-1, 0.5*(start-first+end+sec));
    	    	 rad.set(x-1, cost/range);
    	    	 stations.remove(x);
    	    	 rad.remove(x);
    	    	 go = true;
    	    	 x--;
    	     }
    	 }
    	 
    	 
    	 
     }
     double sum = rad.size()*build;
     
     
     for(int x = 0;x<rad.size();x++){
    	 sum+=(rad.get(x)*range);
     }
    
     
     
     
     
     out.println(sum);
     
     
     
     
     
    // for(int x = 0;x<200;x++) System.out.println(x+" "+field[x]);
                            
    out.close();                             
    System.exit(0);                            
  }
}