class DogDemo{
	String name, breed, color;
	int age;
	
	DogDemo(String name, String breed, String color, int age){
		this.name=name;
		this.age=age;
		this.breed=breed;
		this.color=color;
	}
	
	String getName(){
		return name;
	}
	String getBreed(){
		return breed;
	}
	int getAge(){
		return age;
	}
	String getColor(){
		return color;
	}
	public static void main(String args[]){
		DogDemo tuffy=new DogDemo("Lucinda", "Chihuahua", "Chocolate", 9);
		System.out.println("Hi my name is "+tuffy.getName());
		System.out.println("I am of the breed "+tuffy.getBreed());
		System.out.println("My coat is "+tuffy.getColor()+" in color");
		System.out.println("My age is "+tuffy.getAge());
	}
}