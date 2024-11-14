import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Main extends JFrame implements ActionListener {
  private JTextField display;
  private double result = 0.0;
  private char operator = ' ';
  private String currentNumber = "";

  public Main() {
    super("Adi's Calculator");

    display = new JTextField(20);
    display.setEditable(false);
    display.setPreferredSize(new Dimension(0, 50));
    add(display, BorderLayout.NORTH);

    String labels[] = {"7", "8", "9", "+", "4", "5", "6", "-", "1", "2", "3", "*", ".", "0", "%", "/", "C", "="};
    JPanel buttonsPanel = new JPanel(new GridLayout(5, 4));
    JButton[] buttons = new JButton[labels.length];

    for (int i = 0; i < labels.length; i++) {
      buttons[i] = new JButton(labels[i]);
      buttons[i].addActionListener(this);
      buttonsPanel.add(buttons[i]);
    }
    add(buttonsPanel, BorderLayout.CENTER);
  }

  public static void main(String[] args) {
    Main calc = new Main();
    calc.setDefaultCloseOperation(EXIT_ON_CLOSE);
    calc.setSize(300, 350);
    calc.setVisible(true);
  }

  @Override
  public void actionPerformed(ActionEvent e) {
    String label = e.getActionCommand();
    switch (label) {
      case "C" -> clear();
      case "." -> handleDotPress();
      case "+", "-", "*", "/", "%" -> handleOperatorPress(label.charAt(0));
      case "=" -> handleEqualsPress();
      default -> handleNumberPress(label);
    }
  }

  private void clear() {
    display.setText("");
    result = 0.0;
    operator = ' ';
    currentNumber = "";
  }

  private void handleDotPress() {
    if (!currentNumber.isEmpty()) currentNumber += ".";
    display.setText(currentNumber);
  }

  private void handleOperatorPress(char opr) {
    if (currentNumber.isEmpty()) return;
    if (operator != ' ') handleEqualsPress();
    result = Double.parseDouble(currentNumber);
    operator = opr;
    currentNumber = "";
  }

  private void handleNumberPress(String num) {
    currentNumber += num;
    display.setText(currentNumber);
  }

  private void handleEqualsPress() {
    if (currentNumber.isEmpty()) return;

    double number = Double.parseDouble(currentNumber);  

    switch (operator) {
      case '+' -> result += number;
      case '-' -> result -= number;
      case '*' -> result *= number;
      case '/' -> result /= number;
      case '%' -> result %= number;
    }

    currentNumber = Double.toString(result);
    operator = ' ';
    result = 0.0;
    display.setText(currentNumber);
  } 
}
