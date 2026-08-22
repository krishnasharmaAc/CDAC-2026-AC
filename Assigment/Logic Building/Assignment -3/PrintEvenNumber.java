import java.util.*;

class PrintEvenNumber{
	void printEvenNum(){
		int num = 1;
		while(num<=50){
			if(num%2 == 0){
			System.out.print(num + " ");
			}
			num++;
		}
	}
		
	public static void main(String args[]){
		
		PrintEvenNumber obj =  new PrintEvenNumber();
		obj.printEvenNum();
	}
}