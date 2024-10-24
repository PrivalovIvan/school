package T2;

import lombok.Data;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(System.in);
        MethodsForAnimal methodsForAnimal = new MethodsForAnimal();

        methodsForAnimal.getCountPets(scanner);
        methodsForAnimal.addPetsToList(scanner);

        AnimalIterator iterator = new AnimalIterator(methodsForAnimal.getPets());

        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }
    }
}

@Data
class MethodsForAnimal {
    private Integer countPets;
    private String typePet;
    private List<Animal> pets = new ArrayList<>();

    public Integer inputNumber(Scanner scanner) {
        int number;
        while (true) {
            try {
                number = scanner.nextInt();
                scanner.nextLine();
                return number;
            } catch (InputMismatchException e) {
                System.out.println("Couldn't parse a number. Please, try again");
                scanner.nextLine();
            }
        }
    }

    public void getCountPets(Scanner scanner) {
        this.countPets = inputNumber(scanner);
    }

    public void getTypePet(Scanner scanner) {
        this.typePet = scanner.nextLine();
    }

    public void addPetsToList(Scanner scanner) {
        while (countPets > 0) {
            getTypePet(scanner);
            if (!this.typePet.equals("cat") && !this.typePet.equals("dog")) {
                System.out.println("Incorrect input. Unsupported pet type");
                countPets--;
                continue;
            }
            try {
                String name = scanner.nextLine();
                int age = inputNumber(scanner);
                if (age <= 0) throw new IllegalArgumentException("Incorrect input. Age <= 0");
                pets.add(typePet.equals("cat") ? new Cat(name, age) : new Dog(name, age));
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
            }
            countPets--;
        }
    }
}