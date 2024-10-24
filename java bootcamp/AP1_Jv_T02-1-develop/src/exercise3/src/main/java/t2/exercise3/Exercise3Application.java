package t2.exercise3;

import lombok.Data;

import java.util.*;

public class Exercise3Application {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(System.in);
        ListAnimals pets = new ListAnimals();

        pets.inputCountAnimals(scanner);

        for (int i = 0; i < pets.getCountAnimals(); i++) {
            pets.inputTypeAnimal(scanner);
            pets.addPetsInList(scanner);
        }
        if (!pets.getPets().isEmpty()) pets.getPets().forEach(x -> {
            if (x instanceof Herbivore) System.out.print(x + "\n");
        });
        if (!pets.getPets().isEmpty()) pets.getPets().forEach(x -> {
            if (x instanceof Omnivore) System.out.print(x + "\n");
        });
        scanner.close();
    }

}

@Data
class ListAnimals {
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
        if (!inputTypeAnimal.equals("cat") && !inputTypeAnimal.equals("dog") && !inputTypeAnimal.equals("hamster")
                && !inputTypeAnimal.equals("guinea")) {
            System.out.println("Incorrect input. Unsupported pet type");
        }
    }

    public void addPetsInList(Scanner scanner) {
        if (inputTypeAnimal.equals("cat") || inputTypeAnimal.equals("dog") || inputTypeAnimal.equals("hamster")
                || inputTypeAnimal.equals("guinea")) {
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
            switch (inputTypeAnimal) {
                case "cat":
                    pets.add(new Cat(name, age));
                    break;
                case "dog":
                    pets.add(new Dog(name, age));
                    break;
                case "hamster":
                    pets.add(new Hamster(name, age));
                    break;
                case "guinea":
                    pets.add(new GuineaPig(name, age));
            }
        }
    }
}