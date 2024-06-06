import java.io.*;
import java.util.*;

public class B_ASCII{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a character: ");
        char c = sc.next().charAt(0);
        int ascii = c;
        System.out.println("ASCII value: " + ascii);
    }
}