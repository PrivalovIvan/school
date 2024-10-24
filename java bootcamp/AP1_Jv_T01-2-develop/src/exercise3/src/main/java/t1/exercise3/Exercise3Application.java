package t1.exercise3;

import lombok.Data;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Exercise3Application {
    public static void main(String[] args) {
        Fibonacci fibonacci = new Fibonacci();
        Scanner scanner = new Scanner(System.in);
        boolean valid = false;
        while (!valid) {
            try {
                fibonacci.inputNumber(scanner);
                fibonacci.findFibonacci();
                fibonacci.showFibonacci();
                valid = true;
            } catch (InputMismatchException e) {
                System.out.println("Couldn't parse a number. Please, try again");
                scanner.next();
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
            }
        }
        scanner.close();
    }
}

@Data
class Fibonacci {
    private long number;
    private long fibonacciResult;

    public void inputNumber(Scanner scanner) throws InputMismatchException {
        number = scanner.nextLong();
        if (number > 92) throw new IllegalArgumentException("Too large n");
    }

    public void findFibonacci() {
        fibonacciResult = fibonacci(number);
    }

    public long fibonacci(long n) {
        if (n <= 1) return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    public void showFibonacci() {
        System.out.println(fibonacciResult);
    }
}
