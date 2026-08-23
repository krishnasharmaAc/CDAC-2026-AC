import java.util.*;

public class LargestElementArray{

    public static void main(String[] args) {
      Scanner s = new Scanner(System.in);

        int n = 5;
        int arr[] = new int[n];
        System.out.println("Enter the 5 integers  : ");

        for (int i=0; i<n; i++){
            arr[i] = s.nextInt();
        }
        int maxNum = -1;
        for(int val: arr){
            maxNum = Math.max(maxNum,val);
        }  
        System.out.println("Largest number in array is :" + maxNum);
    }
}
