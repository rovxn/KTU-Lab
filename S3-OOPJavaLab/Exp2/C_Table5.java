import java.io.*;
import java.util.*;

public class C_Table5{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number: ");
        int n = sc.nextInt();
        for(int i=1; i<=n; i++){
            System.out.println(5 + " * " + i + " = " + (5*i));
        }
    }
}