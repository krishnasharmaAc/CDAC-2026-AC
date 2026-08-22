import java.util.*;

class PositiveNumber{
	void askForPositiveNumber(){
		Scanner sc = new Scanner(System.in);
		int num;	
		do{
		   System.out.println("Enter the positive Number :");
		   num = sc.nextInt();
		   if(num>0){
			System.out.println("You entered a positive Number : "+ num);
		   }
		}while(num<=0);
		
	}
		
	public static void main(String args[]){
		
		PositiveNumber p = new PositiveNumber();
		p.askForPositiveNumber();
	}
}		

