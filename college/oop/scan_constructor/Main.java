import java.util.Scanner;

class Person {
  String name;
  int age;

  // constructor
  public Person(String name, int age) {
    this.name = name;
    this.age = age;
  }

  public void display() {
    System.out.println("name: " + name);
    System.out.println("age: " + age);

  }
}

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.println("enter your name: ");
    String nInput = scanner.nextLine();

    System.out.println("enter your age: ");
    int aInput = scanner.nextInt();

    Person person = new Person(nInput, aInput);
    person.display();
  }
}
