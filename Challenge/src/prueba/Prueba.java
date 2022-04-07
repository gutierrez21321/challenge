package prueba;

import domain.*;

public class Prueba {

	public static void main(String[] args) {
		Person persona1 = new Person("jose maria","gutierrez","12/09/2001");
		Person persona2 = new Person();
		Person persona3 = new Person("jose maria","gutierrez","12/09/2001");
		Person persona4 = new Person("hernan","alvarez","22/11/1990");
		Person empleado1 = new Employee("jose maria","gutierrez","12/09/2001",2,2);
		Person empleado2 = new Employee("jose maria","gutierrez","12/09/2001",2,2);
		Person empleado3 = new Employee("jorge","hernandez","21/03/1977",3,5);
		persona1.myInfo();
		persona2.myInfo();
		persona4.myInfo();
		empleado1.myInfo();
		System.out.println(empleado1.comparar(empleado2));
		System.out.println(empleado1.comparar(empleado3));
		System.out.println(empleado2.comparar(empleado1));
		System.out.println(persona1.comparar(persona3));
		System.out.println(persona1.comparar(persona2));
		System.out.println(persona4.comparar(persona3));
	}

}
