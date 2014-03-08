package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: subset
*/
import java.io.*;
import java.util.*;

public class subsetslow {
	
  static boolean[] set;
  static int size;
  static int total;
  static int end;
  static int counter = 0;
  static int path[];
  static ArrayList<int[]> sol;
  static boolean half;
  static int special;
  
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("subset.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("subset.out")));
     size = Integer.parseInt(f.readLine());
     total = (size)*(size+1)/4;
     set = new boolean [size];
     end = size/2;
     path = new int[end];
     sol = new ArrayList<int[]>();
     special = 0;
     if(end%2==0) half = true;
     else half = false;
     
     if(size*(size+1)%4!=0){
    	 out.println(0);
    	 out.close();
    	 System.exit(0);
     }
     
     
     for(int x = 1; x<=end;x++){
    	 search(0, x, 0, 0);
     }
     
     /*top:for(int x = 0;x<sol.size();x++){
    	 int[] temp = sol.get(x);
    	 int[] rev = new int[size];
    	 int pointO = 0;
    	 int pointN = 0;
    	 for(int y = 1;y<=size;y++){
    		 if(pointO<size/2&&temp[pointO]==y){
    			 pointO++;
    			 continue;
    		 }
    		 else{
    			 rev[pointN] = y;
    			 pointN++;
    		 }
    		 
    	 }
    	 for(int b = 0; b<rev.length;b++){
    		 System.out.print(rev[b]+" ");
    	 }
    	 
    	 for(int a = x;a<sol.size();a++){
    		 if(compare(rev, sol.get(a))) continue top;
    	 }
    	 counter++;
    	 
    	 
     }*/
    out.println(counter+special/2);
     
    out.close();                             
    System.exit(0);                            
  }
  static boolean compare(int[] one, int[] two){
	  
	  
	  for(int x = 0;x<two.length;x++){
		  if(one[x]!=two[x]) return false;
	  }
	  return true;
	  
  }
  
  static void search(int current, int end, int sum, int choice){
	  sum+=choice;
	  if(current == end){
		  if(sum==total){
			  if(half&&end==size/2) special++;
			  else counter++;
		  }
		  return;
	  }
	  
 	  for(int x = choice+1;x<=size;x++){
 		  path[current] = x;
 		  //System.out.println(sum);
 		  search(current+1, end, sum, x);
 		  //System.out.println(sum);
 	  }
 	  
	  return;
	  
  }
  
  static void print(){
	  for(int x = 0;x<path.length;x++){
		  System.out.print(path[x]+" ");
	  }
	  System.out.println();
	  
	  return;
  }
  static void store(){
	  int[] temp = new int[size/2];
	  for(int x = 0;x<path.length;x++){
		  temp[x] = path[x];
	  }
	  sol.add(temp);
	  
	  return;
  }
  
}