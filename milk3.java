package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: milk3
*/
import java.io.*;
import java.util.*;



public class milk3 {
	
	public static ArrayList<Integer> historyA = new ArrayList<Integer>();
	public static ArrayList<Integer> historyB = new ArrayList<Integer>();
	public static ArrayList<Integer> historyC = new ArrayList<Integer>();
	public static ArrayList<Integer> possible = new ArrayList<Integer>();
	public static int Amax, Bmax, Cmax;
	
	
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("milk3.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk3.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
    	    
    
    Amax = Integer.parseInt(st.nextToken());    
    Bmax = Integer.parseInt(st.nextToken());  
    Cmax = Integer.parseInt(st.nextToken());
    
    
    
    
    pourMilk(0,0,Cmax, 0);
    
    int[] solutions = new int[possible.size()];
    
    
    for(int x = 0; x<possible.size();x++){
    	solutions[x] = possible.get(x);
    }
    boolean go = true;
    int storage;
    
    while(go){
    	go = false;
    	for(int x = 1; x<solutions.length;x++){
    		if(solutions[x]<solutions[x-1]){
    			go = true;
    			storage = solutions[x];
    			solutions[x]=solutions[x-1];
    			solutions[x-1] = storage;
    		}
    	}
    }
    
    
    
    
 
    out.print(solutions[0]);
    
    for(int x = 1; x<solutions.length;x++){
    	out.print(" "+solutions[x]);
    }
    
    
 
    out.println();                           
    out.close();                             
    System.exit(0);                            
  }
  
  private static void pourMilk(int A, int B, int C, int counter){
	  counter++;
	
	  
	  if(A<0||B<0||C<0) return;
	  if(A>Amax||B>Bmax||C>Cmax) return;
	  	  
	if(checkHistory(A, B, C)) return;
	  
	  if(A==0) possible.add(C);
	  
	  int diff = 0;
	  
	  if(A!=Amax&&C>0){//1 C to A
		  diff = Amax-A;
		  if(C>=diff){
			  pourMilk(Amax, B, C-diff, counter);
		  }
		  else{
			  pourMilk(A+C, B, 0, counter);
		  }
	  }
	  if(C!=Cmax&&A>0){//2 A to C
		  diff = Cmax-C;
		  if(A>=diff){
			  pourMilk(A-diff, B, Cmax, counter);
		  }
		  else{
			  pourMilk(0, B, C+A, counter);
		  }
	  }
	  if(B!=Bmax&&C>0){//3 C to B
		  diff = Bmax-B;
		  if(C>=diff){
			  pourMilk(A, Bmax, C-diff, counter);
		  }
		  else{
			  pourMilk(A, B+C, 0, counter);
		  }
	  }
	  if(C!=Cmax&&B>0){//4 B to C
		  diff = Cmax-C;
		  if(B>=diff){
			  pourMilk(A, B-diff, Cmax, counter);
		  }
		  else{
			  pourMilk(A, 0, C+B, counter);
		  }
	  }
	  if(B!=Bmax&&A>0){//5 A to B
		  diff = Bmax-B;
		  if(A>=diff){
			  pourMilk(A-diff, Bmax, C, counter);
		  }
		  else{
			  pourMilk(0, B+A, C, counter);
		  }
	  }
	  if(A!=Amax&&B>0){//6 B to A
		  diff = Amax-A;
		  if(B>=diff){
			  pourMilk(Amax, B-diff, C, counter);
		  }
		  else{
			  pourMilk(A+B, 0, C, counter);
		  }
	  }
	  
	  return;
	  
	  
  }

  public static boolean checkHistory(int A, int B, int C){
	  
	for(int x = 0; x<historyA.size();x++){
		if(historyA.get(x)==A&&historyB.get(x)==B&&historyC.get(x)==C){
			return true;
		}
			
		
	}
	historyA.add(A);
	historyB.add(B);
	historyC.add(C);
	
	return false;
	  
	  
	  
  }
  
  
  
}

