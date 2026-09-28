package org.lambda.in;

import java.util.Arrays;
import java.util.List;
import java.util.function.Consumer;
import java.util.function.Function;




public class Program {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		List<Transaction> trans = Arrays.asList(new Transaction(1001,10000,false,true),
												new Transaction(1002,4000,true,false),
												new Transaction(1003,12500,true,true),
												new Transaction(1004,8000,false,true),
												new Transaction(1005,3500,false,false));
		
		// Tax Amount > 5000
		Consumer<List<Transaction>> consume = list -> {
			for(Transaction t : list) {
				if(t.getTaxAmount()>5000)
					System.out.println(t);
			}
		};
		consume.accept(trans);

        System.out.println("*****************************************************************");
		
		
		//Tax Status is false
		Consumer<List<Transaction>> consumeStatus = list -> {

            for (Transaction t : list) {

                if (!t.isTaxStatus()) {
                    System.out.println(t);
                }
            }
        };
		consumeStatus.accept(trans);
		
		System.out.println("*****************************************************************");
		
		//Generate amount due
		Function<Transaction,Double> amount = t ->{
			if(t.isTaxArrears()) {
				return t.getTaxAmount() + 500 + (0.18 * t.getTaxAmount());
			}
			return (double)(t.getTaxAmount());
		};
		
		for (Transaction t : trans) {
            System.out.println("Amount Due = " + amount.apply(t));
        }
		
		
		
		
		
		
		
		
		
	}

}
