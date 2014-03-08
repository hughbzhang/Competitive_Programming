package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/
import java.io.*;
import java.util.StringTokenizer;

public class squares {
	static int number;
	static int size;
	static int[][] points;
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("squares.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("squares.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     number = Integer.parseInt(st.nextToken());
     size = Integer.parseInt(st.nextToken());
     int overlap = 0;
   
     points = new int[number][2];
     
     for(int x = 0;x<number;x++){
    	 st = new StringTokenizer(f.readLine());
    	 points[x][0] = Integer.parseInt(st.nextToken());
    	 points[x][1] = Integer.parseInt(st.nextToken());
     }
     quicksort(0, number-1);
     
     for(int y = 0;y<number;y++){
    	 int X = points[y][0];
    	 int Y = points[y][1];
    	 int max = X+size;
    	 for(int x = y+1;x<number;x++){
    		 if(points[x][0]>=max) break;
    		 
    		 if(Math.abs(points[x][0]-X)<size&&Math.abs(points[x][1]-Y)<size){
    			 if(overlap==0){
    				 int width = size-Math.abs(points[x][0]-X);
    				 int height = size-Math.abs(points[x][1]-Y);
    				 overlap = width*height;
    				 //System.out.println(X+" "+Y+" "+points[x][0]+" "+points[x][1]);
    			 }
    			 else{
    				 out.println(-1);
    				 out.close();
    				 System.exit(0);
    			 }
    		 }
    		 
    		 
    		 
    		 
    	 }
     }
     
     
     
     /*for(int x = 0;x<number;x++){
    	 System.out.println(points[x][0]+" "+points[x][1]);
     }*/
     
     
     
     
    out.println(overlap);
    out.close();                             
    System.exit(0);                            
  }
  static void quicksort(int low, int high) {//NOT MY CODE!!!!!!!!!
	    int i = low, j = high;
	    int temp;
	    // Get the pivot element from the middle of the list
	    int pivot = (points[i][0]+points[j][0])/2;
	    // Divide into two lists
	    while (i <= j) {
	      // If the current value from the left list is smaller then the pivot
	      // element then get the next element from the left list
	      while (points[i][0] < pivot) {
	        i++;
	      }
	      // If the current value from the right list is larger then the pivot
	      // element then get the next element from the right list
	      while (points[j][0] > pivot) {
	        j--;
	      }

	      // If we have found a values in the left list which is larger then
	      // the pivot element and if we have found a value in the right list
	      // which is smaller then the pivot element then we exchange the
	      // values.
	      // As we are done we can increase i and j
	      if (i <= j) {
	    	  temp = points[i][0];
	    	  points[i][0] = points[j][0];
	    	  points[j][0] = temp;
	    	  temp = points[i][1];
	    	  points[i][1] = points[j][1];
	    	  points[j][1] = temp;
	    	  
	    	  
	    	  
	        i++;
	        j--;
	      }
	    }
	    // Recursion
	    if (low < j)
	      quicksort(low, j);
	    if (i < high)
	      quicksort(i, high);
	  }
}