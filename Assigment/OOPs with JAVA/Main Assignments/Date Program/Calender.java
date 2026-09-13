

public class Calender{
	
	public static void main(String [] args) {
		
		int choice;
		//char solved;
		
		 NewAdd objDate = new NewAdd();
		
		do {
			
			
			System.out.println("********** Welcome to the Menu Driven Program -- Calender ********");
			System.out.println("1. Set Date ");
			System.out.println("2. ADD Days ");
			System.out.println("3. ADD Months ");
			System.out.println("4. ADD Years ");
			System.out.println("5. Set Display ");
			System.out.println("6. Compare Dates ");
			System.out.println("7. Exit ");
			
			 System.out.print("Enter your choice: ");
			 choice = ConsoleInput.getInt();
			 
			
			 
			 
			 switch(choice){
				 case 1:
						
						System.out.println("Enter the day :");
						int day = ConsoleInput.getInt();
						
						System.out.println("Enter the month :");
						int m = ConsoleInput.getInt();
						
						System.out.println("Enter the year :");
						int y = ConsoleInput.getInt();
						
						objDate.setDate(day,m,y);
						
						System.out.println(" Date is set ");
						
						break;
				
				 case 2:
				
		                System.out.print("Enter number of days to add: ");
		                int days = ConsoleInput.getInt();

		                objDate.addDays(days);

		                System.out.println("Days added .");

		                break;
			

		            case 3:
		            
		                System.out.print("Enter number of months to add : ");
		                int months = ConsoleInput.getInt();

		                objDate.addMonths(months);

		                System.out.println("Months added .");

		                break;
		            


		            case 4:{

		                System.out.print("Enter number of years to add : ");
		                int years = ConsoleInput.getInt();

		                objDate.addYears(years);

		                System.out.println("Years added .");

		                break;
		            }


		            case 5:

		                objDate.displayDate();
		                break;


		            case 6:

		                // objDate.compareDate();
		                break;

		                
		            default:

		                System.out.println("Invalid choice! Please enter a choice between 1 and 7." );
		                break;
			 }
		            			 
			 
		}while(choice != 7);
		
		System.out.println("Thank You");	
	}
		
}
