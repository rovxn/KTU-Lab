import java.io.*;
import java.util.*;

public class A_Multiply {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.println("Enter the number of rows and columns of first matrix");
    int rows1 = sc.nextInt();
    int columns1 = sc.nextInt();

    int[][] firstMatrix = new int[rows1][columns1];

    System.out.println("Enter elements of first matrix");

    for (int i = 0; i < rows1; i++)
        for (int j = 0; j < columns1; j++)
        firstMatrix[i][j] = sc.nextInt();

    System.out.println("Enter the number of rows and columns of second matrix");
    int rows2 = sc.nextInt();
    int columns2 = sc.nextInt();

    if (columns1 != rows2) {
        System.out.println("The matrices can't be multiplied with each other.");
        return;
    }

    int[][] secondMatrix = new int[rows2][columns2];

    System.out.println("Enter elements of second matrix");

    for (int i = 0; i < rows2; i++)
        for (int j = 0; j < columns2; j++)
        secondMatrix[i][j] = sc.nextInt();

    int[][] result = new int[rows1][columns2];

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
        for (int k = 0; k < columns1; k++) {
            result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
        }
        }
    }

    System.out.println("Product of entered matrices:-");

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++)
        System.out.print(result[i][j] + " ");
        System.out.println();
    }
    }
}