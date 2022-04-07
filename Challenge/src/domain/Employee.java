package domain;

public class Employee extends Person {
	private int file;
	private int departament;
	
	public Employee(String firstName,String lastName,String birthday,int file,int departament) {
		super(firstName,lastName,birthday);
		this.file = file;
		this.departament = departament;
	}

	public int getFile() {
		return file;
	}

	public void setFile(int file) {
		this.file = file;
	}

	public int getDepartament() {
		return departament;
	}

	public void setDepartament(int departament) {
		this.departament = departament;
	}
	
	public boolean comparar(Employee empleado) {
		return this.file==empleado.getFile() && this.departament==empleado.getDepartament() && super.comparar(empleado);
	}
	
	@Override
	public String toString() {
		return super.toString() + " file: " + this.getFile() + " departament: " + this.getDepartament();
	}
	
}
