class accessTable {

  int defaultVar = 0;
  public int publicVar = 1;
  private int privateVar = 2;
  protected int protectedVar = 3;

  public void internalshow() {

    System.out.println("Defualt: " + defaultVar);
    System.out.println("Public: " + publicVar);
    System.out.println("Private: " + privateVar);
    System.out.println("Protected: " + protectedVar);
  }

}

public class Main {
  public static void main(String[] args) {
    
    accessTable exec = new accessTable();
    // access through through 
    System.out.println("calling from through");

    System.out.println("Defualt:" + exec.defaultVar);
    System.out.println("Public:" + exec.publicVar);
 // System.out.println("Private:" + exec.privateVar);
    System.out.println("Protected: " + exec.protectedVar);

    // using the internalshow() on the inside
    
    exec.internalshow();


  }
}
