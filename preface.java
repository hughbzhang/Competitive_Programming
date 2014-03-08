package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: preface
*/
import java.io.*;

public class preface{
	public static void main(String[] args) throws IOException{
		
		BufferedReader f = new BufferedReader(new FileReader("preface.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("preface.out")));
		
		int max = Integer.parseInt(f.readLine());
		
		char[] rome = new char[]{'M', 'D', 'C', 'L', 'X', 'V', 'I'};
		int[] value = new int[]{1000, 500, 100, 50, 10, 5, 1};
		int[] count = new int[]{0, 0, 0, 0, 0, 0, 0};
		int mod = 0;
		int index = 0;
		int hold = 0;
		StringBuffer holder = new StringBuffer("");
		
		
		for(int x = 1; x<=max;x++){
			mod = x;
			holder = new StringBuffer("");
			
			for(int y = 0; y<7;y++){
				if(mod==0) break;
				hold = mod-value[y];
				if(hold>-1){
					holder.append(rome[y]);
					mod = hold;
					y--;
					continue;
				}
				else{
					if(y==6) continue;
					if(y%2==0) index = y+2;
					else index = y+1;
					
					if(hold>=(-value[index])){
						holder.append(rome[index]);
						holder.append(rome[y]);
						mod-=(value[y]-value[index]);
					}
					
					
				}
			
			}
			for(int a = 0;a<holder.length();a++){
				char key = holder.charAt(a);
				
				switch(key){
				case 'M':
					count[0]++;
					break;
				case 'D':
					count[1]++;
					break;
				case 'C':
					count[2]++;
					break;
				case 'L':
					count[3]++;
					break;
				case 'X':
					count[4]++;
					break;
				case 'V':
					count[5]++;
					break;
				case'I':
					count[6]++;
					break;
				
				default:
					System.out.println("wrong");
					break;
				}
			}
			
			
			
			
		}

		for(int x = 6;x>-1;x--){
			if(count[x]!=0){
				out.println(rome[x]+" "+count[x]);
			}
		}
		
		
	
		out.close();
		System.exit(0);
	}
}