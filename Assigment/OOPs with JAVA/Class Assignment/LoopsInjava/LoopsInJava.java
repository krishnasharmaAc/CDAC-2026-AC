
public class LoopsInJava {

	public static void main(String[] args) {
		
		// 1- Odd Numbers
		for( int iTemp = 1; iTemp<=1000; iTemp++) {
			if(!(iTemp%2 == 0)) {
				System.out.print(iTemp + " ");
			}
		}
		System.out.println();
		// 2- Even Numbers
				for( int iTemp = 1; iTemp<=500; iTemp++) {
					if(iTemp%2 == 0) {
						System.out.print(iTemp + " ");
					}
				}
		System.out.println();
		// 4- Pattern
					for( int iTemp = 0; iTemp<=5; iTemp++) {	
						for( int jTemp = 1; jTemp<=iTemp; jTemp++) {
							System.out.print("* ");
						}
						System.out.println();
					}
					
					System.out.println();
					// 5- Pattern
					for( int iTemp = 0; iTemp<=5; iTemp++) {	
						for( int jTemp = 4-iTemp; jTemp>=0; jTemp--) {
							System.out.print("* ");
						}
						System.out.println();
					}
				
				System.out.println();
				// 6- Pattern
					int temp = 1;
				for( int iTemp = 0; iTemp<=4; iTemp++) {
					
					for( int jTemp = 0; jTemp<=iTemp; jTemp++) {
					System.out.print(temp++ + " ");
					}
					System.out.println();
				}
		
		
		System.out.println();
		// 7- Pattern
		for( int iTemp = 0; iTemp<=6; iTemp++) {	
			for( int jTemp = 1; jTemp<=iTemp; jTemp++) {
				System.out.print(jTemp + " ");
			}
			System.out.println();
		}
		
		System.out.println();
		// 8- Pattern
		for( int iTemp = 6; iTemp>=0; iTemp--) {
			
			for( int jTemp = 1; jTemp<=iTemp; jTemp++) {
			System.out.print(jTemp + " ");
			}
			System.out.println();
		}
	}

}
