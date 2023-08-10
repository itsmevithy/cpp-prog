class CircleEg1{
	double radius, area;
	public static void main(String args[]){
		CircleEg1 cirobj;
		cirobj = new CircleEg1();
		cirobj.radius=5;
		cirobj.area=3.14*cirobj.radius*cirobj.radius;
		System.out.println(cirobj.area);
	}
}