import java.util.Scanner;

public class CheckStrPalindrome{
    public static void main(String[] args) {
        
        System.out.println("Enter the word ::");
        Scanner s = new Scanner(System.in);
        String word = s.next();

        int a = 0;
        int b = word.length()-1;
        boolean isPalindrome = true;
        while(a<b){
            if(word.charAt(a) != word.charAt(b)){
                isPalindrome = false;
                break;
            }
            a++;
            b--;
        }
        if (isPalindrome) {
                System.out.println("The String " + word + " is a Palindrome ::");
        } else {
                System.out.println("The String " + word + " is not a Palindrome ::");
        }
    }
}

