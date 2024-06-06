interface Animal {
    void eat();
    void sleep();
}

interface Bird extends Animal {
    void fly();
}

class Eagle implements Bird {
    public void eat() {
        System.out.println("Eagle eats");
    }

    public void sleep() {
        System.out.println("Eagle sleeps");
    }

    public void fly() {
        System.out.println("Eagle flies");
    }
}

public class Exp7_InterfaceInherit {
    public static void main(String[] args) {
        Eagle eagle = new Eagle();
        eagle.eat();
        eagle.sleep();
        eagle.fly();
    }
}