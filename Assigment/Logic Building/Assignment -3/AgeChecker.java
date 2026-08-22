import java.util.*;

class AgeChecker{
	void checkAgeCategory(int age){
		if(age<18){
		   System.out.println("You are a minor ");
		}
		else if(age<60){
		   System.out.println("You are an adult ");
		}
		else{
		   System.out.println("You are senior citizen");
		}
	}
		
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the age");
		int age = sc.nextInt();
		
		AgeChecker check =  new AgeChecker();
		check.checkAgeCategory(age);
		}
	}