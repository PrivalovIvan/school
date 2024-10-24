package t2.exercise4;

import java.util.List;
import java.util.Scanner;

interface EnterNumberFunction {
    int enterNumber(Scanner scanner);
}

interface TypePetFunction {
    String typePet(Scanner scanner);
}

interface AddPetsToListFunction {
    List<Animal> addPetsToList(List<Animal> pets, Integer count, Scanner scanner);
}
interface CreatePetFunction {
    Animal createPet(String type,Scanner scanner);
}
interface IncrementAgeFunction {
    List<Animal> incrementAge(List <Animal> pets);
}