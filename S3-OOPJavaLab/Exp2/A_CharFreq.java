import java.io.*;
import java.util.*;

public class A_CharFreq{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String s = sc.nextLine();
        System.out.println("Enter a character: ");
        char c = sc.next().charAt(0);
        int count = 0;
        s=s.toUpperCase();
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == c){
                count++;
            }
        }
        System.out.println("Frequency of " + c + ": " + count);
    }
}