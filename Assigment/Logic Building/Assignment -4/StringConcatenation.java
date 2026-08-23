public class StringConcatenation {
    public static void main(String[] args) {
        
    
        String str1 = "Hello";
        String str2 = "World";
        String str3 = str1 + str2;

        System.out.println("String 1 = " + str1);
        System.out.println("String 2 = " + str2);
        System.out.println("String 3 = " + str3);

        
        System.out.println("Is Str3 pointing to the same object as str1 :: " + (str3 == str1));
        
        
        
    }
}

