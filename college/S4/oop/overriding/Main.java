class Animal {
  public void sound() {
    System.out.println("Animal makes a sound");
  }
}

class Dog extends Animal {
  @Override
  public void sound() {
    System.out.println("dog barks");
  }
}

public class Main {
  public static void main(String[] args) {
    Animal a = new Animal();
    a.sound();
    Dog b = new Dog();
    b.sound();
  }
}
