
public class Main {
	
	public static void main(String [] args) {
		int menuChoice;
		int addEmployeeChoice;
		int displayChoice;
		int sortChoice;
		
		// Create AddEmployee object 
		AddEmployee addEmployee = new AddEmployee(); 
		// Create DisplayEmployee object 
		DisplayEmployee displayEmployee = new DisplayEmployee( addEmployee.getEmployees(), addEmployee.getEmployeeCount());
		// Create SortEmployee Object
		SortEmployees sortEmployee;
		
		do {
			
			System.out.println("\n********** Welcome to the Menu Driven Program -- Employee Organisation********");
			System.out.println("1. Add an Employee");
			System.out.println("2. Display");
			System.out.println("3. Sort");
			System.out.println("4. Save");
			System.out.println("5. Delete ");
			System.out.println("6. Load");
			System.out.println("7. Exit the Program");
			
			 System.out.print("Enter your choice: ");
			 menuChoice = ConsoleInput.getInt();
			 
			 switch(menuChoice){
				 case 1:
						
						do {
							System.out.println("\n********Add an Employee********");
							System.out.println("1. Add Manager");
							System.out.println("2. Engineer");
							System.out.println("3. SalesPerson");
							System.out.println("4. Exit to Main Menu ");
							
							 System.out.print("Enter your Employee choice: ");
							 addEmployeeChoice = ConsoleInput.getInt();
							 
							 switch(addEmployeeChoice) {
							 case 1:
								 addEmployee.addManager();
								 break;
								 
							 case 2:
								 addEmployee.addEngineer();
								 break;
								 
							 case 3:
								 addEmployee.addSalesPerson();
								 break;
								 
							 case 4:
								 System.out.println("Returning to Main Menu...");
								 break;
							
							default:
								System.out.println("Invalid choice.");
							 }
							 
						}while(addEmployeeChoice != 4 );
						break;
						

		            case 2:
		            	
		            	displayEmployee = new DisplayEmployee(
		            	        addEmployee.getEmployees(),
		            	        addEmployee.getEmployeeCount()
		            	  );
		            	 do {
								System.out.println("\n********Display an Employee********");
								System.out.println("1. All Eployees");
								System.out.println("2. First Employee");
								System.out.println("3. Next Eployee");
								System.out.println("4. perivious Employee");
								System.out.println("5. Last Employee");
								System.out.println("6. Exit to Main Menu ");
								
								 System.out.print("Enter your Display choice: ");
								 displayChoice = ConsoleInput.getInt();
								 
								 switch(displayChoice) {
								 case 1:
									 displayEmployee.displayAll();
									 break;
									 
								 case 2:
									 displayEmployee.firstEmployee();
									 break;
									 
								 case 3:
									 displayEmployee.nextEmployee();
									 break;
								
								 case 4:
									 displayEmployee.previousEmployee();
									 break;
									 
								 case 5:
									 displayEmployee.lastEmployee();
									 break;
									 
								 case 6:
									 System.out.println("Returning to Main Menu...");
									 break;
								
								default:
									System.out.println("Invalid choice.");
								 }
								 
							}while(displayChoice != 6);

		                break;
		            	 
		            case 3:
						sortEmployess = new SortEmployees(addEmployee.getEmployees(),addEmployee.getEmployeeCount());
						 do {
								System.out.println("\n********Sort Employee********");
								System.out.println("1. All Employees Alphabetic order ascending");
								System.out.println("2. All Employees Alphabetic order descending");
								System.out.println("3. Designation");
								System.out.println("4. Exit to Main Menu ");
								
								 System.out.print("Enter your Sort choice: ");
								 sortChoice = ConsoleInput.getInt();
								 
								 switch(sortChoice) {
								 case 1:
									 sortEmployee.sortAscending();
									 break;
									 
								 case 2:
									 sortEmployee.sortDescending();
									 break;
									 
								 case 3:
									 //sortEmployees.sortDesignation();
									 break;
									 
								 case 4:
									 System.out.println("Returning to Main Menu...");
									 break;
								
								default:
									System.out.println("Invalid choice.");
								 }
								 
							}while(sortChoice != 4 );
						 
							break;
		            


		            case 4:{
		            	//Save to File
		                System.out.println("Save to file : coming soon ");
		                break;
		            }


		            case 5:

		            	//Delete to File
		                System.out.println("Delete  file : coming soon ");
		                break;


		            case 6:

		                //Load from File
		                System.out.println("Load from file : coming soon ");
		                break;
		                
		            case 7:
		                //Load from File
		                System.out.println("Exiting The Program");
		                break;
		                
		            default:
		            	
		                System.out.println("Invalid choice! Please enter a choice between 1 and 7." );
		                break;
			 }
		            			 
			 
		}while(menuChoice != 7);
		
		System.out.println("Thank You");	
	}

}
