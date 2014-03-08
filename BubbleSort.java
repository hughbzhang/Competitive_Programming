package Algorithms;

/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/
import java.io.*;

public class BubbleSort {
  public static void main (String [] args) throws IOException {
  
	  int[] stack = new int[]{5, 65, 3, 24, 22, 4, 5, 6, 7, 3, 237};
	  
	  stack = sort(stack);
	  for(int x = 0;x<stack.length;x++){
		  System.out.println(stack[x]);
	  }
	  
    System.exit(0);  
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