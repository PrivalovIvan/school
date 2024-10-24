package t2.exercise4;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

public class Exercise4Application {
    CreatePetFunction createPet;
    TypePetFunction typePet;
    AddPetsToListFunction addPets;
    EnterNumberFunction enterNumber;
    IncrementAgeFunction incrementAge;

    public Exercise4Application() {
        this.enterNumber = scanner -> {
            try {
                int number = scanner.nextInt();
                scanner.nextLine();
                return number;
            } catch (InputMismatchException e) {
                System.out.println("Couldn't parse a number. Please, try again");
                scanner.nextLine();
                return enterNumber(scanner);
            }
        };

        this.createPet = (type, scanner) -> {
            String name;
            int age;
            try {
                switch (type) {
                    case "dog":
                        name = scanner.nextLine();
                        age = enterNumber(scanner);
                        if (age <= 0) throw new IllegalArgumentException("Incorrect input. Age <= 0");
                        return new Dog(name, age);
                    case "cat":
                        name = scanner.nextLine();
                        age = enterNumber(scanner);
                        if (age <= 0) throw new IllegalArgumentException("Incorrect input. Age <= 0");
                        return new Cat(name, age);
                    default:
                        System.out.println("Incorrect input. Unsupported pet type");
                }
            } catch (InputMismatchException e) {
                System.out.println("Couldn't parse a number. Please, try again");
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
            }
            return null;
        };

        this.typePet = scanner -> {
            String type = scanner.nextLine();
            if (!type.equalsIgnoreCase("dog") && !type.equalsIgnoreCase("cat")) {
                return null;
            }
            return type;
        };

        this.addPets = (list, count, scanner) -> {
            if (count == 0) return list;
            String type = typePet.typePet(scanner);
            if (type == null) {
                System.out.println("Incorrect input. Unsupported pet type");
                return addPetsToList(list, count - 1, scanner);
            }
            Animal pet = createPet.createPet(type, scanner);
            List<Animal> pets = new ArrayList<>(list);
            if (pet != null) pets.add(pet);
            return addPetsToList(pets, count - 1, scanner);
        };

        this.incrementAge = list -> {
            return list.stream().peek(x -> {
                if (x.getAge() > 10) x.setAge(x.getAge() + 1);
            }).toList();
        };
    }

    public List<Animal> addPetsToList(List<Animal> list, Integer count, Scanner scanner) {
        return addPets.addPetsToList(list, count, scanner);
    }

    public Integer enterNumber(Scanner scanner) {
        return enterNumber.enterNumber(scanner);
    }

    public List<Animal> incrementAge(List<Animal> list) {
        return incrementAge.incrementAge(list);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Exercise4Application main = new Exercise4Application();
        Integer countPets = main.enterNumber(scanner);
        List<Animal> pets = new ArrayList<>();
        pets = main.addPetsToList(pets, countPets, scanner);
        pets = main.incrementAge(pets);

        pets.forEach(System.out::println);

        scanner.close();
    }
}