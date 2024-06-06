import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class TrafficLight extends JPanel implements ActionListener {
    static JRadioButton r1,r2,r3;
    static Color red1,green1,orange1;

    public TrafficLight() {
        setBounds(0,0,600,480);
        r1=new JRadioButton("RED");
        r2=new JRadioButton("GREEN");
        r3=new JRadioButton("ORANGE");

        ButtonGroup group=new ButtonGroup();
        r1.setSelected(true);
        group.add(r1);
        group.add(r2);
        group.add(r3);

        add(r1);
        add(r2);
        add(r3);

        red1=Color.red;
        green1=getBackground();
        orange1=getBackground();

        r1.addActionListener(this);
        r2.addActionListener(this);
        r3.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        if(r1.isSelected()==true) {
            red1=Color.red;
            green1=getBackground();
            orange1=getBackground();
        } else if(r2.isSelected()==true) {
            red1=getBackground();
            green1=Color.green;
            orange1=getBackground();
        } else if(r3.isSelected()==true) {
            red1=getBackground();
            green1=getBackground();
            orange1=Color.orange;
        }
        repaint();
    }

    public void paintComponent(Graphics g) {
        g.drawOval(50,50,50,50);
        g.drawOval(50,110,50,50);
        g.drawOval(50,170,50,50);

        g.setColor(red1);
        g.fillOval(50,50,50,50);
        g.setColor(green1);
        g.fillOval(50,110,50,50);
        g.setColor(orange1);
        g.fillOval(50,170,50,50);
    }
}

class TrafficDemo {
    public static void main(String args[]) {
        JFrame f1=new JFrame();
        f1.setVisible(true);
        f1.setSize(500,500);
        f1.setLayout(null);
        TrafficLight t=new TrafficLight(); // Corrected here
        f1.add(t);
    }
}