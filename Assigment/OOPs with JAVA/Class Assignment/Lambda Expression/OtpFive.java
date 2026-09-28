package org.ks.on;

import java.util.function.Supplier;

public class OtpFive {

	public static void main(String[] args) {
		
		//otp five digits first is vowel 
		
		//first Random vowel 
		String s = "AEIOU";
		Supplier<Character> vowel = () -> s.charAt((int)(Math.random() * s.length()));
		System.out.print(vowel.get());
		
		//Random digits
		Supplier<Integer> digit = () -> (int)(Math.random()*10);
		System.out.print(digit.get());
		System.out.print(digit.get());
		System.out.print(digit.get());
		System.out.print(digit.get());

	}

}
