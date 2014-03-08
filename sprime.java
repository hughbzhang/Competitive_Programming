package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: sprime
*/
import java.io.*;
import java.util.*;

public class sprime {
	
	static int[] primes;
	static int length;
	static ArrayList<StringBuffer> prime = new ArrayList<StringBuffer>();
	
	
	
	
	static boolean checkPrime(int prime){
		  
		  int stop = (int) Math.sqrt(prime);
		  if(prime==1) return false;
		  
		 for(int x = 0;x<primes.length;x++){
			if(primes[x]>stop) break;
			if(prime%primes[x]==0) return false;
		 }
		 
		 
		 return true;
		  
	  }
	  
	  
	  
	  
	  
	  static ArrayList<Integer> fill(int max){
		  
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
	  
	  static boolean check(StringBuffer sprime){
		  
		  StringBuffer prime = new StringBuffer(sprime);
		  
		  while(prime.length()>0){
			  if(checkPrime(Integer.parseInt(prime.toString()))==false) return false;
			  prime.deleteCharAt(prime.length()-1);
		  }
		  return true;
	  }
	  
	
	
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("sprime.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("sprime.out")));
    
     length = Integer.parseInt(f.readLine());
     ArrayList<Integer> Tprimes = fill((int)Math.pow(10, length));
     primes = new int[Tprimes.size()];
     
     for(int x = 0; x<Tprimes.size();x++){
    	 primes[x] = Tprimes.get(x);
     }

     //int min = (int)Math.pow(10, length-1);
     //int max = (int)Math.pow(10, length);
     StringBuffer sprime = new StringBuffer("2");
     
     
     for(int x = 1; x<length;x++){
    	 sprime.append("1");
     }
     boolean changed = false;
     
     
     
     while(true){
    	 if(check(sprime)) prime.add(new StringBuffer(sprime));
    	 for(int x = length-1;x>0;x--){
    		 
    		 
    		 if(sprime.charAt(x)!='9'){
    			 sprime.setCharAt(x, (char)(sprime.charAt(x)+2));
    			 changed = true;
    			 break;
    		 }
    		 else sprime.setCharAt(x, '1');
    	 }
    	 if(changed == false){
    		 char holder = sprime.charAt(0);
    		 if(holder=='2') sprime.setCharAt(0, '3');
    		 else if(holder=='9') break;
    		 else sprime.setCharAt(0, (char)(holder+2));
    	 }
    	 changed = false;
    	 
     }
     
     for(int x = 0;x<prime.size();x++){
    	 out.println(prime.get(x));
     }
	 
    
     
     
    out.close();                             
    System.exit(0);                            
  }
  static void prime(StringBuffer sprime, String add){
	  
	  sprime.append(add);
	  
	  if(sprime.length()==length){
		  if(check(sprime)) prime.add(sprime);
	  }
	  else{
		  for(int x = 1;x<=9;x=x+2){
			  prime(sprime, Integer.toString(x));
		  }
	  }
	  return;
  }
  
}