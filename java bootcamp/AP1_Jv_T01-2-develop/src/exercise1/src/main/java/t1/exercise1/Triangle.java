package t1.exercise1;

import lombok.Data;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.stereotype.Component;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;


class Test {
    public static void main(String[] args) {
        AnnotationConfigApplicationContext context = new AnnotationConfigApplicationContext(MyConfig.class);
        TriangleController perimeter = context.getBean(TriangleController.class);
        Scanner scanner = new Scanner(System.in);
        boolean valid = false;
        while (!valid) {
            try {
                perimeter.requestCoordinates(scanner);
                perimeter.isTriangle();
                perimeter.getPerimeterTriangle();
                perimeter.showPerimeter();
                valid = true;
            } catch (InputMismatchException e) {
                System.out.println("Couldn't parse a number. Please, try again");
                scanner.next();
            } catch (ArithmeticException e) {
                System.out.println(e.getMessage());
            }
        }
        scanner.close();
        context.close();
    }
}


@Data
@Component
public class Triangle {
    private List<Double> coordinates = new ArrayList<>();
    private double perimeter;

    public void requestCoordinates(Scanner scanner) throws InputMismatchException {
        coordinates.clear();
        for (int i = 0; i < 6; i++) coordinates.add(scanner.nextDouble());
    }

    public void isTriangle() {
        double x1 = coordinates.get(0), y1 = coordinates.get(1);
        double x2 = coordinates.get(2), y2 = coordinates.get(3);
        double x3 = coordinates.get(4), y3 = coordinates.get(5);

        double area = Math.abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
        if (area == 0) {
            throw new ArithmeticException("It isn't triangle");
        }
    }

    public void getPerimeterTriangle() {
        perimeter = 0;
        for (int i = 0; i < 4; i += 2)
            perimeter += Math.sqrt(Math.pow(coordinates.get(i + 2) - coordinates.get(i), 2) + Math.pow(coordinates.get(i + 3) - coordinates.get(i + 1), 2));

        perimeter += Math.sqrt(Math.pow(coordinates.get(4) - coordinates.get(0), 2) + Math.pow(coordinates.get(5) - coordinates.get(1), 2));
    }

}

@Component
class TriangleView {
    public void showPerimeter(Triangle triangle) {
        System.out.printf("%.3f", triangle.getPerimeter());
    }
}

@Component
class TriangleController {
    Triangle model;
    TriangleView view;

    @Autowired
    public TriangleController(Triangle model, TriangleView view) {
        this.model = model;
        this.view = view;
    }

    public void requestCoordinates(Scanner scanner) throws InputMismatchException {
        model.requestCoordinates(scanner);
    }

    public void isTriangle() {
        model.isTriangle();
    }

    public void getPerimeterTriangle() {
        model.getPerimeterTriangle();
    }

    public void showPerimeter() {
        view.showPerimeter(model);
    }
}

@Configuration
@ComponentScan("t1.exercise1")
class MyConfig {
}