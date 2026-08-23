import java.util.*;

class PrintNumbers{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the Num : ");
        int num = s.nextInt();

        for(int i=1; i<=num; i++){
            System.out.print(i + " ");
        }
    }
}