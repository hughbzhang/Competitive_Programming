package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/
import java.io.*;
import java.util.*;

public class invite {
	static int[][] groups;
	static int cows;
	static int number;
	static boolean[] party;
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("invite.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("invite.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     
     cows = Integer.parseInt(st.nextToken());//number of cows
     number = Integer.parseInt(st.nextToken());//number of groups
     int counter = 1;
     groups = new int[number][number+2];
     boolean[] visit = new boolean[number];
     party = new boolean[cows+1];
     party[1]  = true;
     
     int start = 0;
     
     for(int x = 0;x<number;x++){
    	 st = new StringTokenizer(f.readLine());
    	 groups[x][0] = Integer.parseInt(st.nextToken());
    	 if(groups[x][0]>number+1){
    		 groups[x][0] = 0;
    		 start++;
    		 continue;
    	 }
    	 if(groups[x][0]==1){
    		 start++;
    		 counter++;
    		 party[Integer.parseInt(st.nextToken())]=true;
    	 }
    	 for(int a = 1;a<=groups[x][0];a++){
    		 groups[x][a] = Integer.parseInt(st.nextToken());
    	 }
     }
     quicksort(0, number-1);
     
     
     boolean go = true;
     int end = counter+1;
     while(go){
    	 go = false;
    	 for(int x = start;x<number;x++){
    		 if(groups[x][0]>end) break;
    		 if(visit[x]) continue;
    		 if(check(x)){
    			 counter++;
    			 end++;
    			 go = true;
    			 visit[x] = true;
    		 }
    	 }
     }
     /*for(int y = 0;y<number;y++){
    	 for(int x = 0;x<number+2;x++){
    		 System.out.print(groups[y][x]);
    	 }
    	 System.out.println();
     }*/
     
     out.println(counter);
     
    out.close();                             
    System.exit(0);                            
  }
  static boolean check(int index){
	 int pos = 0;
	 
	 for(int a = 1; a<=groups[index][0];a++){
		int next = groups[index][a];
		if(party[next]==false){
			if(pos==0){
				pos = next;
			}
			else return false;
		}
	 }
	 party[pos] = true;
	 return true;
	  
	  
  }
  
  static void quicksort(int low, int high) {//NOT MY CODE!!!!!!!!!
	    int i = low, j = high;
	    // Get the pivot element from the middle of the list
	    int pivot = (groups[low][0] + groups[high][0])/2;
	    // Divide into two lists
	    while (i <= j) {
	      // If the current value from the left list is smaller then the pivot
	      // element then get the next element from the left list
	      while (groups[i][0] < pivot) {
	        i++;
	      }
	      // If the current value from the right list is larger then the pivot
	      // element then get the next element from the right list
	      while (groups[j][0] > pivot) {
	        j--;
	      }

	      // If we have found a values in the left list which is larger then
	      // the pivot element and if we have found a value in the right list
	      // which is smaller then the pivot element then we exchange the
	      // values.
	      // As we are done we can increase i and j
	      if (i <= j) {
	    	swap(i, j);
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
  static void swap(int i, int j){
	
	  int temp;
	  for(int x = 0;x<number+2;x++){
		  if(groups[i][x]==0&&groups[j][x]==0) break;
		  temp = groups[i][x];
		  groups[i][x] = groups[j][x];
		  groups[j][x]= temp;
	  }
	  
	  
	  
  }
}