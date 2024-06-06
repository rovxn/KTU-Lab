import java.io.*;
import java.util.*;

public class E_Details{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your name: ");
        String name = sc.nextLine();
        System.out.println("Enter your age: ");
        int age = sc.nextInt();
        System.out.println("Enter your roll no: ");
        int roll = sc.nextInt();
        System.out.println("Enter your sem: ");
        int sem = sc.nextInt();
        System.out.println("Details: ");
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Roll no: " + roll);
        System.out.println("Sem: " + sem);
    }
}