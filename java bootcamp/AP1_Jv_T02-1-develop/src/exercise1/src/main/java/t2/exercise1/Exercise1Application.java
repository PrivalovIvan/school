package t2.exercise1;

import lombok.Data;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

public class Exercise1Application {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ListPets pets = new ListPets();

        pets.inputCountAnimals(scanner);

        for (int i = 0; i < pets.getCountAnimals(); i++) {
            pets.inputTypeAnimal(scanner);
            pets.addPetsInList(scanner);
        }
        if (!pets.getPets().isEmpty()) System.out.println(pets.getPets());
        scanner.close();
    }
}

@Data
class ListPets {
    private int countAnimals;
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
            if (age <= 0) System.out.println("Incorrect input. Age <= 0");
            else {
                switch (inputTypeAnimal) {
                    case "cat":
                        pets.add(new Cat(name, age));
                        break;
                    case "dog":
                        pets.add(new Dog(name, age));
                        break;
                }
            }
        }
    }
}
