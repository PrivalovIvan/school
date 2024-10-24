package t1.exercise6;


import lombok.Data;

import java.util.*;

import static java.util.Collections.swap;

public class Exercise6Application {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        scanner.useLocale(Locale.US);
        SelectionSort sort = new SelectionSort();
        boolean valid = false;

        while (!valid) {
            try {
                sort.inputSize(scanner);
                sort.inputArray(scanner);
                sort.selectionSort();
                sort.showArray();
                valid = true;
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
            } catch (InputMismatchException e) {
                System.out.println("Couldn't parse a number. Please, try again");
                scanner.nextLine();
            }
        }
        scanner.close();
    }
}

@Data
class SelectionSort {
    private int size;
    private double[] array;

    public void inputSize(Scanner scanner) throws IllegalArgumentException, InputMismatchException {
        size = scanner.nextInt();
        if (size <= 0) throw new IllegalArgumentException("Input error. Size <= 0");
    }

    public void inputArray(Scanner scanner) throws InputMismatchException {
        array = new double[size];
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextDouble();
        }
    }

    public void selectionSort() {
        for (int i = 0; i < size; i++) {
            int minIndex = i;
            for (int j = i; j < size; j++) {
                if (array[j] < array[minIndex]) minIndex = j;
            }
            if (minIndex != i) {
                double temp = array[i];
                array[i] = array[minIndex];
                array[minIndex] = temp;
            }
        }
    }

    public void showArray() {
        Arrays.stream(array).forEach(x -> System.out.print(x + " "));
    }
}
