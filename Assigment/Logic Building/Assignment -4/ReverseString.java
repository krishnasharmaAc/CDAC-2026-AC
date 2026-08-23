import java.util.Scanner;

public class ReverseString {
    public static void main(String[] args) {
        
        System.out.println("Enter the word ::");
        Scanner s = new Scanner(System.in);
        String word = s.next();

        for(int i = word.length()-1 ;i>=0; i--){
            System.out.print(word.charAt(i));
        }
    }
}
