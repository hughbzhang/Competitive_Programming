package Solved;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

/*
ID: bigfish2
LANG: JAVA
TASK: milk
*/
import java.io.*;
import java.util.*;


class milk{
	
	public static void main (String args[]) throws IOException{
		BufferedReader f = new BufferedReader(new FileReader("milk.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());
		
		int demand = Integer.parseInt(st.nextToken());
		int supply = Integer.parseInt(st.nextToken());
		int cost = 0;
		int[] price = new int[supply];
		int[] amount = new int[supply];
		int prices = 1001;
		int cheapest = -1;
		int counter = 0;
		
		for(int x = 0; x<supply;x++){
		
			StringTokenizer pa = new StringTokenizer(f.readLine());
		
			price[x] = Integer.parseInt(pa.nextToken());
			amount[x] = Integer.parseInt(pa.nextToken());
		if(price[x]<prices){
			prices = price[x];
			cheapest = x;
		}
		}
		
		while(demand != 0){
		//counter++;
		if(counter == 10000){
			System.out.println("loop");
			break;
		}
		if(amount[cheapest] >0){
		demand--;
		amount[cheapest]--;
		cost  = cost + price[cheapest];
		}
		else{
			
			System.out.println(cheapest);
			cheapest = findNext(price, amount, cheapest);
		
		}
		
		}
		out.println(cost);
		
	out.close();
	System.exit(0);
	}
	
	private static int findNext(int[] price, int[] amount, int cheapest){
		
		int prices = 1001;
		int newcheap = -1;
		for(int x = 0; x<price.length;x++){
			if(x == cheapest) continue;
			if(price[x]<prices&&amount[x]>0){
				prices = price[x];
				newcheap = x;
			}
			
			}
		
		return newcheap;
	}
	
	
	
}