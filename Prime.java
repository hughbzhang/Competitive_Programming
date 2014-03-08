package Algorithms;
import java.util.*;

/*Intersting facts about primes INCOMPLETE

All primes greater than three can be written as 1 or -1 mod 6.
Sieve of Eratosthenes is standard

Using Fermat's little theorem and a strong primality test is the basis of RSA

*/

public class Prime {
	static ArrayList<Integer> primes;
	static boolean[] sieve;//sieve of composites
	
	public static void main(String[] args){
		primes = new ArrayList<Integer>();
		primes.add(2);
		for(int x = 3;x<Math.sqrt(600851475143L);x++){
			if(isPrime(x)) primes.add(x);
		}
		
		System.out.println(factor(600851475143L));
		
	}
	public static void sieve(int max){//SIEVE DOES NOT WORK!!!!!
		int limit = (int)Math.sqrt(max);
		int cur = 3;
		int marker = -1;
		while(cur<=limit){
			marker = (3*cur-3)/2;
			while(marker<=max){
				sieve[marker] = true;
				marker+=cur;
			}
			for(int x = (cur-1)/2;x<max;x++){
				if(!sieve[x]) cur = 2*x+3;
			}
		}
	}
	
	public static boolean isPrime(long test){//Standard Prime Tester
		long max = (long)Math.sqrt(test);
		int counter = 0;
		long prime = primes.get(0);
		while(prime<=max){
			if(test%prime==0) return false;
			counter++;
			prime = primes.get(counter);
		}
		return true;
	}
	public static long factor(long test){//returns the largest prime factor
		
		long max = (long)Math.sqrt(test);
		int counter = 0;
		long prime = primes.get(0);
		while(prime<=max){
			while(test%prime==0) test/=prime;
			counter++;
			prime = primes.get(counter);
			max = (long)Math.sqrt(test);
		}
		return test;
	}
	
	
	
}
