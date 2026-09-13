

public class NewAdd {
	
	private int day;
	private int month;
	private int year;
	
	private static final int[] arrDaysInMonth = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	
	public boolean isLeapYear(int y) {
    	return (y % 400 == 0 ||(y % 4 == 0 && y % 100 != 0));
    }
	// settor / mutator
	
	public int noOfDays() {
		if(month == 2  && isLeapYear(year))
			return 29;
		else 
			return arrDaysInMonth[month];
		
	}
	
	public void setDate(int dd , int mm, int yy) {
		
		// year directly set 
		if(yy<1900 || yy>2030) {
			year= 2026;
		}
		else {
			year = yy;
		}
		
		
		// month set 
		if(mm<1 || mm>12) {
			month = 1;
		}
		else {
			month = mm;
		}
		
		// days set
		if(dd<1 || dd>noOfDays())	{
			day =1;
		}
		else {
			day = dd;
		}
	}
		
		// gettor / Accessor
		
		public int getDay() {
			return day;
		}
		
		public int getMonth() {
			return month;
		}
		public int getYear() {
			return year;
		}
		
		
		// Add days method 
		public void addDays(int addToDays) {
			int totalDays = day + addToDays;
			
			while(totalDays > noOfDays()) {
				totalDays -= noOfDays();
				addMonths(1);
				day = totalDays;
			}
	    }
		
		
		// Add Months
	    public void addMonths(int monthsToAdd) {
	    	int totalMonths = (month - 1) + monthsToAdd;

	        year = year + totalMonths / 12;

	        month = (totalMonths % 12) + 1;

	        if (day > noOfDays()) {
	            day = noOfDays();
	        }
	    }
	    
	    
		
		// Add years method 
		public void addYears(int yearsToAdd) {
			if(isLeapYear(year) && !(isLeapYear(year+ yearsToAdd)) &&  month == 2 && day == 29) {
				day = 1;
				month = 3;	
			}
			year = year + yearsToAdd;
	    }
		
		
		// Display Date
	    public void displayDate() {
	        System.out.println("Date: " + day + "/" + month + "/" + year);
	    }
		
		
	
}

