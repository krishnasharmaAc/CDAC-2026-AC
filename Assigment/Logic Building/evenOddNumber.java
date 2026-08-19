// 1. check number is even or odd :

import java.util.*;

public class evenOddNumber{
	public static void main(String args[]){
	
		System.out.println("Enter the num");
      		Scanner s = new Scanner(System.in);
      		int num = s.nextInt();
		
		if(num%2==0){
			System.out.println("Even  number");
		}
		else{
			System.out.println("Odd number");
		}
  }
}