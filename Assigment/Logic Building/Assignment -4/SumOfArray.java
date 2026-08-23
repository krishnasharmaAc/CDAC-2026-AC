import java.util.*;

public class SumOfArray {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n = 5;
        int arr[] = new int[n];
        System.out.println("Enter the 5 integers  : ");

        for (int i=0; i<n; i++){
            arr[i] = s.nextInt();
        }
        int sum = 0;
        for(int val: arr){
            sum = sum + val;
        }
        System.out.print( "The sum of all numbers is : " + sum);
    }
}
