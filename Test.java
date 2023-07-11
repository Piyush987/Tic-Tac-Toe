import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        TicTacToe game = new TicTacToe();

        game.welcome();
        game.choose();

        while (true) {
            game.showBoard();
            game.playerMove(sc);

            if (game.checkWin() != TicTacToe.Status.CONTINUE) break;

            game.computerMove();

            if (game.checkWin() != TicTacToe.Status.CONTINUE) break;
        }

        game.showBoard();
        game.showResult();
    }
}

class TicTacToe {
    enum Status {
        CONTINUE,
        PLAYER_WIN,
        COMPUTER_WIN,
        DRAW
    }

    private char[][] board = {{'0', '1', '2'}, {'3', '4', '5'}, {'6', '7', '8'}};
    private char playerChoice;
    private char computerChoice;
    private Random random = new Random();

    public void welcome() {
        System.out.println("Welcome to Tic Tac Toe!");
        System.out.println("Rules: Try to get 3 in a row, column or diagonal.");
    }

    public void choose() {
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println("Choose X or O (capital letters):");
            String input = sc.nextLine().toUpperCase();

            if ("X".equals(input)) {
                playerChoice = 'X';
                computerChoice = 'O';
                break;
            } else if ("O".equals(input)) {
                playerChoice = 'O';
                computerChoice = 'X';
                break;
            } else {
                System.out.println("Invalid choice. Please choose X or O.");
            }
        }
    }

    public void showBoard() {
        for (char[] row : board) {
            System.out.println(row[0] + "|" + row[1] + "|" + row[2]);
            System.out.println("-----");
        }
    }

    public void playerMove(Scanner sc) {
        while (true) {
            System.out.println("Enter the number of the cell where you want to place your move:");
            String input = sc.nextLine();

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == input.charAt(0)) {
                        board[i][j] = playerChoice;
                        return;
                    }
                }
            }

            System.out.println("Invalid move. Try again.");
        }
    }

    public void computerMove() {
        while (true) {
            int i = random.nextInt(3);
            int j = random.nextInt(3);

            if (Character.isDigit(board[i][j])) {
                board[i][j] = computerChoice;
                break;
            }
        }
    }

    public Status checkWin() {
        // Rows and columns
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
                return board[i][0] == playerChoice ? Status.PLAYER_WIN : Status.COMPUTER_WIN;
            }

            if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
                return board[0][i] == playerChoice ? Status.PLAYER_WIN : Status.COMPUTER_WIN;
            }
        }

        // Diagonals
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            return board[0][0] == playerChoice ? Status.PLAYER_WIN : Status.COMPUTER_WIN;
        }

        if (board[2][0] == board[1][1] && board[2][0] == board[0][2]) {
            return board[2][0] == playerChoice ? Status.PLAYER_WIN : Status.COMPUTER_WIN;
        }

        // Draw
        boolean draw = true;
        for (char[] row : board) {
            for (char cell : row) {
                if (Character.isDigit(cell)) {
                    draw = false;
                    break;
                }
            }
        }

        if (draw) return Status.DRAW;

        return Status.CONTINUE;
    }

    public void showResult() {
        switch (checkWin()) {
            case PLAYER_WIN:
                System.out.println("Congratulations! You won!");
                break;
            case COMPUTER_WIN:
                System.out.println("Sorry, the computer won.");
                break;
            case DRAW:
                System.out.println("It's a draw!");
                break;
            default:
                break;
        }
    }
}
