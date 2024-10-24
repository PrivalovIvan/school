package t2.exercise2;

import lombok.Data;

public abstract class Animal {
    private String name;
    private Integer age;
    private Double weight;

    public Animal(String name, Integer age, Double weight) {
        this.name = name;
        this.age = age;
        this.weight = weight;
    }

    public String getName() {
        return name;
    }

    public Integer getAge() {
        return age;
    }

    public Double getWeight() {
        return weight;
    }

    public abstract Double getFeedInfoKg();
}

class Dog extends Animal {
    public Dog(String name, Integer age, Double weight) {
        super(name, age, weight);
    }

    @Override
    public Double getFeedInfoKg() {
        return getWeight() * 0.3;
    }

    @Override
    public String toString() {
        return "Dog name = " + getName() + ", age = " + getAge() + ", mass = " + String.format("%.2f", getWeight()) + "," +
                " feed = " + String.format("%.2f", getFeedInfoKg());
    }
}

class Cat extends Animal {
    public Cat(String name, Integer age, Double weight) {
        super(name, age, weight);
    }

    @Override
    public Double getFeedInfoKg() {
        return getWeight() * 0.1;
    }

    @Override
    public String toString() {
        return "Cat name = " + getName() + ", age = " + getAge() + ", mass = " + String.format("%.2f", getWeight()) + "," +
                " feed = " + String.format("%.2f", getFeedInfoKg());
    }
}
