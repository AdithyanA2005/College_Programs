class MethdOverloading {
  public static void main(String[] args) {
    double area;

    // Calculate area of a rectangle
    area = calculateArea(5, 4);
    System.out.println("Area of rectangle: " + area);

    // Calculate area of a circle
    area = calculateArea(5, 2, 2);
    System.out.println("Area of circle: " + area);

    // Calculate area of a square
    area = calculateArea(5);
    System.out.println("Area of square: " + area);

    // Calculate area of a circle
    area = calculateArea(5.0);
    System.out.println("Area of circle: " + String.format("%.2f", area));
  }

  static double calculateArea(double length, double breadth) {
    return length * breadth;
  }

  static int calculateArea(int side) {
    return side * side;
  }

  static double calculateArea(double radius) {
    return Math.PI * radius * radius;
  }

  static double calculateArea(double side1, double side2, double side3) {
    double s = (side1 + side2 + side3) / 2;
    return Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));
  }
}
