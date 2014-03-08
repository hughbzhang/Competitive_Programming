package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: pprime
*/
import java.io.*;
import java.util.*;

public class pprime {
	
	static int min, max;
	static int[] primes;
	static ArrayList<Integer> pprime = new ArrayList<Integer>();
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("pprime.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("pprime.out")));
     
     StringTokenizer st = new StringTokenizer(f.readLine());
     
     min = Integer.parseInt(st.nextToken());
     max = Integer.parseInt(st.nextToken());
     
     ArrayList<Integer> Tprimes = fill();//find all necessary primes

     Integer[] middle = (Integer[]) Tprimes.toArray(new Integer[0]);
     primes = new int[middle.length];
     
     
     for(int x = 0; x<middle.length;x++){
    	 primes[x]=middle[x];
    	
     }

     int pal = first();
     int mid = 0;
     char ch = 0;
     int length = 0;
     StringBuffer change = new StringBuffer(Integer.toString(pal));
     boolean changes = false;
     
     while(pal<=max){
    	 if(checkPrime(pal)) pprime.add(pal);
    	 length = change.length();
    	 mid = length/2;
    	 for(int x = mid;x<length;x++){
    		 ch = change.charAt(x);
    		 if(ch!='9'){
    			 change.setCharAt(x, (char)(ch+1));
    			 change.setCharAt(length-x-1, (char)(ch+1));
    			 changes = true;
    			 break;
    		 }
    		 else{
    			 change.setCharAt(x, '0');
    			 change.setCharAt(length-x-1, '0');
    		 }
    	 }
    	 if(changes==false){
    		 change.append("1");
    		 change.setCharAt(0, '1');
    	 }
    	 changes = false;
    	 pal = Integer.parseInt(change.toString());
    	 
    	 
     }
     
    for(int x = 0; x<pprime.size();x++){
    	out.println(pprime.get(x));
    }
     
     
     
     
    out.close();                             
    System.exit(0);                            
  }
  static int first(){
	  
	  int counter = min-1;
	  StringBuffer temp;
	  
	  top: while(counter<max){
		counter++;
		temp = new StringBuffer(Integer.toString(counter));
		
		int length = temp.length();
		int end = length/2;
		
		for(int x = 0; x<end;x++){
			if(temp.charAt(x)!=temp.charAt(length-x-1)) continue top;
		}
		return counter;
	  }
	  
	  return -1;
  }
  
  
  
  
  
  static boolean checkPrime(int prime){
	  
	  int stop = (int) Math.sqrt(prime);
	  
	 for(int x = 0;x<primes.length;x++){
		if(primes[x]>stop) break;
		if(prime%primes[x]==0) return false;
	 }
	 
	 
	 return true;
	  
  }
  
  
  
  
  
  static ArrayList<Integer> fill(){
	  
	  int counter = 1;
	  
	  ArrayList<Integer> Tprimes = new ArrayList<Integer>();
	  
	  top: while(counter<Math.sqrt(max)){
		  counter++;
		  for(int x = 0;x<Tprimes.size();x++){
			  if(counter%Tprimes.get(x)==0) continue top;
		  }
		  Tprimes.add(counter);
	  }
	  return Tprimes;
	  
  }
    
	  
  
  
  
  
  
  
  
  
  
  
  
}