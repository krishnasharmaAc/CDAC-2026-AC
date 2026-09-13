
public class MainInheritClass {
	public static void main(String [] args ) {
		
		// 1-Parent child method call
		
		Parent parent = new Parent();  
		Child child = new Child(); 
		
		
		//Method of parent class by object of parent class
		parent.parentMethod(); 
		
		//Method of child class by object of child class 
		child.childMethod(); 
		
		//Method of parent class by object of child class
		child.parentMethod();
		
		
		// 2- Member Prime-Membe class
		
		PrimeMembers member = new PrimeMembers(); 
		
		// Input Member details 
		System.out.println("Enter Name:");
		member.setName(ConsoleInput.getString());
		
		System.out.println("Enter Age:"); 
		member.setAge(ConsoleInput.getInt()); 
		
		System.out.println("Enter Phone Number:");
		member.setPhoneNumber(ConsoleInput.getString()); 
		
		System.out.println("Enter Address:");
		member.setAddress(ConsoleInput.getString());
		
		System.out.println("Enter Salary:"); 
		member.setSalary(ConsoleInput.getFloat());
		
		// Input PrimeMember details 
		System.out.println("Enter Joining Year:");
		member.setJoiningYear(ConsoleInput.getInt()); 
		
		System.out.println("Enter Joining Fees:");
		member.setJoiningFees(ConsoleInput.getFloat()); 
		
		System.out.println("Is Active? (true/false):"); 
		member.setActive(Boolean.parseBoolean(ConsoleInput.getString())); 
		// Display all information
		
		
		System.out.println("\n--------- Member Details -----------");
		member.display(); 
		
		// 3-Rectangle and Square area perimeter
		
		 // Rectangle
        Rectangle r = new Rectangle(10, 5);

        System.out.println("Rectangle:");
        r.printArea();
        r.printPerimeter();

        System.out.println();

        // Square
        Square s = new Square(5);

        System.out.println("Square:");
        s.printArea();
        s.printPerimeter();
        
        
        // 4- Shape having circle and rectangle extends also square extends rectangle
        NewSquare objSquare = new NewSquare(); 
        objSquare.printShape();
        objSquare.printRectangle();
        objSquare.printSquare();
        
        //error
       // objSquare.printCircle();
        
       
	}
}
