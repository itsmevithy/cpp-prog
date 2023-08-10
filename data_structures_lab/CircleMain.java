class CircleEg3{
	double radius, area;
	void setRadius(double r){
		radius=r;
	}
	void CalculateArea(){
		area=3.14*radius*radius;
		System.out.println("Area "+area);
	}
}
class CircleMain{
	public static void main(String args[]){
		CircleEg2 cirobj1=new CircleEg2();
		cirobj1.setRadius(10);
		cirobj1.CalculateArea();
	}
}