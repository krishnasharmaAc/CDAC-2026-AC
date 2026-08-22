// 3. Display Good Morning message based on time :

import java.util.*;

public class goodMorning{
	public static void main(String args[]){
	
		System.out.println("Enter the time");
      		Scanner s = new Scanner(System.in);
      		int time = s.nextInt();
		
		if(time>=5 && time<12){
			System.out.println("Good Morning");
		}
		
  }
}