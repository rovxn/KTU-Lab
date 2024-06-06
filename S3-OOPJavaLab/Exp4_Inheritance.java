import java.util.Scanner;

class Employee {
    String name;
    int age;
    String phoneNumber;
    String address;
    int salary;

    public void printSalary() {
        System.out.println(salary);
    }
}

class Officer extends Employee {
    String specialization;
}

class Manager extends Employee {
    String department;
}

public class Exp4_Inheritance {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Officer officer = new Officer();
        System.out.println("Enter Officer's Details:");
        System.out.print("Name: ");
        officer.name = scanner.nextLine();
        System.out.print("Age: ");
        officer.age = scanner.nextInt();
        scanner.nextLine(); // consume newline left-over
        System.out.print("Phone Number: ");
        officer.phoneNumber = scanner.nextLine();
        System.out.print("Address: ");
        officer.address = scanner.nextLine();
        System.out.print("Salary: ");
        officer.salary = scanner.nextInt();
        scanner.nextLine(); // consume newline left-over
        System.out.print("Specialization: ");
        officer.specialization = scanner.nextLine();

        Manager manager = new Manager();
        System.out.println("\nEnter Manager's Details:");
        System.out.print("Name: ");
        manager.name = scanner.nextLine();
        System.out.print("Age: ");
        manager.age = scanner.nextInt();
        scanner.nextLine(); // consume newline left-over
        System.out.print("Phone Number: ");
        manager.phoneNumber = scanner.nextLine();
        System.out.print("Address: ");
        manager.address = scanner.nextLine();
        System.out.print("Salary: ");
        manager.salary = scanner.nextInt();
        scanner.nextLine(); // consume newline left-over
        System.out.print("Department: ");
        manager.department = scanner.nextLine();

        System.out.println("\nOfficer Details:");
        System.out.println("Name: " + officer.name);
        System.out.println("Age: " + officer.age);
        System.out.println("Phone Number: " + officer.phoneNumber);
        System.out.println("Address: " + officer.address);
        System.out.println("Salary: ");
        officer.printSalary();
        System.out.println("Specialization: " + officer.specialization);

        System.out.println("\nManager Details:");
        System.out.println("Name: " + manager.name);
        System.out.println("Age: " + manager.age);
        System.out.println("Phone Number: " + manager.phoneNumber);
        System.out.println("Address: " + manager.address);
        System.out.println("Salary: ");
        manager.printSalary();
        System.out.println("Department: " + manager.department);
    }
}