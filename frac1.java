package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: frac1
*/

import java.io.*;

public class frac1{
	public static void main(String[] args) throws IOException{
		
		BufferedReader f = new BufferedReader(new FileReader("frac1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("frac1.out")));
		
		int max = Integer.parseInt(f.readLine());
		int denom = 0;
		int numer = 0;
		int length = (int)((Math.pow(max, 2)-max)/2);
		double[] frac = new double[length];
		int[] up = new int[length];
		int[] down = new int[length];
		
		double temp;
		int counter = 0;
		
		for(denom = 1; denom<=max;denom++){
			for(numer = 1; numer<denom;numer++){
				frac[counter] = (double)numer/denom;
				up[counter] = numer;
				down[counter] = denom;
				counter++;
			}
		}
		
		boolean go = true;
		int storage;
		while(go){
	  	   go = false;
	  	   for(int x = 1;x<frac.length;x++){
	  		   if(frac[x]<frac[x-1]){
	  			   temp = frac[x];
	  			   frac[x] = frac[x-1];
	  			   frac[x-1]=temp;
	  			   
	  			   storage = up[x];
	  			   up[x] = up[x-1];
	  			   up[x-1]=storage;
	  			   
	  			   storage = down[x];
	  			   down[x] = down[x-1];
	  			   down[x-1]=storage;
	  			   go = true;
	  		   }
	  	   }
	     }
		
		
		
		
		
		/*for(int x = 0;x<frac.length-1;x++){
			if(frac[x]==frac[x+1]){
				frac = delete(frac, x+1);
				up = delete(up, x+1);
				down = delete(down, x+1);
				x--;
			}
		}*/
		
		
		
		
		
		
		
		out.println("0/1");
		if(frac.length>0) out.println(up[0]+"/"+down[0]);
		
		for(int x = 1;x<frac.length;x++){
			if(frac[x]==frac[x-1]) continue;
			out.println(up[x]+"/"+down[x]);
		}
		
		
		out.println("1/1");
		out.close();
		System.exit(0);
		
	}
	
	static double[] delete(double[] old, int index){
		double[] next = new double[old.length-1];
		int oldC = 0;
		for(int x = 0; x<next.length;x++){
			if(x==index) oldC++;
			next[x] = old[oldC];
			oldC++;
			
			
		}
		return next;
		
	}

	static int[] delete(int[] old, int index){
		int[] next = new int[old.length-1];
		int oldC = 0;
		for(int x = 0; x<next.length;x++){
			if(x==index) oldC++;
			next[x] = old[oldC];
			oldC++;
			
			
		}
		return next;
		
	}
	
	
	
}