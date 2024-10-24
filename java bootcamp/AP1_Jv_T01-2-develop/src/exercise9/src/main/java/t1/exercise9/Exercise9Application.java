package t1.exercise9;

import lombok.Data;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

public class Exercise9Application {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        FilterString filterString = new FilterString();
        filterString.inputCounterString(scanner);
        filterString.inputString(scanner);
        filterString.inputSubString(scanner);
        filterString.findSubString();

        System.out.println(filterString.getResult());
        scanner.close();
    }
}

@Data
class FilterString {
    private int countStr;
    private List<String> list = new ArrayList<>();
    private String subString = null;
    private List<String> result = new ArrayList<>();


    void inputCounterString(Scanner scanner) throws InputMismatchException {
        setCountStr(scanner.nextInt());
        scanner.nextLine();
    }

    void inputString(Scanner scanner) {
        for (int i = 0; i < countStr; i++)
            list.add(scanner.nextLine());
    }

    void inputSubString(Scanner scanner) {
        setSubString(scanner.nextLine());
    }

    void findSubString() {
        int counter = 0;
        for (int i = 0; i < list.size(); i++) {
            String temp = list.get(i);
            for (int j = 0; j < temp.length(); j++) {
                for (int k = 0; k < subString.length(); k++) {
                    if (temp.charAt(j) == subString.charAt(k)) {
                        counter++;
                        j++;
                    } else counter = 0;

                    if (counter == subString.length()) {
                        result.add(temp);
                        counter = 0;
                        break;
                    }
                }
            }
        }
    }
}
