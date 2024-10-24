package t2.exercise3;

public abstract class Animal {
    private String name;
    private Integer age;

    public Animal(String name, Integer age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public Integer getAge() {
        return age;
    }
}

class Dog extends Animal implements Omnivore {
    public Dog(String name, Integer age) {
        super(name, age);
    }

    @Override
    public String hunt() {
        return "I can hunt for robbers";
    }

    @Override
    public String toString() {
        return "Dog name = " + getName() + ", age = " + getAge() + ". " + hunt();
    }
}

class Cat extends Animal implements Omnivore {
    public Cat(String name, Integer age) {
        super(name, age);
    }

    @Override
    public String hunt() {
        return "I can hunt for mice";
    }

    @Override
    public String toString() {
        return "Cat name = " + getName() + ", age = " + getAge() + ". " + hunt();
    }
}

class Hamster extends Animal implements Herbivore {
    public Hamster(String name, Integer age) {
        super(name, age);
    }

    @Override
    public String chill() {
        return "I can chill for 8 hours";
    }

    @Override
    public String toString() {
        return "Hamster name = " + getName() + ", age = " + getAge() + ". " + chill();
    }
}

class GuineaPig extends Animal implements Herbivore {
    public GuineaPig(String name, Integer age) {
        super(name, age);
    }

    @Override
    public String chill() {
        return "I can chill for 12 hours";
    }

    @Override
    public String toString() {
        return "GuineaPig name = " + getName() + ", age = " + getAge() + ". " + chill();
    }
}