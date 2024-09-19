import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class CalculatorSwing extends JFrame implements ActionListener {
  private JTextField display;
  private JButton[] buttons;
  private double result = 0.0;
  private char operator = ' ';
  private String currentNumber = "";
  private static String[] labels = {
      "7", "8", "9", "+", "4", "5", "6", "-", "1", "2", "3", "*", ".", "0", "%", "/", "C", "="
  };

  public CalculatorSwing() {
    super("Adi's Calculator");
    setLayout(new BorderLayout());

    // Display
    display = new JTextField(20);
    display.setEditable(false);
    display.setPreferredSize(new Dimension(0, 50));
    add(display, BorderLayout.NORTH);

    // Buttons
    buttons = new JButton[labels.length];
    JPanel buttonsPanel = new JPanel(new GridLayout(5, 4));
    for (int i = 0; i < labels.length; i++) {
      buttons[i] = new JButton(labels[i]);
      buttons[i].addActionListener(this);
      buttonsPanel.add(buttons[i]);
    }
    add(buttonsPanel, BorderLayout.CENTER);
  }

  public static void main(String[] args) {
    CalculatorSwing calculator = new CalculatorSwing();
    calculator.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    calculator.setSize(300, 350);
    calculator.setVisible(true);
  }

  @Override
  public void actionPerformed(ActionEvent e) {
    String label = e.getActionCommand();
    try {
      switch (label) {
        case "C" -> clear();
        case "." -> handleDotPress();
        case "+", "-", "*", "/", "%" -> handleOperatorPress(label.charAt(0));
        case "=" -> handleEqualPress();
        default -> handleNumberPress(label);
      }
      System.out.println("Clicked: " + label);
      System.out.println("Operator: " + operator);
      System.out.println("Result: " + result);
      System.out.println("CurrentNumber: " + currentNumber);
    } catch (Exception exception) {
      display.setText("Error");
    }
  }

  private void clear() {
    this.result = 0.0;
    this.operator = ' ';
    this.currentNumber = "";
    this.display.setText("");
  }

  private void handleDotPress() {
    if (!this.currentNumber.isEmpty()) {
      this.currentNumber += ".";
    }
    this.display.setText(this.currentNumber);
  }

  private void handleOperatorPress(char operator) {
    if (!this.currentNumber.isEmpty()) {
      this.result = Double.parseDouble(this.currentNumber);
      this.operator = operator;
      this.currentNumber = "";
    }
  }

  private void handleEqualPress() {
    if (!this.currentNumber.isEmpty()) {
      double number = Double.parseDouble(this.currentNumber);
      switch (this.operator) {
        case '+' -> this.result += number;
        case '-' -> this.result -= number;
        case '*' -> this.result *= number;
        case '%' -> this.result %= number;
        case '/' -> this.result /= number;
      }

      this.currentNumber = Double.toString(this.result);
      this.display.setText(this.currentNumber);
    }
  }

  private void handleNumberPress(String number) {
    this.currentNumber += number;
    this.display.setText(this.currentNumber);
  }
}
