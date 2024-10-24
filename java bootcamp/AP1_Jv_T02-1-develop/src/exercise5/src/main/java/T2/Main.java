package T2;

import lombok.Data;

import java.time.Duration;
import java.time.Instant;
import java.util.*;
import java.util.concurrent.*;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(System.in);
        TrackingPetWalks trackingPetWalks = new TrackingPetWalks();

        trackingPetWalks.getCountPets(scanner);
        trackingPetWalks.addPetsToList(scanner);

        Instant startTimeProgram = Instant.now();
//        ExecutorService executorService = Executors.newFixedThreadPool(trackingPetWalks.getPets().size());
        ExecutorService executorService = Executors.newCachedThreadPool();
        CountDownLatch countDownLatch = new CountDownLatch(trackingPetWalks.getPets().size());
        for (Animal pet : trackingPetWalks.getPets()) {
            executorService.submit(() -> {
                try {
                    Instant walkStart = Instant.now();
                    Duration durationStart = Duration.between(startTimeProgram, walkStart);
                    pet.goToWalk();
                    Instant walkEnd = Instant.now();
                    Duration durationEnd = Duration.between(startTimeProgram, walkEnd);
                    System.out.println(pet +
                            ", start time = " + String.format("%.2f", durationStart.toMillis() / 1000.0) +
                            ", end time = " + String.format("%.2f", durationEnd.toMillis() / 1000.0));

                } finally {
                    countDownLatch.countDown();
                }
            });
        }
        countDownLatch.await();
        executorService.shutdown();
    }
}

@Data
class TrackingPetWalks {
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