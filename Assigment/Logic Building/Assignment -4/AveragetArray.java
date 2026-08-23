import java.util.*;

public class AveragetArray{

    public static void main(String[] args) {
      Scanner s = new Scanner(System.in);
        System.out.println("Enter the no.of  integers  : ");
        int n = s.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter the  integers  : ");

        for (int i=0; i<n; i++){
            arr[i] = s.nextInt();
        }
        int sum = 0;
    
        for(int val: arr){
            sum = sum + val;
        }
        float avg = (sum/n);  
        System.out.println(" Avergae of the array is :" + avg);
    }
}
