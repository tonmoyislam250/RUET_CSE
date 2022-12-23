package com.tonmoy.moneyconverter;
import java.awt.Color;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.text.DecimalFormat;
import javax.swing.*;
public class myframe extends JFrame implements ActionListener{
    JTextField txf =new JTextField();
    private static final DecimalFormat df = new DecimalFormat("0.00");
    JTextField txf2 =new JTextField();
    JLabel label = new JLabel("INPUT MONEY");
    JLabel label2 = new JLabel("OUTPUT MONEY");
    String[] choice={"USD"};
    String[] choice2={"BDT"};
    JComboBox<String> combo = new JComboBox<>(choice);
    JComboBox<String> combo2 = new JComboBox<>(choice2);
    JButton b=new JButton("Convert");
    myframe(){
        setSize(420,420);
        setTitle("MoneyConverter");
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocation(650,250);
        setResizable(false);
        getContentPane().setBackground(new Color(255, 213, 128));
        txf.setBounds(30,150,100,30);
        txf2.setBounds(270,150,120,30);
        txf.setBackground(Color.cyan);
        txf2.setBackground(Color.cyan);
        label.setBounds(30,20,100,100);
        label2.setBounds(270,20,100,100);
        label.setForeground(Color.BLUE);
        label2.setForeground(Color.BLUE);
        combo.setBounds(30,90,80,30);
        combo.setBackground(Color.GREEN);
        combo2.setBackground(Color.GREEN);
        combo2.setBounds(270,90,80,30);
        b.setBounds(140, 230, 100, 30);
        b.setBackground(Color.GREEN);
        b.setForeground(Color.red);
        getContentPane().setLayout(null);
        add(txf);
        add(txf2);
        add(combo);
        add(combo2);
        add(label);
        add(b);
        add(label2);
        b.addActionListener(this);
        b.setActionCommand("button");
    }
    @Override
    public void actionPerformed(ActionEvent e){
        String s1=txf.getText();
        double a=Double.parseDouble(s1);
        if(e.getActionCommand().equals("button")){
        String s0 = (String) combo.getSelectedItem();
        String s = (String) combo2.getSelectedItem();
        switch (s) {
                case "BDT":
                    a=a*105.5085;
                    String s2=df.format(a);
                    txf2.setText(s2+" TAKA");
                    break;
                }
        }
   }
}


