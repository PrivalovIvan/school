package t1.exercise8;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Exercise8Application {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int prev = 0, current = 0;

        try {
            prev = scanner.nextInt();
        } catch (InputMismatchException e) {
            System.out.println("Input error");
            return;
        }

        while (true) {
            try {
                current = scanner.nextInt();
                if (current < prev)
                    throw new IllegalArgumentException("The sequence is not ordered from the ordinal number of the number " + current);
            } catch (InputMismatchException e) {
                System.out.println("The sequence is ordered in ascending order");
                break;
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
                break;
            }
            prev = current;
        }
        scanner.close();
    }
}
