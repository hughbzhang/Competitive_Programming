package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: prefix
*/

import java.io.*;
import java.util.*;

public class prefix{
	public static void main(String[] args) throws IOException{
		
		BufferedReader f = new BufferedReader(new FileReader("prefix.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("prefix.out")));
		
		ArrayList<String> mid = new ArrayList<String>();
		
		String temp = f.readLine();
		StringTokenizer st;
		int length = 0;
		
		while(temp.compareTo(".")!=0){
			st = new StringTokenizer(temp);
			int count = st.countTokens();
			for(int x = 0;x<count;x++){
				mid.add(st.nextToken());
			}
			
			temp = f.readLine();
		}
		length = mid.size();
		String[] prim = new String[length];
		for(int x = 0;x<length;x++){
			prim[x] = mid.get(x);//careful the object has multiple references to it.
		}
		
		boolean go = true;
		String storage;
		while(go){
	  	   go = false;
	  	   for(int x = 1;x<prim.length;x++){
	  		   if(prim[x].length()<prim[x-1].length()){
	  			   storage = prim[x];
	  			   prim[x] = prim[x-1];
	  			   prim[x-1]=storage;
	  			   go = true;
	  		   }
	  	   }
	     }
		
		
		
		StringBuffer line = new StringBuffer("");
		temp = f.readLine();
		
		while(temp!=null){
			line.append(temp);
			temp = f.readLine();
		}
		boolean [] dp = new boolean[line.length()+1];
		//System.out.println(dp[3]);
		dp[0]=true;
		int index = 0;
		//boolean start = true;
		int longest = 0;
		
		
		
		
		
		
		
		
		
		for(int x = 0; x<line.length();x++){
			for(int a = 0;a<length;a++){
				index = x-prim[a].length()+1;
				if(index<0) break;//can shorten time here
				
				if((dp[index])&&line.substring(index, x+1).compareTo(prim[a])==0){
					dp[x+1]=true;
					longest = x+1;
					break;
				}
				//else System.out.println(line.substring(index, x+1));
			}
			if(x>(longest+80)) break;//too far to find a prefix
		}
		//System.out.println(dp[0]);
		//for(int x = 1;x<dp.length;x++){
		//	System.out.println(dp[x]+" "+line.charAt(x-1));
		//}
		
		
		out.println(longest);
		
		out.close();
		System.exit(0);
	}
}