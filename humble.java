package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: humble
*/
import java.io.*;
import java.util.*;

public class humble {
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("humble.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("humble.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     int number = Integer.parseInt(st.nextToken());
     int place  = Integer.parseInt(st.nextToken());
     int length = (int)Math.ceil(Math.sqrt(20*place));
     st = new StringTokenizer(f.readLine());
     int[] primes = new int[number];
     long[] path = new long[place+1];
     int[] pindex = new int[number];
     
     long[] next   = new long[number];
     for(int x = 0;x<number;x++){
    	 primes[x]=Integer.parseInt(st.nextToken());
    	 next[x] = primes[x];
    	 path[x] = Long.MAX_VALUE;
     }
     

     Arrays.sort(primes);
     
     
     int counter = 1;
     long current = primes[0];
     path[0] = 1;
     path[1] = current;
     long temp;
     
     while(counter<place){
    	 temp = Long.MAX_VALUE;
    	 //System.out.print(current+"  ");
    	 for(int x = 0;x<next.length;x++){
    		 if((primes[x]*((current/primes[x])+1))>temp) continue;
    		 pindex[x] = binarySearch(current/primes[x], path, counter, pindex[x]);
    		 next[x] = primes[x]*path[pindex[x]];
    		 if(next[x]<temp) temp = next[x];
    		 //System.out.print(next[x]+" ");
    	 }
    	 //System.out.println();
    	 current = temp;
    	 counter++;
    	 path[counter] = current;
     }
     
     out.println(current);
     //for(int x = 0;x<path.length;x++) System.out.println(path[x]);
     	/*counter = 0;
     	long checker = 1;
    	while(counter<place){
    	 checker++;
    	 long pos = checker;
    	 for(int x = 0;x<primes.length;x++) while(pos%primes[x]==0) pos/=primes[x];
    	 if(pos==1) counter++;
     }
     
     
     out.println(checker);*/
     
     
     
     
     
     
     
	 out.close();   
	 
	 System.exit(0);     
	 
  }
  static boolean check(long pos, int[] primes){
	  
	  for(int x = 0;x<primes.length;x++){
		  while(pos%primes[x]==0) pos/=primes[x];
	  }
	  if(pos==1) return false;
	  else return true;
	  
  }
  static int binarySearch(long key, long[] path, int end, int start){
	  
	 
	  int mid = 0;
	  
	  while(start<end){
		mid = (start+end)/2;
		if(path[mid]<=key) start = mid+1;
		else end = mid;
	  }
	  if(start!=end){
		  System.out.println("failure");
		  return -1;
	  }
	  return start;
  }
}


//System.out.println(binarySearch(8, new long[] {1 , 4, 6 ,8, 9, 10}, 5));

