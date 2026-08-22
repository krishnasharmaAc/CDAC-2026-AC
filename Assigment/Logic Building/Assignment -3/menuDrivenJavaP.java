import java.util.Scanner;

public class menuDrivenJavaP{

                    static int i;
                    static float f;
                    static char ch;
                    static double d;
                    static byte by;
                    static short st;
                    static boolean b;
                    static long l;
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        int choice;
        char solved;

        do {
            System.out.println("===== MENU =====");
            System.out.println("Press 1 for Problem 1: Leap Year Check");
		    System.out.println("Press 2 for Problem 2: Grade Evalution System");
		    System.out.println("Press 3 for Problem 3: Day of the week");
		    System.out.println("Press 4 for Problem 4: Identify Default Values of Variables");
		    System.out.println("Press 5 for Exit");

            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {

                case 1:
                    System.out.print("Enter year: ");
                    int year = sc.nextInt();

                    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
                        System.out.println("It is a Leap Year");
                    } else {
                        System.out.println("It is not a Leap Year");
                    }
                    break;

                case 2:
                    System.out.print("Gradeof the student is : ");

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
                    break;

                case 3:
                    System.out.print("Enter day number (1-7): ");
                    int day = sc.nextInt();

                    switch (day) {
                        case 1:
                            System.out.println("Monday");
                            break;
                        case 2:
                            System.out.println("Tuesday");
                            break;
                        case 3:
                            System.out.println("Wednesday");
                            break;
                        case 4:
                            System.out.println("Thursday");
                            break;
                        case 5:
                            System.out.println("Friday");
                            break;
                        case 6:
                            System.out.println("Saturday");
                            break;
                        case 7:
                            System.out.println("Sunday");
                            break;
                        default:
                            System.out.println("Invalid Day");
                    }
                    break;

                case 4:
                    System.out.println("Default values of Primitive Data Types :::::::");

                    System.out.println("Default value of int is : " + i);
                    System.out.println("Default value of double is : " + d);
                    System.out.println("Default value of boolean is : " + b);
                    System.out.println("Default value of char is :" + ch);
                    System.out.println("Default value of long is : "+ l);
                    System.out.println("Default value of float is : " + f);
                    System.out.println("Default value of short is :" + st);
                    System.out.println("Default value of byte is : "+ by);


                    break;

                case 5:
                    System.out.println("Program Exited.");
                    break;

                default:
                    System.out.println("Invalid Choice!");
                    continue;
            }

            // Ask user whether the problem is solved
            if (choice != 5) {
                System.out.print("\nIs your problem solved? (Y/N): ");
                solved = sc.next().charAt(0);

                if (solved == 'Y' || solved == 'y') {
                    System.out.println("Thank you! Program Exited.");
                    break;
                }
            }

        } while (choice != 5);
    }
}