import java.util.Scanner;

class Phone{
	double width, height;
	int price;
	String brand, OS;
	Phone(double width, double height, String os, String brand, int price){
		this.width=width;
		this.height=height;
		this.OS=os;
		this.brand=brand;
		this.price=price;
	}
	void call(){
		long number;
		System.out.print("Call:- \nEnter mobile number to call: ");
		Scanner in= new Scanner(System.in);
		number=in.nextLong();
		System.out.println("Calling... "+number);
		System.out.println("The number you're trying to reach, is not answering your call. Please try again later.\n");
	}
	void sendMessage(){
		long number;
		System.out.print("Message:-\nEnter mobile number to send message: ");
		Scanner in= new Scanner(System.in);
		number=in.nextLong();
		System.out.print("Enter message: ");
		String msg="";
		in.skip("[\r\n]+");
		msg+=in.nextLine();
		System.out.println("Sending message... to "+number);
		System.out.println("Message Sent!\n"+msg+"\n");
	}
	void browse(){
		String site="";
		System.out.print("Browse:-\nEnter website to browse: ");
		Scanner in= new Scanner(System.in);
		site+=in.nextLine();
		System.out.println("Trying to reach "+site);
		System.out.println("Site unreachable. Not connected to internet!\n");
	}
	void share(){
		System.out.println("Share:-\nNote: The message will be shared to last 5 number in your recently contacted list.");
		String msg="";
		Scanner in= new Scanner(System.in);
		System.out.print("Enter message: ");
		msg+=in.nextLine();
		System.out.println("Message Shared!\n"+msg+"\n");
	}
}

class PhoneMain{
	public static void main(String args[]){
		Phone myandroid, myapple;
		myandroid= new Phone(6.98, 13.6, "Android", "Samsung", 70000);
		myapple= new Phone(5.86, 12.3, "iOS", "Apple", 100000);
		System.out.println("Samsung:-");
		myandroid.call();
		myandroid.sendMessage();
		myandroid.browse();
		myandroid.share();
		System.out.println("Apple:-");
		myapple.call();
		myapple.sendMessage();
		myapple.browse();
		myapple.share();
	}
}