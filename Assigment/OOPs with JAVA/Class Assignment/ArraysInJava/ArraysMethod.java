
public class ArraysMethod {
	
	// Display the Array
	public static void printArray(int [] arr) {
		System.out.println("Printing  the array Elemnts ::");
		for (int iTemp = 0; iTemp < arr.length; iTemp++) {
			System.out.print(arr[iTemp] + " ");
		}
		System.out.println();
	}
	//Swap 
	public static void swap(int[] arr, int index1, int index2) {
	    int temp = arr[index1];
	    arr[index1] = arr[index2];
	    arr[index2] = temp;
	}
	
	// Sort the array
	public static void sortArray(int [] arr) {
		int temp = 0;
		for( int iTemp = 0; iTemp<arr.length-1; iTemp++) {
			for ( int jTemp = iTemp + 1; jTemp<arr.length; jTemp++) {	
				 if(arr[iTemp] > arr[jTemp] ){
					 temp = arr[iTemp]; 
					 arr[iTemp] = arr[jTemp];
					 arr[jTemp] = temp;
				 }
			}
		}
	}
	// SUM OF THE ARRAY
	public static int sumOfArray(int [] arr) {
			int sum = 0;
			for (int iTemp = 0; iTemp <arr.length; iTemp++) {
				sum+= arr[iTemp];
			}
			return sum;
	}
	
	// Average OF THE ARRAY
		public static void averageOfArray(int [] arr) {
				double avg = sumOfArray(arr)/arr.length;
				System.out.println("Average is  : " + avg);
		}
	
	// Min & Max 
		public static void minAndMax(int [] arr) {
			int minElement = arr[0];
			int maxElement = arr[0];
			
			for (int iTemp = 0; iTemp < arr.length; iTemp++) {
				if(arr[iTemp] < minElement)
					minElement = arr[iTemp];
				if(arr[iTemp] > maxElement)
					maxElement = arr[iTemp];
			}
			
			System.out.println("maximum in array :" + maxElement);
			System.out.println("minimum in array :" + minElement);
		}
		
	// COpy array
		public static int[] copyArray(int[] arr) {
			int[] arr2 = new int[arr.length]; 
			for (int i = 0; i < arr.length; i++) {
				arr2[i] = arr[i];
			} 
			return arr2;
		}
		
	// reverse the array
		public static void reverseArray(int [] arr) {
			int iTemp = 0;
			int jTemp = arr.length-1;
			while(iTemp<jTemp) {
				swap(arr,iTemp,jTemp);
				iTemp++;
				jTemp++;
			}
		}
	
	// Duplicates in one array
		public static void findDuplicates(int[] arr) {
			
		    for (int iTemp = 0; iTemp < arr.length; iTemp++) {
		        for (int jTemp = iTemp + 1; jTemp < arr.length; jTemp++) {
		            if (arr[iTemp] == arr[jTemp]) {
		                System.out.println("Duplicate : " + arr[iTemp]);
		                break;
		            }
		        }
		    }
		}	
}
