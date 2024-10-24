package t1.exercise7;

import lombok.Data;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class Exercise7Application {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        MinMaxFinder finder = new MinMaxFinder();
        boolean valid = false;
        //src/main/resources/file1.txt
        while (!valid) {
            try {
                finder.inputPath(scanner);
                finder.addedListLines();
                finder.addedListNumbers();
                finder.outputTerminal();
                finder.writeResultInFile();
                valid = true;
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
            } catch (IOException e) {
                System.out.println("Input error. File isn't exist");
            }
        }
        scanner.close();
    }
}

@Data
class MinMaxFinder {
    private String path;
    private int countNumbers;
    private List<String> lines;
    private List<Double> numbers = new ArrayList<>();

    void inputPath(Scanner scanner) {
        this.path = scanner.nextLine();
    }

    void addedListLines() throws IOException {
        lines = Files.readAllLines(Paths.get(path));
    }

    void addedListNumbers() throws IllegalArgumentException {
        this.countNumbers = Integer.parseInt(lines.get(0));
        if (countNumbers <= 0) throw new IllegalArgumentException("Input error. Size <= 0");

        String[] split = lines.get(1).split("\\s+");
        if (split.length < countNumbers)
            throw new IllegalArgumentException("Input error. Insufficient number of elements");

        int temp = 0;
        for (int i = 0; i < countNumbers + temp; i++) {
            try {
                numbers.add(Double.parseDouble(split[i]));
            } catch (NumberFormatException ignored) {
                temp++;
            }
        }
    }

    Double findMin() {
        return numbers.stream().min(Double::compareTo).get();
    }

    Double findMax() {
        return numbers.stream().max(Double::compareTo).get();
    }

    void outputTerminal() {
        System.out.println(countNumbers);
        numbers.forEach(x -> System.out.print(x + " "));
        System.out.println("\nSaving min and max values in file");
    }

    void writeResultInFile() throws IOException {
        List<String> results = new ArrayList<>();
        results.add(findMin().toString() + " " + findMax().toString());
        Files.write(Paths.get("result.txt"), results);
    }
}


