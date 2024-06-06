import java.util.*;

public class Exp9_StringToken {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a line of integers (separated by space):");
        String line = scanner.nextLine();

        StringTokenizer tokenizer = new StringTokenizer(line);

        int totalSum = 0, evenSum = 0, oddSum = 0;
        while (tokenizer.hasMoreTokens()) {
            int num = Integer.parseInt(tokenizer.nextToken());
            totalSum += num;
            if (num % 2 == 0) {
                evenSum += num;
            } else {
                oddSum += num;
            }
        }

        System.out.println("Total sum: " + totalSum);
        System.out.println("Sum of even numbers: " + evenSum);
        System.out.println("Sum of odd numbers: " + oddSum);
    }
}