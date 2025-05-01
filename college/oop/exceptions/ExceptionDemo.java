public class ExceptionDemo {
  public static void main(String[] args) {
    
    try {

      int a = 10;
      int b =  0;
      int c = a / b;
      
    } catch (ArithmeticException e) {
      System.out.println("error is: " + e.getMessage());
    }
      System.out.println();
    try {
      int number[] = {1, 2, 3};
      System.out.println("printing: " +  number[3]);
      
    } catch (ArrayIndexOutOfBoundsException e) {
      System.out.println("error: " + e.getMessage() );
    }
  }
}
