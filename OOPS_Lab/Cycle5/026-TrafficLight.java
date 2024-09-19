import javax.swing.*;
import java.awt.*;

class TrafficLight extends JFrame {
    private JRadioButton redBtn, greenBtn, yellowBtn;
    private JPanel lightPanel, btnPanel;

    public TrafficLight() {
        // Frame Configs
        super("Adi's Traffic");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(300, 400);
        setResizable(false);
        setLayout(new BorderLayout());

        // Creating the buttons
        redBtn = new JRadioButton("Red");
        greenBtn = new JRadioButton("Green");
        yellowBtn = new JRadioButton("Yellow");

        // Make the traffic light to repaint on btn clicks
        redBtn.addActionListener(e -> lightPanel.repaint());
        greenBtn.addActionListener(e -> lightPanel.repaint());
        yellowBtn.addActionListener(e -> lightPanel.repaint());

        // Adding button to a group so that only one can be selected at a time
        ButtonGroup group = new ButtonGroup();
        group.add(redBtn);
        group.add(greenBtn);
        group.add(yellowBtn);

        // Creating a panel for buttons
        btnPanel = new JPanel(new GridLayout(1, 3));
        btnPanel.add(redBtn);
        btnPanel.add(greenBtn);
        btnPanel.add(yellowBtn);

        // Createing a panel for light
        lightPanel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                g.setColor(Color.BLACK);
                g.fillRect(100, 50, 100, 200);

                g.setColor(redBtn.isSelected() ? Color.RED : Color.DARK_GRAY);
                g.fillOval(125, 65, 50, 50);

                g.setColor(greenBtn.isSelected() ? Color.GREEN : Color.DARK_GRAY);
                g.fillOval(125, 125, 50, 50);

                g.setColor(yellowBtn.isSelected() ? Color.YELLOW : Color.DARK_GRAY);
                g.fillOval(125, 185, 50, 50);
            }
        };

        // Add btnPanel and lightPanel to the frame
        add(btnPanel, BorderLayout.NORTH);
        add(lightPanel, BorderLayout.CENTER);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            TrafficLight frame = new TrafficLight();
            frame.setVisible(true);
        });
    }
}