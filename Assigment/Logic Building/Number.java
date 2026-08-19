// 1. check number is positive or negative :

import java.util.*;

public class Number{
	public static void main(String args[]){
	
		System.out.println("Enter the num");
      		Scanner s = new Scanner(System.in);
      		int num = s.nextInt();
		
		if(num>0){
			System.out.println("It is a Positive  number");
		}
		else if(num<0){
			System.out.println("It is a Negative  number");
		}
		else{
			System.out.println("Number is 0");
		}
  }
}