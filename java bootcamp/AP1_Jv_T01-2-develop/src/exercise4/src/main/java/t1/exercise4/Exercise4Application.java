package t1.exercise4;


import lombok.Data;

import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Exercise4Application {

    public static void main(String[] args) {
        AverageNegativeNumbers avg = new AverageNegativeNumbers();
        Scanner scanner = new Scanner(System.in);
        boolean valid = false;
        while (!valid) {
           try {
               avg.inputSizeArray(scanner);
               avg.inputArray(scanner);
               avg.checkArray();
               avg.showAverage();
                valid = true;
           } catch (NotNegativeNumbers | IllegalArgumentException e) {
               System.out.println(e.getMessage());
               scanner.nextLine();
           } catch (InputMismatchException e) {
               System.out.println("Couldn't parse a number. Please, try again");
               scanner.nextLine();
           }
        }
        scanner.close();
    }

}

@Data
class AverageNegativeNumbers {
    private int size;
    private int[] array;
    private int average;

    public void inputSizeArray(Scanner scanner) throws InputMismatchException {
        size = scanner.nextInt();
        if (size < 0) throw new IllegalArgumentException("Input error. Size <= 0");
    }

    public void inputArray(Scanner scanner) throws InputMismatchException {
        array = new int[size];
        for (int i = 0; i < size; i++) array[i] = scanner.nextInt();
    }

    public void checkArray() throws NotNegativeNumbers {
        average = (int)Arrays.stream(array).filter(x -> x < 0).average().orElse(0);
        if(average == 0) throw new NotNegativeNumbers();

    }
    public void showAverage ()  {
        System.out.println(average);
    }
}

class NotNegativeNumbers extends Exception {
    public NotNegativeNumbers() {
        super("There are no negative elements");
    }
}
