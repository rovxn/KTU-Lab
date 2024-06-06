class NumberPrinter {
    void printEven(int number) {
        synchronized (this) {
            if (number % 2 == 0) {
                System.out.println("Even Thread: " + number);
            }
        }
    }

    void printOdd(int number) {
        synchronized (this) {
            if (number % 2 != 0) {
                System.out.println("Odd Thread: " + number);
            }
        }
    }
}

class EvenThread implements Runnable {
    private NumberPrinter numberPrinter;

    EvenThread(NumberPrinter numberPrinter) {
        this.numberPrinter = numberPrinter;
    }

    public void run() {
        for (int i = 1; i <= 10; i++) {
            numberPrinter.printEven(i);
        }
    }
}

class OddThread implements Runnable {
    private NumberPrinter numberPrinter;

    OddThread(NumberPrinter numberPrinter) {
        this.numberPrinter = numberPrinter;
    }

    public void run() {
        for (int i = 1; i <= 10; i++) {
            numberPrinter.printOdd(i);
        }
    }
}

public class Exp12_BlockSync {
    public static void main(String[] args) {
        NumberPrinter numberPrinter = new NumberPrinter();
        Thread evenThread = new Thread(new EvenThread(numberPrinter));
        Thread oddThread = new Thread(new OddThread(numberPrinter));

        evenThread.start();
        oddThread.start();
    }
}