package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: nuggets
 */
import java.io.*;
import java.util.*;


/*
 * I mark the maximum not reached mov[x]-1 (the first number unreachable)
 * 
 * I push the next reachable values into my set. If they are a continuous sequence i record it until it reaches mov[x]
 * in which case all nuggest are reachble beacuse all x mod mov[x] are satisfied
 * 
 * if i hit the LCM first then it is unbounded
 * 
 */

public class nuggets {
	
	
	
	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner(new FileReader("nuggets.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("nuggets.out")));
		
		TreeSet<Integer> set = new TreeSet<Integer>();
		
		
		int number = in.nextInt();
		int[] mov = new int[number];
		for(int x = 0;x<number;x++){
			mov[x] = in.nextInt();
			set.add(mov[x]);
		}
		Arrays.sort(mov);
		if(quit(mov)){
			System.out.println("unending");
			out.println(0);
			in.close();
			out.close();
			System.exit(0);
		}
		int seq = 0;

		int max = mov[0]-1;
		long limit = Math.min(LCM(mov),2000000000);
		System.out.println(limit);
		int cur = set.first();
		int past = cur;
		set.remove(cur);
		while(cur<limit){
			if(cur==past+1) seq++;
			else{
				seq = 0;
				max = cur-1;
			}
			if(seq>=mov[0]){//all numbers are reachable
				out.println(max);
				in.close();
				out.close();
				System.exit(0);
			}
			for(int a = 0;a<mov.length;a++) set.add(cur+mov[a]);
			past = cur;
			cur = set.first();
			set.remove(cur);
			//System.out.println(cur);
		}
		out.println(0);//if it reaches 2 million then there will be unbounded
		//System.out.println(dp.length);
		
		
		in.close();
		out.close();
		System.exit(0);
	}
	public static boolean quit(int[] mov){
		
		boolean[] temp = new boolean[mov[0]];
		boolean[] master = new boolean[mov[0]];
		for(int x = 1;x<mov.length;x++){
			int mod = mov[x]%mov[0];
			int cur = mod;
			while(!temp[cur]){
				if(cur==1) return false;//all reachable
				temp[cur] = true;
				cur+=mod;
				cur%=mov[0];
			}
			for(int a = 0;a<temp.length;a++){
				if(temp[a]){
					temp[a]=false;
					master[a]=true;
				}
			}
		}//all mods reachable WITHOUT ADDING IN THE MASTER
		for(int x = 1;x<master.length;x++){
			if(master[x]&&master[1+mov[0]-x]) return false;//all reachable
		}
		return true;//QUIT
		
	}
	
	public static void print(boolean[] dp){
		for(int x = 0;x<1000;x++){
			System.out.print(x+" ");
		}
		System.out.println();
		for(int x = 0;x<1000;x++){
			if(dp[x]) System.out.print(1+" ");
			else System.out.print(0+" ");
		}
	}
	
	public static long GCF(long a, long b){
		if(a<b){
			long temp = a;
			a = b;
			b=temp;
		}
		while(b!=0){
			long m = a%b;
			a = b;
			b = m;
		}
		return a;
	}
	public static long LCM(long a, long b){
		return a*b/GCF(a,b);
	}
	public static long LCM(int[] num){
		
		long cur = num[0];
		
		for(int x = 1;x<num.length;x++){
			cur = LCM(cur, num[x]);
		}
		return cur;
	}
	
	
}
