import java.util.*;

public class PrintArray {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n = 5;
        int arr[] = new int[n];
        System.out.println("Enter the 5 integers  : ");

        for (int i=0; i<n; i++){
            arr[i] = s.nextInt();
        }

        for(int val: arr){
            System.out.print(val + " ");
        }

    }
}