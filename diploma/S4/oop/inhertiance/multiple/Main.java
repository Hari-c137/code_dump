interface HomeLoan {

 public void loanPercentage();

}

interface CarLoan {

 public void loanPercentage();

}

interface EduLoan {

 public void loanPercentage();

}


public class Main implements HomeLoan, CarLoan, EduLoan {

  public void HLP() {
    System.out.println("FK");
  }

  public void CLP() {
    System.out.println("NGA");
  }

  public void ELP() {
    System.out.println("CHAKKA");
  }

  @Override
  public void loanPercentage() {
  }


  public static void main(String[] args) {
    Main fuk = new Main();

    fuk.HLP();
    fuk.CLP();
    fuk.ELP();
  }
}

