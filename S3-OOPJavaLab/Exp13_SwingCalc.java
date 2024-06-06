import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Exp13_SwingCalc {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Calculator");
        JTextField textField = new JTextField();

        JButton button0 = new JButton("0");
        JButton button1 = new JButton("1");
        JButton button2 = new JButton("2");
        JButton button3 = new JButton("3");
        JButton button4 = new JButton("4");
        JButton button5 = new JButton("5");
        JButton button6 = new JButton("6");
        JButton button7 = new JButton("7");
        JButton button8 = new JButton("8");
        JButton button9 = new JButton("9");

        JButton buttonAdd = new JButton("+");
        JButton buttonSub = new JButton("-");
        JButton buttonMul = new JButton("*");
        JButton buttonDiv = new JButton("/");
        JButton buttonEq = new JButton("=");
        JButton buttonClear = new JButton("C");

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(4, 4));

        panel.add(button1);
        panel.add(button2);
        panel.add(button3);
        panel.add(buttonAdd);

        panel.add(button4);
        panel.add(button5);
        panel.add(button6);
        panel.add(buttonSub);

        panel.add(button7);
        panel.add(button8);
        panel.add(button9);
        panel.add(buttonMul);

        panel.add(buttonEq);
        panel.add(button0);
        panel.add(buttonClear);
        panel.add(buttonDiv);

        CalculatorListener listener = new CalculatorListener(textField);
        button0.addActionListener(listener);
        button1.addActionListener(listener);
        button2.addActionListener(listener);
        button3.addActionListener(listener);
        button4.addActionListener(listener);
        button5.addActionListener(listener);
        button6.addActionListener(listener);
        button7.addActionListener(listener);
        button8.addActionListener(listener);
        button9.addActionListener(listener);
        buttonAdd.addActionListener(listener);
        buttonSub.addActionListener(listener);
        buttonMul.addActionListener(listener);
        buttonDiv.addActionListener(listener);
        buttonEq.addActionListener(listener);
        buttonClear.addActionListener(listener);

        frame.setLayout(new BorderLayout());
        frame.add(textField, BorderLayout.NORTH);
        frame.add(panel, BorderLayout.CENTER);
        frame.setSize(200, 200);
        frame.setVisible(true);
    }
}

class CalculatorListener implements ActionListener {
    private JTextField textField;
    private String operator = "";
    private String operand1 = "";
    private String operand2 = "";

    CalculatorListener(JTextField textField) {
        this.textField = textField;
    }

    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();

        switch (command) {
            case "+":
            case "-":
            case "*":
            case "/":
                operator = command;
                operand1 = textField.getText();
                textField.setText("");
                break;
            case "=":
                operand2 = textField.getText();
                double result = calculate();
                textField.setText(String.valueOf(result));
                operator = "";
                break;
            case "C":
                operator = "";
                operand1 = "";
                operand2 = "";
                textField.setText("");
                break;
            default:
                textField.setText(textField.getText() + command);
                break;
        }
    }

    private double calculate() {
        double num1 = Double.parseDouble(operand1);
        double num2 = Double.parseDouble(operand2);

        switch (operator) {
            case "+":
                return num1 + num2;
            case "-":
                return num1 - num2;
            case "*":
                return num1 * num2;
            case "/":
                if (num2 != 0) {
                    return num1 / num2;
                } else {
                    System.out.println("Error! Dividing by zero is not allowed.");
                    return 0;
                }
            default:
                return 0;
        }
    }
}