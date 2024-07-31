class Employee {
  String name;
  int age;
  String phoneNumber;
  String address;
  double salary;

  void printSalary() {
    System.out.println("Salary: " + salary);
  }
}

class Officer extends Employee {
  String specialization;
}

class Manager extends Employee {
  String department;
}

class EmployeeAndClasses {
  public static void main(String[] args) {
    Officer officer = new Officer();
    officer.name = "Amjad";
    officer.age = 99;
    officer.phoneNumber = "1234567890";
    officer.address = "xxx yyy zzz";
    officer.salary = 500.0;
    officer.specialization = "IT";

    Manager manager = new Manager();
    manager.name = "Aneesh";
    manager.age = 102;
    manager.phoneNumber = "9876543210";
    manager.address = "xxx yyy zzz";
    manager.salary = 5.0;
    manager.department = "Sales";

    System.out.println("Officer Details:");
    System.out.println("Name: " + officer.name);
    System.out.println("Age: " + officer.age);
    System.out.println("Phone Number: " + officer.phoneNumber);
    System.out.println("Address: " + officer.address);
    officer.printSalary();
    System.out.println("Specialization: " + officer.specialization);

    System.out.println("\nManager Details:");
    System.out.println("Name: " + manager.name);
    System.out.println("Age: " + manager.age);
    System.out.println("Phone Number: " + manager.phoneNumber);
    System.out.println("Address: " + manager.address);
    manager.printSalary();
    System.out.println("Department: " + manager.department);
  }
}
