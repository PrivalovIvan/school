package T2;

import lombok.Getter;

import java.util.concurrent.TimeUnit;

@Getter
public abstract class Animal {
    private final String name;
    private final int age;

    public Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public abstract Double goToWalk();
}

class Dog extends Animal {
    public Dog(String name, int age) {
        super(name, age);
    }

    @Override
    public String toString() {
        return "Dog name = " + getName() + ", age = " + getAge();
    }

    @Override
    public Double goToWalk() {
        double t = getAge() * 0.5;
        try {
            TimeUnit.SECONDS.sleep((long) t);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        return t;
    }
}

class Cat extends Animal {
    public Cat(String name, int age) {
        super(name, age);
    }

    @Override
    public String toString() {
        return "Cat name = " + getName() + ", age = " + getAge();
    }

    @Override
    public Double goToWalk() {
        double t = getAge() * 0.25;
        try {
            TimeUnit.SECONDS.sleep((long) t);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        return t;
    }
}