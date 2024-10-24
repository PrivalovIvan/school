package t2.exercise1;

public abstract class Animal {
    private String name;
    private Integer age;

    public Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public Integer getAge() {
        return age;
    }

    public String getName() {
        return name;
    }
}

class Dog extends Animal {
    Dog(String name, Integer age) {
        super(name, age);
    }

    @Override
    public String toString() {
        return "Dog name = " + getName() + ", age = " + getAge();
    }
}

class Cat extends Animal {
    Cat(String name, Integer age) {
        super(name, age);
    }

    @Override
    public String toString() {
        return "Cat name = " + getName() + ", age = " + getAge();
    }
}