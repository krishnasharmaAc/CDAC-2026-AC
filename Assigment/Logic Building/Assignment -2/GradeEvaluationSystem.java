
public class GradeEvaluationSystem{
	public static void main(String args[]){
	
		int mathMarks = 80;
		int scienceMarks = 85;
		int englishMarks = 90;

        int avg = (mathMarks+scienceMarks+englishMarks)/3;
         System.out.println("Average marks: " + avg);
		
		if(avg>=90){
			System.out.println("Grade: A");
		}
		else if(avg>=70 && avg<90){
			  System.out.println("Grade: B");
		}
        else if(avg>=50 && avg<70){
			  System.out.println("Grade: C");
		}
        else if(avg>=30 && avg<50){
			  System.out.println("Grade: D");
		}
		else{
			 System.out.println("Fail");
		}
  }
}
