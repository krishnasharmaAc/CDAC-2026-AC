public class StringLiteral {
    public static void main(String[] args) {
        
    
        String s1 = "Hello";
        String s2 = "Hello";

        System.out.println("String 1 = " + s1);
        System.out.println("String 2 = " + s2);

        if(s1==s2){
            System.out.println("Both variables point to the same object");
        }else{
        System.out.println("Not point to the same object");
        }
    }
}
