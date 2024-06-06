abstract class Shape {
    abstract void numberOfSides();
}

class Rectangle extends Shape {
    void numberOfSides() {
        System.out.println("Rectangle has 4 sides.");
    }
}

class Triangle extends Shape {
    void numberOfSides() {
        System.out.println("Triangle has 3 sides.");
    }
}

class Hexagon extends Shape {
    void numberOfSides() {
        System.out.println("Hexagon has 6 sides.");
    }
}

public class Exp5_Abstract {
    public static void main(String[] args) {
        Rectangle rectangle = new Rectangle();
        rectangle.numberOfSides();

        Triangle triangle = new Triangle();
        triangle.numberOfSides();

        Hexagon hexagon = new Hexagon();
        hexagon.numberOfSides();
    }
}