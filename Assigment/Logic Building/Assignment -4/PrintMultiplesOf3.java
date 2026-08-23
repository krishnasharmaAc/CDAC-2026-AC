
import java.util.*;

public class PrintMultiplesOf3 {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the Num : ");
        int num = s.nextInt();

        for(int i=1; i<=num; i++){
            if(i%3==0){
                System.out.print(i + " ");
            }
        }
    }
}
    

