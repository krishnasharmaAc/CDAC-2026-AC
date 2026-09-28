package org.ks.on;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.function.Predicate;
import java.util.function.Supplier;
import java.util.function.BiFunction;
import java.util.function.Consumer;
import java.util.function.Function;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
	//Sort an array Lsit 
		ArrayList<String> list = new ArrayList<>();
		
		list.add("krishna");
		list.add("arjun");
		list.add("tarun");
		
		list.sort((first,second) -> first.compareTo(second)> 0 ? 1 : first.compareTo(second)<0 ? -1 : 0);
		
		System.out.println(list);
		
		
		//find the maximum elemnt in array of integer
		ArrayList<Integer> arr = new ArrayList<>();
		arr.add(19);
		arr.add(42);
		arr.add(10);
		arr.add(32);
		
		Function<ArrayList<Integer>,Integer> fn = num -> 
		{
			int max = num.get(0);
			for(int n : num) {
				if(max<n)
					max = n;
			}	
			return max;
		};
		
		System.out.println("Maximum ELement is : " + fn.apply(arr));
		
		// minimum element in array
		Function<ArrayList<Integer>,Integer> fn2 = num -> 
		{
			int mini = num.get(0);
			for(int n : num) {
				if(mini>n)
					mini = n;
			}	
			return mini;
		};
		
		System.out.println("Minimum ELement is : " + fn2.apply(arr));
		
		//Generate 3 digit randoom number
		Supplier <Integer> number = () -> (int)(Math.random() *1000);
		System.out.println("Num1 : " + number.get());
		
		
		//retuns reverse array
		Consumer<ArrayList<Integer>> consumer = l ->
		{
			for(int temp = l.size()-1; temp>=0; temp--)
				System.out.print(l.get(temp) + " ");
		};
		
		consumer.accept(arr);
		
		//print he current data
		Supplier<LocalDate> date = () -> LocalDate.now();
		System.out.println(date.get());
		
		//Number is prime or not
		
		int variable = 4;
		Predicate<Integer> predicate = num ->
		{
			for(int temp=2; temp<num; temp++) {
				if(num%temp == 0)
					return false;
			}
			return true;
		};
		
		System.out.println(predicate.test(variable));
		
		
		// Concatanation of the string
		String s1 = "Krishna";
		String s2 = "Sharma";
		
		BiFunction<String,String,String> concat = (str1,str2) ->  str1+str2; 
		
		System.out.print(concat.apply(s1,s2));

		
	}

}
