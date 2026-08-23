import java.util.*;

public class CountNumbers{

    public static void main(String[] args) {
      Scanner s = new Scanner(System.in);
        System.out.println("Enter the no.of  integers  : ");
        int n = s.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter the  integers  : ");

        for (int i=0; i<n; i++){
            arr[i] = s.nextInt();
        }
        int positiveCounts = 0;
        int negativeCounts = 0;
    
        for(int i=0; i<n; i++){
            if(arr[i] > 0){
                positiveCounts++;
            }
            else if(arr[i] < 0){
                negativeCounts++;
            }
            else{
                continue;
            }
        } 
        System.out.println(" Positive Number is :" + positiveCounts);
        System.out.println(" Negative Number is :" + negativeCounts);
    }
}

