
public class Arrays {

    public static void main(String[] args) {
        // Input Array

        System.out.println("Enter the size of the array ::");
        int size = ConsoleInput.getInt();

        int[] arr = new int[size];

        System.out.println("Enter the array elements ::");

        for (int i = 0; i < arr.length; i++) {
            arr[i] = ConsoleInput.getInt();
        }

        System.out.println("\nOriginal Array ::");
        ArraysMethod.printArray(arr);
        // Sum
        int sum = ArraysMethod.sumOfArray(arr);

        System.out.println("Sum is : " + sum);


        // Average
        
        ArraysMethod.averageOfArray(arr);
        

        // Minimum & Maximum
        ArraysMethod.minAndMax(arr);




      
        // Copy Array

        int[] arr2 = ArraysMethod.copyArray(arr);

        System.out.println("\nCopied Array ::");
        ArraysMethod.printArray(arr2);


        // Find Duplicates

        System.out.println("\nDuplicate Elements ::");
        ArraysMethod.findDuplicates(arr);


        // Ascending Sort

        ArraysMethod.sortArray(arr);

        System.out.println("\nArray After Ascending Sort ::");
        ArraysMethod.printArray(arr);


        

        // Swap Example

        if (arr.length >= 2) {

            ArraysMethod.swap(arr, 0, 1);

            System.out.println("\nArray After Swapping First Two Elements ::");
            
            ArraysMethod.printArray(arr);
        }
    }
}


