import java.util.*;

public class PrintEvenNumbers {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the Num : ");
        int num = s.nextInt();

        for(int i=1; i<=num; i++){
            if(i%2==0){
                System.out.print(i + " ");
            }
        }
    }
}
