public class MultipleStringLiterals {
    public static void main(String[] args) {
        String str1 = "java";
        String str2 = "java";
        String str3 = "java";

        boolean isSame ;
        if((str1==str2) && (str2==str3) && (str3==str1)){
            isSame = true;
            System.out.println("All strings point to the same object : " + isSame);
        }else{
            isSame = false;
             System.out.println("All strings point to the same object : " + isSame);
        }
    }
}
