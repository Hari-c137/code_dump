class calcuArea {

  public void area(double length, double breath) {
    double area = length * breath;
    System.out.println("rectangle area: " + area);
  }

  public void area(double radius) {
    double area = Math.PI * radius * radius;
    System.out.println("circle area: " + area);

  }
}

public class Main {
  public static void main(String[] args) {
    calcuArea arc = new calcuArea();

    arc.area(5);
    arc.area(5,3);
  }
}
