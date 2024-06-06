class NumberThread implements Runnable {
    private String threadName;

    NumberThread(String threadName) {
        this.threadName = threadName;
    }

    public void run() {
        for (int i = 1; i <= 10; i++) {
            System.out.println(threadName + ": " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted: " + e.getMessage());
            }
        }
    }
}

public class Exp10_MultiThreading {
    public static void main(String[] args) {
        Thread firstThread = new Thread(new NumberThread("FIRST THREAD"));
        Thread secondThread = new Thread(new NumberThread("SECOND THREAD"));

        firstThread.start();
        secondThread.start();
    }
}