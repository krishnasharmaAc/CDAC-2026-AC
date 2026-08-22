import java.util.*;

class AdditionToN{
	int calculateSum(int num){
		int add = 0;
		for(int i=1; i<=num;i++){
		add = add + i;
		}
		return add;
	}
		
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number");
		int number = sc.nextInt();
		
		
		AdditionToN obj =  new AdditionToN();
		int sum = obj.calculateSum(number);
		System.out.println("The sum of numbers from 1 to " + number + " is : " + sum);
	}
}