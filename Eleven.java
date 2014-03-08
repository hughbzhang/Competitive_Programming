package Solved;
import java.io.*;
import java.util.*;

public class Eleven {
	public static void main(String[] args) throws IOException{
		BufferedReader f = new BufferedReader(new FileReader("numbers"));
		StringTokenizer st;
		int[][] field = new int[20][20];
		for(int y = 0;y<20;y++){
			st = new StringTokenizer(f.readLine());
			for(int x = 0;x<20;x++){
				field[y][x] = Integer.parseInt(st.nextToken());
			}
			
			
			
		}
		int max = 0;
		int pro = 1;
		
		
		for(int y = 0;y<20;y++){
			for(int x = 0;x<17;x++){
				pro = 1;
				for(int a = x;a<x+4;a++){
					pro*=field[y][a];
				}
				if(pro>max) max = pro;
			}
		}
		for(int x = 0;x<20;x++){
			for(int y = 0;y<17;y++){
				pro = 1;
				for(int a = y;a<y+4;a++){
					pro*=field[a][x];
				}
				if(pro>max) max = pro;
			}
		}
		for(int x = 0;x<17;x++){
			for(int y = 0;y<17;y++){
				pro = 1;
				for(int a = 0;a<4;a++){
					pro*=field[y+a][a+x];
				}
				if(pro>max) max = pro;
			}
		}
		for(int x = 0;x<17;x++){
			for(int y = 0;y<17;y++){
				pro = 1;
				for(int a = 0;a<4;a++){
					pro*=field[y+a][a+x];
				}
				if(pro>max) max = pro;
			}
		}
		for(int x = 19;x>2;x--){
			for(int y = 0;y<17;y++){
				pro = 1;
				for(int a = 0;a<4;a++){
					pro*=field[y+a][x-a];
				}
				if(pro>max) max = pro;
			}
		}
		System.out.println(max);
		f.close();
		
	}
}
