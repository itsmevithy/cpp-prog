class Employee{
	String empname, empdesignation;
	int empid;
	double basicpay, netpay;
	Employee(String empname, String empdesignation, int empid, double basicpay){
		this.empname=empname;
		this.empdesignation=empdesignation;
		this.empid=empid;
		this.basicpay=basicpay;
		this.netpay=this.payBill();
	}
	void empUpdate(String name, String designation, int id, double bpay, double npay){
		this.empname=name;
		this.empdesignation=designation;
		this.empid=id;
		this.basicpay=bpay;
		this.netpay=npay;
	}
	void payBill(){
		double da=0.18*basicpay, hra=0.05*basicpay, pf=0.08*basicpay;
		netpay=basicpay+da+hra-pf;
	}
	void display(){
		System.out.println("Employee name: "+empname);
		System.out.println("Designation: "+empdesignation);
		System.out.println("Employee id: "+empid);
		System.out.println("Basic pay: Rs. "+basicpay);
		System.out.println("Net pay: Rs. "+netpay);	
	}
}