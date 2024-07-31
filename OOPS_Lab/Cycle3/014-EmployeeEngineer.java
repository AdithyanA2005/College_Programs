class Employee {
  void display() {
    System.out.println("Name of the class is Employee");
  }

  void calcSalary() {
    System.out.println("Salary of employee is 10000");
  }
}

class Engineer extends Employee {
  @Override
  void calcSalary() {
    System.out.println("Salary of employee is 20000");
  }
}

class EmployeeEngineer {
  public static void main(String[] args) {
    Engineer engineer = new Engineer();
    engineer.display();
    engineer.calcSalary();
  }
}
