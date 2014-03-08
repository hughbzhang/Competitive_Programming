package Solved;
import java.io.*;
import java.util.*;


public class SixtySeven {
	public static void main(String[] args)throws IOException{
		
		int NUMBER= 100;
		
		int[][] triangle = new int[NUMBER][NUMBER];
		int[][] dp = new int[NUMBER][NUMBER];
		Scanner in = new Scanner(new FileReader("triangle"));
		
		for(int y = 0;y<NUMBER;y++){
			for(int x = 0;x<=y;x++){
				triangle[y][x] = in.nextInt();
			}
		}
		for(int x = 0;x<NUMBER;x++){
			dp[NUMBER-1][x] = triangle[NUMBER-1][x];
		}
		for(int y = NUMBER-2;y>=0;y--){
			for(int x = 0;x<=y;x++){
				dp[y][x] = Math.max(dp[y+1][x], dp[y+1][x+1])+triangle[y][x];
			}
		}
		System.out.println(dp[0][0]);
		
		//print(dp);
		in.close();
	}
	public static void print(int[][] print){
		for(int y = 0;y<print.length;y++){
			for(int x = 0;x<print.length;x++){
				System.out.print(print[y][x]+" ");
			}
			System.out.println();
		}
	}
}
