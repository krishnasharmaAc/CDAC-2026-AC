import java.util.*;

public class IndexOfElement {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n = 5;
        int arr[] = new int[n];
        System.out.println("Enter the 5 integers  : ");

        for (int i=0; i<n; i++){
            arr[i] = s.nextInt();
        }
        System.out.println("Enter the Number to be found ::");
        int key = s.nextInt();
        
        Arrays.sort(arr);
        int index = Arrays.binarySearch(arr, key);

        if(index>=0){
            System.out.println("The number " + key + " is found at index : " + index);
        }
        else{
            System.out.println("Not found");
        }
    }
}

