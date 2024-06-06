import java.util.*;

public class B_Addition {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number of rows and columns of the matrices");
        int rows = sc.nextInt();
        int columns = sc.nextInt();

        int[][] firstMatrix = new int[rows][columns];
        int[][] secondMatrix = new int[rows][columns];

        System.out.println("Enter elements of first matrix");

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                firstMatrix[i][j] = sc.nextInt();

        System.out.println("Enter elements of second matrix");

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                secondMatrix[i][j] = sc.nextInt();

        int[][] result = new int[rows][columns];

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                result[i][j] = firstMatrix[i][j] + secondMatrix[i][j];

        System.out.println("Sum of entered matrices:-");

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++)
                System.out.print(result[i][j] + " ");
            System.out.println();
        }
    }
}