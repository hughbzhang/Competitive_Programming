package Solved;
/*
ID: bigfish2
TASK: kimbits
LANG: JAVA
*/

import java.io.*;
import java.util.*;

public class kimbits{
	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner(new FileReader("kimbits.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("kimbits.out")));
		
		int length = in.nextInt();
		int bits = in.nextInt();
		long number = in.nextLong();
		
		
		
		long[][] dp = new long[length+1][bits+1];//[length][bits]
		for(int x = 1;x<=length;x++) dp[x][0] = 1;
		for(int x = 1;x<=bits;x++){
			dp[0][x] = 1;
			dp[1][x] = 2;
		}
		dp[0][0] = 1;
		
		for(int y = 2;y<dp.length;y++){
			for(int x = 1;x<dp[0].length;x++){
				dp[y][x] = dp[y-1][x]+dp[y-1][x-1];
			}
		}
		
		StringBuffer answer = new StringBuffer("");
		int left = bits;
		
		for(int x = length;x>0;x--){
			if(dp[x-1][left]<number){
				answer.append("1");
				number-=dp[x-1][left];
				left--;
			}
			else{
				answer.append("0");
			}
			
		}
		
		//print(dp);
		out.println(answer);
		
		in.close();
		out.close();
		System.exit(0);
	}
	static void print(long[][] dp){
		for(int y = 0;y<dp.length;y++){
			for(int x = 0;x<dp[y].length;x++){
				System.out.print(dp[y][x]+" ");
			}
			System.out.println();
		}
		
	}
}