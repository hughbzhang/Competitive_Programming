package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: hamming
*/
import java.io.*;
import java.util.*;

public class hamming{
	
	static int size;
	static int length;
	static int dist;
	static StringBuffer[] list;
	
	public static void main(String[]args) throws IOException{
		
		BufferedReader f = new BufferedReader(new FileReader("hamming.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("hamming.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());
		
		size = Integer.parseInt(st.nextToken());
		length = Integer.parseInt(st.nextToken());
		dist = Integer.parseInt(st.nextToken());
		list = new StringBuffer[size];
		
		int max = (int) Math.pow(2, length);
		StringBuffer temp;
		int counter = 0;
		
		for(int x = 0;x<max;x++){
			temp = new StringBuffer(Integer.toBinaryString(x));
			while(temp.length()<length) temp.insert(0, "0");
			if(compare(temp)){
				list[counter] = temp;
				counter++;
				
			}
			if(counter==size) break;
			//System.out.println(temp);
			
		}
		counter = 1;
		
		out.print(Integer.parseInt(list[0].toString(), 2));
		
		for(int x = 1 ;x<list.length;x++){
			if(list[x]==null) break;
			counter++;
			if(counter == 11){
				out.println();
				out.print(Integer.parseInt(list[x].toString(), 2));
				counter=1;
			}
			
			else out.print(" "+Integer.parseInt(list[x].toString(), 2));
		}
		out.println();
		out.close();
		System.exit(0);
	}
	
	static boolean compare(StringBuffer comp){
		
		int y = 0;
		int counter = 0;
		
		while(y<size&&list[y]!=null){
			
			for(int x = 0;x<length;x++){
				if(comp.charAt(x)!=list[y].charAt(x)) counter++;
			}
			
			//System.out.println(counter);
			
			if(counter<dist) return false;
			
			y++;
			counter = 0;
		}
		
		return true;
	}
	
	
	
	
}