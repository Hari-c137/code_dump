class Rectangle {

  protected double length;
  protected double breath;

  // contructor
  public Rectangle(double length, double breath) {

    this.length = length;
    this.breath = breath;

  }
}

public class SingleInheritance extends Rectangle {

  // contructor for contructor
  public SingleInheritance(double length, double breath) {
    super(length,breath);
  }
  // load && dont class it MF
  public double calcu() {
    return length * breath;
  }

  public static void main(String[] args) {
    SingleInheritance obj = new SingleInheritance(5.0, 3.0);
    System.out.println("rectangle area is :" + obj.calcu());
  }
}
