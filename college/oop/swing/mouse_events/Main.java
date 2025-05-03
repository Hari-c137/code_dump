import javax.swing.*;
import java.awt.event.*;

public class Main extends JFrame implements MouseListener {
  JLabel label;

  public Main() {
    label = new JLabel("interact with things");
    label.setBounds(50,50,300,30);

    add(label);
    addMouseListener(this);
    setSize(300,400);
    setVisible(true);
    setLayout(null);
    setTitle("demo");
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  }

  public void mouseClicked(MouseEvent e) {
    label.setText("Mouse clicked at (" + e.getX() + "," + e.getY() + ")");
  }
  public void mousePressed(MouseEvent e) {
    label.setText("Mouse pressed");
  }
  public void mouseEntered(MouseEvent e) {
    label.setText("Mouse entered");
  }
  public void mouseReleased(MouseEvent e) {
    label.setText("Mouse released");
  }
  public void mouseExited(MouseEvent e) {
    label.setText("Mouse exited");
  }

  public static void main(String[] args) {
    new Main();
  }
}
