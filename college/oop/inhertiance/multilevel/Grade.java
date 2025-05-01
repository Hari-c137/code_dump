class Student {

  protected String name;
  protected int m1, m2, m3;

  // contructor 

  public Student(String name, int m1, int m2, int m3) {
    this.name = name;
    this.m1 = m1;
    this.m2 = m2;
    this.m3 = m3;
  }
}


class Result extends Student {

  int total;
  double average;

  // constructor fro contructor

  public Result(String name, int m1, int m2, int m3) {

    super(name, m1, m2, m3);
    calculateResult();
  }

  public void calculateResult() {

    total = m1 + m2 + m3;
    average = total / 3.0;
  }
}

class Grade extends Result {

    public Grade(String name, int m1, int m2, int m3) {
      super(name, m1, m2, m3);
    }

    public void display() {
      System.out.println("name: " + name);
      System.out.println("total: " + total);
      System.out.println("average: " + average);

      if (average > 50) {
        System.out.println("passed!");
      }
      else {
        System.out.println("failed");
      }
    }

public static void main(String[] args) {
  
  Grade ga = new Grade("alice", 50, 90, 60);
  ga.display();
  System.out.println();

  Grade gb = new Grade("bob", 50, 40, 30);
  ga.display();
}


}
