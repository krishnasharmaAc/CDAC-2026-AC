import java.util.*;

class PrintTable{
	void printMultiplicationTable(int num){
		for(int i=1; i<=10;i++){
		System.out.println(num + " x " + i + " = " + num*i);
		}
	}
		
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number");
		int number = sc.nextInt();
		System.out.println("Multiplication Table of " + number + "is :");
		
		PrintTable obj =  new PrintTable();
		obj.printMultiplicationTable(number);
	}
}