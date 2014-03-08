package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: sort3
 */
import java.io.*;

public class sort3 {
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader f = new BufferedReader(new FileReader("sort3.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("sort3.out")));
		
		int length = Integer.parseInt(f.readLine());
		int[] seq = new int[length];
		int one = 0;
		int two = 0;
		//int three = 0;
		int first = 0;
		int second = 0;
		int third = 0;
		int fourth = 0;
		int fifth = 0;
		int sixth = 0;
		int place = 1;
		int changes = 0;
		int temp = 0;
		
		
		for(int x =0;x<length;x++){
			
			seq[x] = Integer.parseInt(f.readLine());
			if(seq[x]==1) one++;
			else if(seq[x]==2) two++;
			//else three++;
		}
		//System.out.println(one+" "+two+" "+three);
		
		for(int x = 0;x<length;x++){
			if(x<one) place = 1;
			else if(x>one+two-1) place = 3;
			else place = 2;
			
				 if(place==1&&seq[x]==2) first++;
			else if(place==1&&seq[x]==3) second++;
			else if(place==2&&seq[x]==1) third++;
			else if(place==2&&seq[x]==3) fourth++;
			else if(place==3&&seq[x]==1) fifth++;
			else if(place==3&&seq[x]==2) sixth++;
			
			
		}
		//first and third
		//second and fifth
		//fourth and sixth
		
		temp = Math.min(first, third);
		first -=temp;
		third -=temp;
		changes+=temp;
		
		//System.out.println(changes);
		
		temp = Math.min(second, fifth);
		second -=temp;
		fifth -=temp;
		changes+=temp;
		
		//System.out.println(changes);
		
		temp = Math.min(fourth, sixth);
		fourth -=temp;
		sixth -=temp;
		changes+=temp;
		
		//System.out.println(changes);
		
		changes+=(first+second+third+fourth+fifth+sixth)*2/3;
		
		//System.out.println(changes);
		out.println(changes);
		out.close();
		System.exit(0);
		
	}
}
