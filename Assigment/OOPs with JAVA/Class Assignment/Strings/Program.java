
public class Program {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		// Get the character at given index
		String str = "Java Excercise!";
		System.out.println(str);
		System.out.println("The Charater at position 0 is "+str.charAt(0));
		System.out.println("The Charater at position 10 is "+str.charAt(10));
		
		//Lexicographically check
		String one = "This is Excercise 1";
		String two = "This is Excercise 2";
		
		if(one.compareTo(two)<0)
			System.out.println(one + " is less than "+two);
		else
			System.out.println(one + " is greater than "+two);
		
		//endwith()
		String str1 = "Python Exercises";
        String str2 = "Python Excercise";

        System.out.println("\"" + str1 + "\" ends with \"" + "se" + "\"? "
                + str1.endsWith("se"));

        String str3 = "Python Exercise";

        System.out.println("\"" + str3 + "\" ends with \"" + "se" + "\"? "
                + str3.endsWith("se"));
        
        //index of every element in string
        String sample = "The quick brown fox jumps over the lazy dog";
        sample.toLowerCase();
        
        for(char temp = 'a' ; temp <= 'j'; temp++)
        	System.out.print(temp+" ");
        System.out.println("\n=====================================");
        for(char temp = 'a' ; temp <= 'j'; temp++)
        	System.out.print(sample.indexOf(temp)+" ");
        System.out.println("\n");
        for(char temp = 'k' ; temp <= 't'; temp++)
        	System.out.print(temp+" ");
        System.out.println("\n=====================================");
        for(char temp = 'k' ; temp <= 't'; temp++)
        	System.out.print(sample.indexOf(temp)+" ");
        System.out.println("\n");
        for(char temp = 'u' ; temp <= 'z'; temp++)
        	System.out.print(temp+" ");
        System.out.println("\n=====================================");
        for(char temp = 'u' ; temp <= 'z'; temp++)
        	System.out.print(sample.indexOf(temp)+" ");
        System.out.println();
        
        //Subsring change
        sample = sample.replace("fox", "cat");
        System.out.println(sample);
        
        //change to uppercase
        sample =  sample.toUpperCase();
        System.out.println(sample);
        
        //reverse the string
        //strings are immutable cannot reverse we ceate a another string 
        String reverse ="";
        for(int temp=sample.length()-1;temp>=0; temp--) {
        	reverse+=sample.charAt(temp);
        }
        System.out.println(reverse);
        
		
	}

}
