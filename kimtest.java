package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: kimbits
*/

import java.io.*;
import java.util.*;

public class kimtest {
	
	static StringBuffer answer;
	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner(new FileReader("kimbits.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("kimbits.out")));
		
		int length = in.nextInt();
		int bits = in.nextInt();
		long index = in.nextLong();
		long checkpoint = (long)Math.pow(2, bits+1);
		if(index<checkpoint){
			long printer = index-1;
			for(int x = length-1;x>-1;x--){
				if(((1<<x)&printer)!=0) out.print(1);
				else out.print(0);
			}
			out.println();
			in.close();
			out.close();
			System.exit(0);
		}
		answer = new StringBuffer("");
		
		solve(length, bits, index);
		while(answer.length()<length) answer.insert(0, "0");
		out.println(answer);
		
		in.close();
		out.close();
		System.exit(0);
	}
	static void solve(int length, int bits, long index){
		System.out.println(length+" "+bits+" "+index);

		if(length==0) return;
		if(length==bits){
			while(length>0){
				answer.append("1");
				length--;
			}
			return;
		}
		if(bits==0||index==0){
			while(length>0){
				answer.append("0");
				length--;
			}
			return;
		}
		if(index<Math.pow(2, bits+1)){
			while(length>0){
				answer.append("0");
				length--;
			}
			long add = Long.parseLong(answer.toString(),2)+index;
			answer = new StringBuffer(Long.toBinaryString(add));
			return;
		}
		int loop = length-bits-2;
		int counter = (int)Math.pow(2, bits+1);
		long current = counter;
		for(int x = 1;x<=loop;x++){
			
			counter+=current;
			counter-=fact(x, bits);
			current*=2;
		}

		if(index>=counter){
			index-=counter;
			bits--;
			answer.append("1");
		}
		else{
			answer.append("0");
		}
		System.out.println(counter);
		solve(length-1, bits, index);
		return;
		
		
	}
	static int fact(int index, int bits){
		int answer = 0;
		for(int x = index;x>=0;x--){
			answer+=combo(bits+index, x);
		}
		return answer;
	}
	static long combo(int top, int bot){
		
		long answer = 1;
		int counter = bot;
		
		while(counter>0){
			answer*=top;
			top--;
			counter--;
		}
		counter = bot;
		while(counter>1){
			answer/=counter;
			counter--;
		}
		return answer;
	}
}
