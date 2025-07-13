import javax.swing.*;
import javax.swing.text.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.util.ArrayList;
import javax.swing.event.*;

public class Main {
    private JTextPane textPane;
    private JFrame frame;
    private JLabel wordCountLabel, charCountLabel;
    private JPanel sketchPad;
    private ArrayList<Shape> shapes = new ArrayList<>();
    private Point startPoint, endPoint;
    private String currentShape = "Rectangle";

    public Main() {
        frame = new JFrame("Text Editor");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(1000, 600);
        frame.setLayout(new BorderLayout());

        // Main Text Area
        textPane = new JTextPane();
        textPane.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void insertUpdate(DocumentEvent e) {
                updateWordAndCharCount();
            }

            @Override
            public void removeUpdate(DocumentEvent e) {
                updateWordAndCharCount();
            }

            @Override
            public void changedUpdate(DocumentEvent e) {
                updateWordAndCharCount();
            }
        });
        JScrollPane textScrollPane = new JScrollPane(textPane);

        // SketchPad Panel
        sketchPad = new JPanel() {
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2d = (Graphics2D) g;
                for (Shape shape : shapes) {
                    g2d.draw(shape);
                }
            }
        };
        sketchPad.setPreferredSize(new Dimension(400, 600));
        sketchPad.setBackground(Color.LIGHT_GRAY);
        setupSketchPad();

        // Split Pane for Text and SketchPad
        JSplitPane splitPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, textScrollPane, sketchPad);
        frame.add(splitPane, BorderLayout.CENTER);

        // Bottom Panel for Word/Character Count
        JPanel bottomPanel = new JPanel();
        wordCountLabel = new JLabel("Words: 0");
        charCountLabel = new JLabel("Characters: 0");
        bottomPanel.add(wordCountLabel);
        bottomPanel.add(charCountLabel);
        frame.add(bottomPanel, BorderLayout.SOUTH);

        // Menu Bar
        JMenuBar menuBar = new JMenuBar();
        frame.setJMenuBar(menuBar);

        // File Menu
        JMenu fileMenu = new JMenu("File");
        menuBar.add(fileMenu);

        JMenuItem saveItem = new JMenuItem("Save");
        saveItem.addActionListener(e -> saveFile());
        fileMenu.add(saveItem);

        JMenuItem loadItem = new JMenuItem("Open");
        loadItem.addActionListener(e -> loadFile());
        fileMenu.add(loadItem);

        // Edit Menu
        JMenu editMenu = new JMenu("Edit");
        menuBar.add(editMenu);

        JMenuItem cutItem = new JMenuItem("Cut");
        cutItem.addActionListener(e -> textPane.cut());
        editMenu.add(cutItem);

        JMenuItem copyItem = new JMenuItem("Copy");
        copyItem.addActionListener(e -> textPane.copy());
        editMenu.add(copyItem);

        JMenuItem pasteItem = new JMenuItem("Paste");
        pasteItem.addActionListener(e -> textPane.paste());
        editMenu.add(pasteItem);

        JMenuItem findReplaceItem = new JMenuItem("Find & Replace");
        findReplaceItem.addActionListener(e -> findAndReplace());
        editMenu.add(findReplaceItem);

        // Count Letters Functionality
        JMenuItem countLettersItem = new JMenuItem("Count Letters");
        countLettersItem.addActionListener(e -> countLetters());
        editMenu.add(countLettersItem);

        // Change Case Menu Items
        JMenuItem toUpperCaseItem = new JMenuItem("Convert to UPPERCASE");
        toUpperCaseItem.addActionListener(e -> changeCase(true));
        editMenu.add(toUpperCaseItem);

        JMenuItem toLowerCaseItem = new JMenuItem("Convert to lowercase");
        toLowerCaseItem.addActionListener(e -> changeCase(false));
        editMenu.add(toLowerCaseItem);

        // Font Menu
        JMenu fontMenu = new JMenu("Font");
        menuBar.add(fontMenu);

        JMenuItem fontItem = new JMenuItem("Change Font");
        fontItem.addActionListener(e -> changeFont());
        fontMenu.add(fontItem);

        // Shape Menu
        JMenu shapeMenu = new JMenu("Shapes");
        menuBar.add(shapeMenu);

        String[] shapeOptions = {"Rectangle", "Oval", "Line"};
        for (String shape : shapeOptions) {
            JMenuItem shapeItem = new JMenuItem(shape);
            shapeItem.addActionListener(e -> currentShape = shape);
            shapeMenu.add(shapeItem);
        }

        JMenuItem clearShapesItem = new JMenuItem("Clear Shapes");
        clearShapesItem.addActionListener(e -> {
            shapes.clear();
            sketchPad.repaint();
        });
        shapeMenu.add(clearShapesItem);

        frame.setVisible(true);
    }

    private void setupSketchPad() {
        sketchPad.addMouseListener(new MouseAdapter() {
            public void mousePressed(MouseEvent e) {
                startPoint = e.getPoint();
            }

            public void mouseReleased(MouseEvent e) {
                endPoint = e.getPoint();
                addShape();
                sketchPad.repaint();
            }
        });

        sketchPad.addMouseMotionListener(new MouseMotionAdapter() {
            public void mouseDragged(MouseEvent e) {
                endPoint = e.getPoint();
                sketchPad.repaint();
            }
        });
    }

    private void addShape() {
        if (startPoint == null || endPoint == null) return;

        int x = Math.min(startPoint.x, endPoint.x);
        int y = Math.min(startPoint.y, endPoint.y);
        int width = Math.abs(endPoint.x - startPoint.x);
        int height = Math.abs(endPoint.y - startPoint.y);

        switch (currentShape) {
            case "Rectangle":
                shapes.add(new Rectangle(x, y, width, height));
                break;
            case "Oval":
                shapes.add(new Ellipse2D.Double(x, y, width, height));
                break;
            case "Line":
                shapes.add(new Line2D.Double(startPoint, endPoint));
                break;
        }
    }

    private void saveFile() {
        JFileChooser fileChooser = new JFileChooser();
        int option = fileChooser.showSaveDialog(frame);
        if (option == JFileChooser.APPROVE_OPTION) {
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileChooser.getSelectedFile()))) {
                writer.write(textPane.getText());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    private void loadFile() {
        JFileChooser fileChooser = new JFileChooser();
        int option = fileChooser.showOpenDialog(frame);
        if (option == JFileChooser.APPROVE_OPTION) {
            try (BufferedReader reader = new BufferedReader(new FileReader(fileChooser.getSelectedFile()))) {
                textPane.setText(reader.lines().collect(java.util.stream.Collectors.joining("\n")));
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    private void findAndReplace() {
        String find = JOptionPane.showInputDialog(frame, "Find:");
        String replace = JOptionPane.showInputDialog(frame, "Replace:");
        if (find != null && replace != null) {
            String content = textPane.getText();
            content = content.replace(find, replace);
            textPane.setText(content);
        }
    }

    private void updateWordAndCharCount() {
        String content = textPane.getText();
        int words = content.trim().isEmpty() ? 0 : content.split("\\s+").length;
        int chars = content.length();
        wordCountLabel.setText("Words: " + words);
        charCountLabel.setText("Characters: " + chars);
    }

    private void countLetters() {
        String content = textPane.getText();
        long letterCount = content.chars()
                .filter(Character::isLetter)
                .count();
        JOptionPane.showMessageDialog(frame, "Total Letters: " + letterCount, "Letter Count", JOptionPane.INFORMATION_MESSAGE);
    }

    private void changeCase(boolean toUpperCase) {
        String selectedText = textPane.getSelectedText();
        if (selectedText != null) {
            String replacement = toUpperCase ? selectedText.toUpperCase() : selectedText.toLowerCase();
            try {
                int start = textPane.getSelectionStart();
                int end = textPane.getSelectionEnd();
                textPane.getDocument().remove(start, end - start);
                textPane.getDocument().insertString(start, replacement, null);
            } catch (BadLocationException e) {
                e.printStackTrace();
            }
        } else {
            JOptionPane.showMessageDialog(frame, "No text selected!", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void changeFont() {
        String[] fonts = GraphicsEnvironment.getLocalGraphicsEnvironment().getAvailableFontFamilyNames();
        String font = (String) JOptionPane.showInputDialog(frame, "Choose Font:", "Font",
                JOptionPane.PLAIN_MESSAGE, null, fonts, textPane.getFont().getFamily());
        if (font != null) {
            textPane.setFont(new Font(font, Font.PLAIN, textPane.getFont().getSize()));
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Main::new);
    }
}
