public class Exp6_Exception {
    static void method() throws NullPointerException {
        System.out.println("Inside method");
        throw new NullPointerException("Demo");
    }

    public static void main(String[] args) {
        try {
            method();
        } catch (NullPointerException e) {
            System.out.println("Caught inside main : " + e.getMessage());
        } finally {
            System.out.println("finally block executed");
        }
    }
}