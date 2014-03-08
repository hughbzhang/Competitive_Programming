package Solved;
import java.awt.Point;
import java.io.*;

public class Eight {
	public static void main(String[] args) throws IOException{
		BufferedReader f = new BufferedReader(new FileReader("LongString"));
		StringBuffer in = new StringBuffer("");
		String temp = f.readLine();
		while(temp!=null){
			in.append(temp);
			temp = f.readLine();
		}
		int[] num = new int[in.length()];
		for(int x = 0;x<num.length;x++){
			num[x] = in.charAt(x)-48;
		}
		Point start = start(0,num);
		if(start==null) System.exit(0);
		int cur = start.x;
		System.out.println(cur);
		int max = 0;
		if(cur>max) max = cur;
		for(int x = start.y;x<num.length;x++){
			//System.out.println(cur);
			if(num[x]==0){
				Point next = start(x+1,num);
				if(next == null) break;
				cur = next.x;
				x = next.y-1;
			}
			else{
				cur/=num[x-5];
				cur*=num[x];
			}
			if(cur>max) max = cur;
		}
		System.out.println(max);
		f.close();
	}
	public static Point start(int start, int[] num){
		int pro  = 1;
		if(start+5>=num.length) return null;
		for(int x = start;x<start+5;x++){
			
			if(num[x]==0) return start(x+1, num);
			pro*=num[x];
		}
		return new Point(pro, start+5);
	}
}
