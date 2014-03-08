package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: contact
*/
import java.io.*;
import java.util.*;

public class contact {
	
	static int[] length;
	static StringBuffer[] code;
	static int[] sort;
	static int[] count;
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("contact.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("contact.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     int min = Integer.parseInt(st.nextToken());    
     int max = Integer.parseInt(st.nextToken());  
     int top = Integer.parseInt(st.nextToken());
     int total = 0;
     for(int x = min;x<=max;x++){
    	 total+=(int)Math.pow(2, x);
     }
     
     
     
              code = new StringBuffer[total];
              sort = new int[total];
             count = new int[total];
     		length = new int[total];
      
     StringBuffer origin = new StringBuffer("");
     String temp = f.readLine();
     
     while(temp!=null){
    	 origin.append(temp);
    	 temp=f.readLine();
     }
     char[] line = new char[origin.length()];
     for(int x = 0;x<line.length;x++) line[x]=origin.charAt(x);
     for(int x = 0;x<total;x++) sort[x]=x;
     
     int counter = 0;
     for(int x = min;x<=max;x++){
    	int high = (int)Math.pow(2, x);
    	for(int y = 0;y<high;y++){
    		StringBuffer hold = new StringBuffer(Integer.toBinaryString(y));
    		while(hold.length()<x) hold.insert(0, '0');
    		code[counter] = hold;
    		length[counter]=x;
    		counter++;
    	}
     }
     int buffer = 0;
     for(int x = min;x<=max;x++){
    	 for(int a = 0;a<=line.length-x;a++){
    		 count[Integer.parseInt(origin.substring(a, a+x), 2)+buffer]++;
    	 }	 
    	 buffer +=Math.pow(2, x);
     }
     
		quicksort(0, sort.length-1);
		int prior = count[sort[0]];
		int index = 0;
		counter = 1;
		
		for(int x = 0;x<sort.length;x++){
			if(counter>top) break;
			if(count[sort[x]]!=prior){
				counter++;
				tiesort(index, x-1);
				index = x;
				prior = count[sort[x]];
			}
		}
		
		prior = -1;
		int last = 0;
		int linebreak = 0;
		boolean print = false;
		
		for(int x = 0;x<total;x++){
			
			index = sort[x];
			if(count[index]==0) break;
			if(count[index]==prior){
				if(linebreak==6){
					out.println();
					linebreak = 0;
				}
				else out.print(" ");
				out.print(code[index]);
				linebreak++;
			}
			else{
				last++;
				if(last>top) break;
				if(print){
					out.println();
					
				}
				print = true;
				out.println(count[index]);
				out.print(code[index]);
				linebreak = 1;
			}
			prior = count[index];
			
			
			
		}
	 out.println();
     out.close();                             
     System.exit(0);                            
  }
  static boolean compare(int one, int two){
	  
	  String first = code[one].toString();
	  String second = code[two].toString();
	  
	  if(first.compareTo(second)==-1) return true;
	  else return false;
  }
  static void quicksort(int low, int high) {
	    int i = low, j = high;
	    // Get the pivot element from the middle of the list
	    int pivot = count[sort[low + (high-low)/2]];

	    // Divide into two lists
	    while (i <= j) {
	      // If the current value from the left list is smaller then the pivot
	      // element then get the next element from the left list
	      while (count[sort[i]] > pivot) {
	        i++;
	      }
	      // If the current value from the right list is larger then the pivot
	      // element then get the next element from the right list
	      while (count[sort[j]] < pivot) {
	        j--;
	      }

	      // If we have found a values in the left list which is larger then
	      // the pivot element and if we have found a value in the right list
	      // which is smaller then the pivot element then we exchange the
	      // values.
	      // As we are done we can increase i and j
	      if (i <= j) {
	    	int temp = sort[i];
	  	    sort[i] = sort[j];
	  	    sort[j] = temp;
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
  static void tiesort(int low, int high) {
	  int storage;
	  boolean go = true;
	  
	 
	  while(go){
		  go = false;
	   for(int x = low+1;x<=high;x++){
  				   
 		   if(count[sort[x]]==count[sort[x-1]]){
 			   if(length[sort[x]]<length[sort[x-1]]){
 				   storage = sort[x];
	  			   sort[x] = sort[x-1];
	  			   sort[x-1]=storage;
	  			   go = true;
 			   }
 			   else if(length[sort[x]]==length[sort[x-1]]){
 				 if(compare(sort[x], sort[x-1])){
 				   storage = sort[x];
	  			   sort[x] = sort[x-1];
	  			   sort[x-1]=storage;
	  			   go = true;
 				 }
 			   }
 		   }
 		 
 	   }
	  }
	  
	  
	  
	  
	  
	  
	 }
  	static boolean check(int i, int j){
  		
  			
	   if(length[sort[i]]<length[sort[j]]){
		  return true;
	   }
	   else if(length[sort[i]]==length[sort[j]]){
		 if(compare(sort[i], sort[j])) return true;
	   }
	   return false;
  	}
  
  
  
}