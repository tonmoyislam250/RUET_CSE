package src;

import java.io.IOException;
import java.util.*;
import java.awt.Color;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.text.DecimalFormat;
import javax.swing.*;
import org.json.JSONException;
import org.json.JSONObject;
import src.JsonReader;

public class myframe extends JFrame implements ActionListener {
    JTextField txf = new JTextField();
    private static final DecimalFormat df = new DecimalFormat("0.00");
    JTextField txf2 = new JTextField();
    JLabel label = new JLabel("INPUT MONEY");
    JLabel label2 = new JLabel("OUTPUT MONEY");
    JLabel label3 = new JLabel();
    String[] choice;
    String[] choice2 = { "BDT" };
    JComboBox<String> combo = new JComboBox<>(getStringList());
    JComboBox<String> combo2 = new JComboBox<>(choice2);
    JButton b = new JButton("Convert");
    JButton b2 = new JButton("Clear");

    myframe() {
        setSize(420, 420);
        setTitle("MoneyConverter");
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocation(650, 250);
        setResizable(false);
        getContentPane().setBackground(new Color(255, 213, 128));
        txf.setBounds(30, 150, 100, 30);
        txf2.setBounds(270, 150, 120, 30);
        txf.setBackground(Color.cyan);
        txf2.setBackground(Color.cyan);
        label.setBounds(30, 20, 100, 100);
        label2.setBounds(270, 20, 100, 100);
        label.setForeground(Color.BLUE);
        label2.setForeground(Color.BLUE);
        combo.setBounds(30, 90, 80, 30);
        combo.setBackground(Color.GREEN);
        combo2.setBackground(Color.GREEN);
        combo2.setBounds(270, 90, 80, 30);
        b.setBounds(140, 230, 100, 30);
        b.setBackground(Color.GREEN);
        b.setForeground(Color.red);
        b2.setBounds(140, 270, 100, 30);
        b2.setBackground(Color.GREEN);
        b2.setForeground(Color.red);
        label3.setBounds(140, 20, 150, 50);
        getContentPane().setLayout(null);
        add(txf);
        add(txf2);
        add(combo);
        add(combo2);
        add(label);
        add(b);
        add(b2);
        add(label2);
        add(label3);
        b.addActionListener(this);
        b2.addActionListener(this);
        b.setActionCommand("button");
        b2.setActionCommand("Clear");
    }

    String[] getStringList() throws JSONException, IOException {
        JSONObject data = JsonReader
                .readJsonFromUrl("https://v6.exchangerate-api.com/v6/4e5b7c421edf65ee9d1c525a/latest/USD");
        Set<String> conversionRates = ((JSONObject) data.get("conversion_rates")).keySet();
        String[] dataList = new String[conversionRates.size()];
        System.out.println(conversionRates.size());
        int i = 0;
        for (Object conversionRate : conversionRates) {
            dataList[i] = conversionRate.toString() + " : "
                    + ((JSONObject) data.get("conversion_rates")).get((String) conversionRate);
            i++;
        }
        return dataList;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getActionCommand().equals("button")) {
            String s0 = (String) combo.getSelectedItem();
            String s = (String) combo2.getSelectedItem();
            String s1 = txf.getText();
            try {
                double a = Double.parseDouble(s1);
                if (s1.isEmpty()) {
                    label3.setText("Empty text-field !");
                    txf2.setText(null);
                } else {
                    label3.setText(null);
                    switch (s) {
                        case "BDT":
                            a = a * 105.5085;
                            String s2 = df.format(a);
                            txf2.setText(s2 + " TAKA");
                            break;
                    }
                }
            } catch (NumberFormatException jj) {
                label3.setText("Not a valid double value !");
            }
        } else if (e.getActionCommand().equals("Clear")) {
            txf.setText(null);
            txf2.setText(null);
        }
    }
}
