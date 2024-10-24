package t1.exercise2;

import lombok.Data;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Exercise2Application {
    public static void main(String[] args) {
        Time time = new Time();
        Scanner scanner = new Scanner(System.in);
        boolean valid = false;
        while (!valid) {
            try {
                time.inputSeconds(scanner);
                time.findHourMinutesSeconds();
                time.outputTime();
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
class Time {
    private int hours, minutes, seconds;

    public void inputSeconds(Scanner scanner) throws InputMismatchException {
        seconds = scanner.nextInt();
        if (seconds < 0) throw new IllegalArgumentException("Incorrect time");
    }

    public void findHourMinutesSeconds() {
        hours = seconds / 3600;
        seconds = seconds % 3600;
        minutes = seconds / 60;
        seconds = seconds % 60;
    }

    public void outputTime() {
        System.out.printf("%02d:%02d:%02d",hours,minutes,seconds);
    }
}