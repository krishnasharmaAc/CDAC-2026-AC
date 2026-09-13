

public class Rectangle{
	protected double length;
	protected double width;
	
	Rectangle(double length, double width){
		this.length = length;
		this.width = width;		
	}
	
	// Method to print area
    public void printArea() {
        System.out.println("Area = " + (length * width));
    }

    // Method to print perimeter
    public void printPerimeter() {
        System.out.println("Perimeter = " + (2 * (length + width)));
    }

	
}

