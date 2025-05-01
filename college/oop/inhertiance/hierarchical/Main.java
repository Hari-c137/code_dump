class Shape {

  public void displayShape() {
    System.out.println("this is a shape!");
  }

}

class Rectangle extends Shape {

  protected double length = 5;
  protected double breath = 3;

  public void areaCalcuate() {
    double area = length * breath;
    System.out.println("area of rectangle: " + area);
  }

} 

class Circle extends Shape {
  protected double radius = 5;

  public void areaCalcuate() {
    double area = Math.PI * radius * radius;
    System.out.println("area of circle : " + area);
  }

}

public class Main {

  public static void main(String[] args) {
    Rectangle r = new Rectangle();
    r.displayShape();
    r.areaCalcuate();

    System.out.println();

    Circle c = new Circle();
    c.displayShape();
    c.areaCalcuate();
  }
}
