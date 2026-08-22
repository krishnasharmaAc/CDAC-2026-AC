import java.util.*;

class Sum{
	int sumOfTwoNumbers(int a , int b){
		int sum = a + b;
		return sum;
	}
		
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the num1");
		int num1 = sc.nextInt();
		System.out.println("Enter the num2");
		int num2 = sc.nextInt();

		Sum add = new Sum();
		int calSum = add.sumOfTwoNumbers(num1, num2);

		System.out.println("Sum is :" + calSum);
		}
	}
		
		