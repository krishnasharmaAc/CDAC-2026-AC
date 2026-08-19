// 1. check largest number:



public class largestNumber{
	public static void main(String args[]){
	
		int a = 10;
		int b = 49;
		int c = 15;
		
		if(a>b){
			if(a>c){
				System.out.println("A is largest number");
			}
			else{
			     System.out.println("C is largest number");
			}
		}
		else{
			if(b>c){
				System.out.println("B is largest number");
			}
			 else{
			     System.out.println("C is largest number");
			}
		}
  }
}