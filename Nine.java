package Solved;
//Pythagorean triples


public class Nine {
	public static void main(String[] args){
		
		for(int n = 1;n<35;n++){
			for(int m = n+1;m<=1000/n;m=m+2){
				if(GCF(n,m)==1){
					if(test(n,m)) System.exit(0);
				}
			}
		}
		
	}
	public static boolean test(int n, int m){
		int sum = 2*(m*m+m*n);
		if(1000%sum==0){
			int S = 1000/sum;
			System.out.println(S*(m*m-n*n)*S*2*m*n*S*(m*m+n*n));
			return true;
		}
		else return false;
	}
	
	public static int GCF(int a, int b){
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
}
