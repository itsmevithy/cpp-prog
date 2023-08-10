class Lamp{
	boolean ison;
	void turnOn(){
		ison=true;
		System.out.println("Light on? "+ ison);
	}
	void turnOff(){
		ison=false;
		System.out.println("Light on? "+ison);
	}
}
class LampMain{
	public static void main(String args[]){
		Lamp led=new Lamp();
		Lamp halogen= new Lamp();
		led.turnOn();
		halogen.turnOff();
	}
}