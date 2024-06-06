import java.io.*;
import java.util.*;

public class C_Quotient{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter two numbers: ");
        int a = sc.nextInt();
        int b = sc.nextInt();
        int quotient = a/b;
        int remainder = a%b;
        System.out.println("Quotient: " + quotient);
        System.out.println("Remainder: " + remainder);
    }
}