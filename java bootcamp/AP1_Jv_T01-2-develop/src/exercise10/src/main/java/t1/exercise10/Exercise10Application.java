package t1.exercise10;

import lombok.Data;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.atomic.AtomicInteger;

public class Exercise10Application {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        FilterUser filterUser = new FilterUser();
        boolean valid = false;
        while (!valid) {
            try {
                filterUser.inputCountUser(scanner);
                filterUser.addUser(scanner);
                filterUser.filterUser();
                valid = true;
            } catch (InputMismatchException e) {
                System.out.println("Couldn't parse a number. Please, try again");
                scanner.nextLine();
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
        scanner.close();
    }

}

@Data
class FilterUser {
    private int countUser;
    private List<User> users = new ArrayList<>();

    void inputCountUser(Scanner scanner) throws InputMismatchException {
        countUser = scanner.nextInt();
    }

    void addUser(Scanner scanner) throws InputMismatchException {
        for (int i = 0; i < countUser; i++) {
            try {
                String name = scanner.next();
                int age = scanner.nextInt();
                if (age <= 0) {
                    countUser++;
                    throw new IllegalArgumentException("Incorrect input. Age <= 0");
                } else users.add(new User(name, age));
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    void filterUser() {
        long count = users.stream().filter(x -> x.getAge() >= 18).count();
        AtomicInteger i = new AtomicInteger(0);
        users.stream().filter(x -> x.getAge() >= 18).forEach(x -> {
            System.out.print(x.getName());
            for (; i.get() < count - 1; i.incrementAndGet()) System.out.print(", ");
        });
    }
}
