import java.util.Scanner;

public class CountVowels {
    public static void main(String[] args) {
        
        System.out.println("Enter the word ::");
        Scanner s = new Scanner(System.in);
        String word = s.next();
        int countVowels = 0;
        for(int i = word.length()-1 ;i>=0; i--){
            if(word.charAt(i) == 'a' || word.charAt(i) == 'e' || word.charAt(i) == 'i' || word.charAt(i) == 'o' || word.charAt(i) == 'u'){
                countVowels++;
            }
        }
        System.out.println("The number of Vowels in " + word + " is : " + countVowels);
    }
}
