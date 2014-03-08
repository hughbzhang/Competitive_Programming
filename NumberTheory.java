package Algorithms;

public class NumberTheory {

		public int GCF(int a, int b){
			if(a<b){
				int temp = a;
				a = b;
				b=temp;
			}
			while(b!=0){
				int m = a%b;
				a = b;
				b = m;
			}
			return a;
		}
		public int LCM(int a, int b){
			return a*b/GCF(a,b);
		}
		public int LCM(int[] num){
			
			int cur = num[0];
			
			for(int x = 1;x<num.length;x++){
				cur = LCM(cur, num[x]);
			}
			return cur;
		}

}
