import java.util.*;

public class PrintStringArray {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n = 4;
        String arr[] = new String[n];
        System.out.println("Enter the 4 names  : ");

        for (int i=0; i<n; i++){
            arr[i] = s.next();
        }

        for(String val: arr){
            System.out.println(val + " ");
        }
    }
}