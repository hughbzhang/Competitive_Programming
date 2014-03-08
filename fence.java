package Solved;

/*
ID: bigfish2
LANG: JAVA
TASK: fence
*/
import java.io.*;
import java.util.*;

public class fence {
	static int[] circuit;
	static int counter = 0;
	static int[][] matrix;
	
	public static void main(String[] args)throws IOException{
		BufferedReader f = new BufferedReader(new FileReader("fence.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("fence.out")));
		int number = Integer.parseInt(f.readLine());
		circuit = new int[number+1];
		matrix = new int[501][501];
		int[] count = new int[501];
		int max = 0;
		int min = 500;
		for(int x = 0;x<number;x++){
			StringTokenizer st = new StringTokenizer(f.readLine());
			int first = Integer.parseInt(st.nextToken());
			int sec = Integer.parseInt(st.nextToken());
			matrix[first][sec]++;
			matrix[sec][first]++;
			if(max<first) max = first;
			if(max<sec) max = sec;
			if(min>first) min = first;
			if(min>sec) min = sec;
			count[first]++;
			count[sec]++;
		}
		max++;
		int start = min;
		for(int x = 0;x<count.length;x++){
			if(count[x]%2==1){
				start = x;
				break;
			}
		}
		fast(start);
		
		
		
		
		for(int x = circuit.length-1;x>-1;x--){
			out.println(circuit[x]);
		}
		
		//for(int x = 0;x<odd.size();x++) System.out.println(odd.get(x));
		out.close();
		System.exit(0);
	}
	static void find(int start){
	//	System.out.println(start);
		int temp = neighbor(start);
		if(temp == 0){
			circuit[counter] = start;
			counter++;
		}
		else{
			while(temp!=0){
				
				matrix[start][temp]--;
				matrix[temp][start]--;
				find(temp);
				temp = neighbor(temp);
			}
			circuit[counter] = start;
			counter++;
		}
	}
	static void fast(int start){
		Stack<Integer> path = new Stack<Integer>();
		path.push(start);
		top: while(path.size()>0){	
			start=path.peek();
			int temp = neighbor(start);
			if(temp == 0){
				circuit[counter] = start;
				counter++;
				path.pop();
			}
			else{
				while(temp!=0){
					matrix[start][temp]--;
					matrix[temp][start]--;
					path.push(temp);
					continue top;
				}
				circuit[counter] = start;
				counter++;
			}
		}
		
		
		
		
		
		
		
		
	}
	
	
	static int neighbor(int start){
		for(int x = 0;x<501;x++){
			if(matrix[start][x]!=0) return x;
		}
		return 0;
	}
}