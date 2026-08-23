import java.util.*;

public class ElementCheck {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n = 5;
        int arr[] = new int[n];
        System.out.println("Enter the 5 integers  : ");

        for (int i=0; i<n; i++){
            arr[i] = s.nextInt();
        }

        System.out.println("Enter the Number to be found ::");
        int key = s.nextInt();

        boolean isPresent = false;
        
        for(int i=0; i<n; i++){
            if(key == arr[i]){
                isPresent = true;
                break;
            }
        }
        if(isPresent){
            System.out.println("Found");
        }
        else{
            System.out.println("Not found");
        }
    }
}
