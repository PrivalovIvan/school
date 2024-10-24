package t2.exercise2;

import lombok.Data;

import java.util.*;

public class Exercise2Application {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(System.in);
        AmountFood pets = new AmountFood();

        pets.inputCountAnimals(scanner);

        for (int i = 0; i < pets.getCountAnimals(); i++) {
            pets.inputTypeAnimal(scanner);
            pets.addPetsInList(scanner);
        }
        if (!pets.getPets().isEmpty()) pets.getPets().forEach(x -> System.out.print(x + "\n"));
        scanner.close();
    }

}

@Data
class AmountFood {
    private Integer countAnimals;
    private List<Animal> pets = new ArrayList<>();
    private String inputTypeAnimal;

    public void inputCountAnimals(Scanner scanner) {
        boolean valid = false;
        while (!valid) {
            try {
                countAnimals = scanner.nextInt();
                scanner.nextLine();
                valid = true;
            } catch (InputMismatchException e) {
                System.out.println("Couldn't parse a number. Please, try again");
                scanner.nextLine();
            }
        }
    }

    public void inputTypeAnimal(Scanner scanner) {
        inputTypeAnimal = scanner.nextLine();
        if (!inputTypeAnimal.equals("cat") && !inputTypeAnimal.equals("dog")) {
            System.out.println("Incorrect input. Unsupported pet type");
        }
    }

    public void addPetsInList(Scanner scanner) {
        if (inputTypeAnimal.equals("cat") || inputTypeAnimal.equals("dog")) {
            String name = scanner.nextLine();
            boolean valid = false;
            int age = 0;
            while (!valid) {
                try {
                    age = scanner.nextInt();
                    scanner.nextLine();
                    valid = true;
                } catch (InputMismatchException e) {
                    System.out.println("Couldn't parse a number. Please, try again");
                    scanner.nextLine();
                }
            }
            if (age <= 0) {
                System.out.println("Incorrect input. Age <= 0");
                return;
            }
            double weight = scanner.nextDouble();
            scanner.nextLine();
            if (weight <= 0) {
                System.out.println("Incorrect input. Mass <= 0");
                return;
            }
            switch (inputTypeAnimal) {
                case "cat":
                    pets.add(new Cat(name, age, weight));
                    break;
                case "dog":
                    pets.add(new Dog(name, age, weight));
                    break;
            }
        }
    }
}