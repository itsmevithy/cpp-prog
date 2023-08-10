class CircleEg2{
	double radius, area;
	void setRadius(double r){
		radius=r;
	}
	void CalculateArea(){
		area=3.14*radius*radius;
		System.out.println("Area "+area);
	}
	public static void main(String args[]){
		CircleEg2 cirobj1=new CircleEg2(), cirobj2=new CircleEg2();
		cirobj1.setRadius(10);
		cirobj2.setRadius(50);
		cirobj2=cirobj1;
		cirobj1.CalculateArea();
		cirobj2.CalculateArea();
	}
}