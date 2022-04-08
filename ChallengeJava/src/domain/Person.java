package domain;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Person {
	protected String firstName;
	protected String lastName;
	protected Date birthday;
	SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yyyy"); //defino formato de fecha
	
	
	public Person() {
		
	}
	
	public Person(String firstName,String lastName,String birthday) { //fecha de tipo String ejemplo "12/09/2001"
		this.firstName = firstName;
		this.lastName = lastName;
		try {
			this.birthday = (Date) formato.parse(birthday);   		//convierto String a tipo Date
		} catch (ParseException e) {
			e.printStackTrace();
		}
	}

	@Override
	public String toString() {
		return "firstName: " + firstName + ", lastName: " + lastName;
	}
	
	public void myInfo() {
		String retorno = this.toString() + " birthday: ";
		if(birthday!=null)  //si no es null formateo el tipo Date
			retorno += formato.format(this.getBirthday());
		else				
			retorno += this.getBirthday();
		System.out.println(retorno);
	}
	
	public boolean comparar(Person persona) {
		return this.getFirstName().equals(persona.getFirstName()) &&  this.getLastName().equals(persona.getLastName()) && 
				this.getBirthday().equals(persona.getBirthday());
	}

	public String getFirstName() {
		return firstName;
	}

	public String getLastName() {
		return lastName;
	}

	public Date getBirthday() {
		return this.birthday;
	}
	
}
