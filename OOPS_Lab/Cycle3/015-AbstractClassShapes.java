abstract class Shape {
  abstract void noOfSides();
}

class Rectangle extends Shape {
  @Override
  void noOfSides() {
    System.out.println("A rectangle has 4 sides");
  }
}

class Triangle extends Shape {
  @Override
  void noOfSides() {
    System.out.println("A triangle has 3 sides");
  }
}

class Hexagon extends Shape {
  @Override
  void noOfSides() {
    System.out.println("A hexagon has 6 sides");
  }
}

class AbstractClassShapes {
  public static void main(String[] args) {
    Shape rectangle = new Rectangle();
    Shape triangle = new Triangle();
    Shape hexagon = new Hexagon();

    rectangle.noOfSides();
    triangle.noOfSides();
    hexagon.noOfSides();
  }
}
