package Solved;

public class Six {
	public static void main(String[] args){
		long one = 5050*5050;
		long two = 0;
		for(long x = 1;x<=100;x++){
			two+=(x*x);
		}
		System.out.println(one-two);
	}
}
