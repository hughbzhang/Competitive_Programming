package Solved;
import java.util.ArrayList;


public class Seven {
	public static void main(String[] args){
		ArrayList<Long> primes = new ArrayList<Long>();
		int size = 0;
		long cur = 1;
		top: while(size<10001){
			cur++;
			for(int x = 0;x<size;x++){
				if(cur%primes.get(x)==0) continue top;
			}
			primes.add(cur);
			size++;
		}
		System.out.println(primes.get(10000));
	}
}
