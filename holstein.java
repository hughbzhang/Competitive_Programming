package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: holstein
*/

import java.io.*;
import java.util.*;

public class holstein{
	
	static int vit[][];
	static int length;
	static int total;
	static StringBuffer solution;
	
	
	public static void main(String[]args) throws IOException{
		
		BufferedReader f = new BufferedReader(new FileReader("holstein.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("holstein.out")));
		
		length = Integer.parseInt(f.readLine());
		StringTokenizer st = new StringTokenizer(f.readLine());
		total = Integer.parseInt(f.readLine())+1;
		vit = new int[total][length];
		
		for(int y = 0;y<total;y++){
			for(int x = 0;x<length;x++){
				vit[y][x] = Integer.parseInt(st.nextToken());
			}
			String temp = f.readLine();
			if(temp!=null) st = new StringTokenizer(temp);
		}
		int depth = 0;
		while(solution == null){
			
			depth++;
			
			for(int x = 1; x<total;x++){
				if(search(depth, new StringBuffer(""), x)) break;
			}
			
		}
		
		System.out.println(solution);
		st = new StringTokenizer(solution.toString());
		
		out.print(st.countTokens());
		out.println(solution);
		
		out.close();
		System.exit(0);
	}
	static boolean search(int depth, StringBuffer old, int number){
		
		
		
		StringBuffer code = new StringBuffer(old).append(" ").append(number);
		//System.out.println(code);
		
		
		if(code.length()==depth){
			
			if(check(code)){
				solution = new StringBuffer(code);
				
				return true;
			}
			
			else{
				//System.out.println(code);
				return false;
			}
		}
		
		for(int x = number+1;x<total;x++){
			
			if(search(depth, code, x)) return true;
		}
		
		return false;
	}
	
	
	static boolean check(StringBuffer checker){
		
		int[] test = new int[length];
		
		StringTokenizer st = new StringTokenizer(checker.toString());
		int count = st.countTokens();

		for(int x = 0; x<count;x++){
			
			int a = Integer.parseInt(st.nextToken());
			for(int y = 0;y<length;y++){
				test[y]+=vit[a][y];
			}
			
		}
		
		for(int x = 0;x<length;x++){
			if(test[x]<vit[0][x]) return false;
		}
		return true;
	}
	
	
	
}