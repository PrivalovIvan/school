package t1.exercise5;

import lombok.Data;

import java.util.*;

public class Exercise5Application {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        MatchingFirstLastDigitFinder finder = new MatchingFirstLastDigitFinder();
        boolean valid = false;

        while (!valid) {
            try {
                finder.inputSize(scanner);
                finder.inputArrayInput(scanner);
                finder.findMatching();
                finder.showResult();
                valid = true;
            } catch (InputMismatchException e) {
                System.out.println("Couldn't parse a number. Please, try again");
                scanner.nextLine();
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
            }
        }
        scanner.close();
    }
}

@Data
class MatchingFirstLastDigitFinder {
    private int size;
    private int[] arrayInput;
    private int[] arrayOutput;

    public void inputSize(Scanner scanner) throws InputMismatchException {
        size = scanner.nextInt();
        if (size <= 0) throw new IllegalArgumentException("Input error. Size <= 0");
    }

    public void inputArrayInput(Scanner scanner) throws InputMismatchException {
        arrayInput = new int[size];
        for (int i = 0; i < arrayInput.length; i++) arrayInput[i] = scanner.nextInt();
    }

    public void findMatching() throws IllegalArgumentException {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            String value = String.valueOf(arrayInput[i]);
            char start = value.charAt(0), end = value.charAt(value.length() - 1);
            if (start == end) list.add(arrayInput[i]);
        }
        if (list.isEmpty()) throw new IllegalArgumentException("There are no such elements");
        arrayOutput = new int[list.size()];
        for (int i = 0; i < arrayOutput.length; i++) arrayOutput[i] = list.get(i);
    }

    public void showResult() {
        Arrays.stream(arrayOutput).forEach(x -> System.out.print(x + " "));
    }
}