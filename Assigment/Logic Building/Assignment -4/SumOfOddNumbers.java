import java.util.*;

public class SumOfOddNumbers {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the Num : ");
        int num = s.nextInt();
        int sum = 0;

        for(int i=1; i<=num; i++){
            if(i%2!=0){
                sum = sum + i;
            }
        }
        System.out.println("The Sum of odd Numbers from 1 To " + num + " is : " + sum);
    }
}