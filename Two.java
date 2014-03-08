package Solved;

public class Two {
	public static void main(String[] args){
		long past = 1;
		long now = 2;
		long sum = 0;
		while(now<=4000000){
			if(now%2==0) sum+=now;
			long next = now+past;
			past = now;
			now = next;
		}
		System.out.println(sum);
	}
}
