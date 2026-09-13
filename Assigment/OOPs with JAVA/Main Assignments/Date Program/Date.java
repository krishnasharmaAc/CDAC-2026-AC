
public class Date {
	
	private int day;
	private int month;
	private int year;
	
	// settor / mutator
	
	public void setDate(int dd , int mm, int yy) {
		// year directly set 
		year = yy;
		
		// month set 
		if(mm<1 || mm>12) {
			month = 1;
		}
		else {
			month = mm;
		}
		
		// days set
		if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ) {
			if(dd<1 || dd>31 ) {
				day = 1;
			}else {
				day = dd;
			}
		}
		else if(month == 4 || month == 6 || month == 9 || month == 11) {
			if(dd<1 || dd>30 ) {
				day = 1;
			}else {
				day = dd;
			}
		}
		else {
			if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
				if(dd<1 || dd>29 ) {
					day = 1;
				}else {
					day = dd;
				}
			}else {
				if(dd<1 || dd>28 ) {
					day = 1;
				}else {
					day = dd;
				}
			}
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

	        for (int iTemp = 0; iTemp < addToDays; iTemp++) {

	            day++;

	            int maxDays;

	            if (month == 2) {
	                if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
	                    maxDays = 29;
	                } else {
	                    maxDays = 28;
	                }
	            } else if (month == 4 || month == 6 || month == 9 || month == 11) {
	                maxDays = 30;
	            } else {
	                maxDays = 31;
	            }

	            if (day > maxDays) {

	                day = 1;
	                month++;

	                if (month > 12) {
	                    month = 1;
	                    year++;
	                }
	            }
	        }
	    }
		
		
		// Add Months
	    public void addMonths(int months) {

	        for (int iTemp = 0; iTemp < months; iTemp++) {

	            month++;

	            if (month > 12) {
	                month = 1;
	                year++;
	            }

	            int maxDays;

	            if (month == 2) {
	                if (year % 400 == 0 ||(year % 4 == 0 && year % 100 != 0)) {
	                    maxDays = 29;
	                } else {
	                    maxDays = 28;
	                }

	            } else if (month == 4 || month == 6 || month == 9 || month == 11) {
	                maxDays = 30;

	            } else {
	                maxDays = 31;
	            }

	            if (day > maxDays) {
	                day = 1;
	            }
	        }
	    }
		
		// Add years method 
		public void addYears(int years) {

	        year = year + years;

	        //Leap Year
	        
	        if (month == 2 && day == 29) {
	            if (!(year % 400 == 0 ||(year % 4 == 0 && year % 100 != 0))) {
	                day = 28;
	            }
	        }
	    }
		
		
		// Display Date
	    public void displayDate() {
	        System.out.println("Date: " + day + "/" + month + "/" + year);
	    }
		
		
	
}
