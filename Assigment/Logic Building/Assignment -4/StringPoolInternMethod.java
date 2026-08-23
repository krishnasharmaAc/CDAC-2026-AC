public class StringPoolInternMethod {
    public static void main(String[] args) {
        
    
        String str1 = new String("hello");
        String str2 = str1.intern();
        String str3 = "hello";

        System.out.println("String 1 = " + str1);
        System.out.println("String 2 = " + str2);
        System.out.println("String 3 = " + str3);

        
        System.out.println("Is Str3 and str2 pointing to the same object :: " + (str2 == str3));
        
        
    }
}


