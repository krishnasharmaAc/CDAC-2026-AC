// 1. check number is positive or negative :

import java.util.*;

public class LeapYear{
	public static void main(String args[]){
	
		System.out.println("Enter the Year :");
      		Scanner s = new Scanner(System.in);
      		int year = s.nextInt();
		
		if (year % 400 == 0) {
            System.out.println(year + " is a Leap Year");
        } 
        else if (year % 100 == 0) {
            System.out.println(year + " is not a Leap Year");
        } 
        else if (year % 4 == 0) {
            System.out.println(year + " is a Leap Year");
        } 
        else {
            System.out.println(year + " is not a Leap Year");
        }
  }
}