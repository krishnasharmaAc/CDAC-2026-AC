package org.lambda.in;

public class Transaction {
	int taxId;
	float taxAmount;
	boolean taxStatus;
	boolean taxArrears;
	public int getTaxId() {
		return taxId;
	}
	
	public Transaction() {
		
	}
	public Transaction(int taxId, float taxAmount, boolean taxStatus, boolean taxArrears) {
		super();
		this.taxId = taxId;
		this.taxAmount = taxAmount;
		this.taxStatus = taxStatus;
		this.taxArrears = taxArrears;
	}

	@Override
	public String toString() {
	    return "Tax ID: " + taxId + 
	           ", Tax Amount: " + taxAmount +
	           ", Tax Status: " + taxStatus +
	           ", Tax Arrears: " + taxArrears;
	}
	
	public void setTaxId(int taxId) {
		this.taxId = taxId;
	}
	public float getTaxAmount() {
		return taxAmount;
	}
	public void setTaxAmount(float taxAmount) {
		this.taxAmount = taxAmount;
	}
	public boolean isTaxStatus() {
		return taxStatus;
	}
	public void setTaxStatus(boolean taxStatus) {
		this.taxStatus = taxStatus;
	}
	public boolean isTaxArrears() {
		return taxArrears;
	}
	public void setTaxArrears(boolean taxArrears) {
		this.taxArrears = taxArrears;
	}
	
	

}
