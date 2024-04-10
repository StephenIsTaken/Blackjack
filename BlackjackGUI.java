import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

enum Cards {
    Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Ace, King, Queen
}

public class BlackjackGUI extends JFrame implements ActionListener {
    private JLabel yourCardsLabel, yourSumLabel, dealerCardsLabel, dealerSumLabel, resultLabel, balanceLabel;
    private JButton hitButton, standButton, resetButton;
    private int yourSum, dealerSum;
    private int balance = 500;

    public BlackjackGUI() {
        setTitle("Blackjack");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        yourCardsLabel = new JLabel("Your cards: ");
        yourSumLabel = new JLabel("Your sum: ");
        dealerCardsLabel = new JLabel("Dealer cards: ");
        dealerSumLabel = new JLabel("Dealer sum: ");
        resultLabel = new JLabel();
        balanceLabel = new JLabel("Balance: ");

        hitButton = new JButton("Hit");
        standButton = new JButton("Stand");
        resetButton = new JButton("Deal");

        hitButton.addActionListener(this);
        standButton.addActionListener(this);
        resetButton.addActionListener(this);

        JPanel buttonsPanel = new JPanel();
        buttonsPanel.setLayout(new FlowLayout());
        buttonsPanel.add(hitButton);
        buttonsPanel.add(standButton);
        buttonsPanel.add(resetButton);

        setLayout(new GridLayout(7, 1));
        add(yourCardsLabel);
        add(yourSumLabel);
        add(dealerCardsLabel);
        add(dealerSumLabel);
        add(resultLabel);
        add(balanceLabel);
        add(buttonsPanel);

        initializeGame();

        setVisible(true);
    }

    private void initializeGame() {
        yourSum = dealerSum = 0;

        // Generate your cards
        Cards yourCard1 = getRandomCard();
        Cards yourCard2 = getRandomCard();

        // Generate dealer cards
        Cards dealerCard1 = getRandomCard();
        Cards dealerCard2 = getRandomCard();

        yourSum += translateToInt(yourCard1) + translateToInt(yourCard2);
        dealerSum += translateToInt(dealerCard1) + translateToInt(dealerCard2);

        yourCardsLabel.setText("Your cards: " + translateToString(yourCard1) + " " + translateToString(yourCard2));
        yourSumLabel.setText("Your sum: " + yourSum);
        dealerCardsLabel.setText("Dealer cards: " + translateToString(dealerCard1) + " " + translateToString(dealerCard2));
        dealerSumLabel.setText("Dealer sum: " + dealerSum);
        resultLabel.setText("");
        balanceLabel.setText("Balance: " + balance);

        if (yourSum == 21) {
            stand();
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == hitButton) {
            hit();
        } else if (e.getSource() == standButton) {
            stand();
        } else if (e.getSource() == resetButton) {
            reset();
        }
    }

    private void hit() {
        Cards card = getRandomCard();
        yourSum += translateToInt(card);

        yourCardsLabel.setText(yourCardsLabel.getText() + " " + translateToString(card));
        yourSumLabel.setText("Your sum: " + yourSum);

        if (yourSum > 21) {
            resultLabel.setText("You lost");
            balance -= 50; // Assuming each game costs 10 units
        } else if (yourSum == 21) {
            stand();
        }
    }

    private void stand() {
        while (dealerSum < 17) {
            Cards card = getRandomCard();
            dealerSum += translateToInt(card);
            dealerCardsLabel.setText(dealerCardsLabel.getText() + " " + translateToString(card));
            dealerSumLabel.setText("Dealer sum: " + dealerSum);
        }

        if (dealerSum > 21 || dealerSum < yourSum) {
            resultLabel.setText("You won");
            balance += 50; // Assuming each win gives 10 units
        } else if (dealerSum > yourSum) {
            resultLabel.setText("You lost");
            balance -= 50; // Assuming each game costs 10 units
        } else {
            resultLabel.setText("It's a draw");
        }

        balanceLabel.setText("Balance: " + balance);
    }

    private void reset() {
        initializeGame();
    }

    private Cards getRandomCard() {
        Random rand = new Random();
        return Cards.values()[rand.nextInt(13)];
    }

    private String translateToString(Cards card) {
        return card.toString();
    }

    private int translateToInt(Cards card) {
        switch (card) {
            case Two:
                return 2;
            case Three:
                return 3;
            case Four:
                return 4;
            case Five:
                return 5;
            case Six:
                return 6;
            case Seven:
                return 7;
            case Eight:
                return 8;
            case Nine:
                return 9;
            case Ten:
            case King:
            case Queen:
                return 10;
            case Ace:
                return 11;
            default:
                return 0;
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new BlackjackGUI());
    }
}
