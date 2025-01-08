import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    while (true){
      calc();
    }
  }

  private static void calc() {
    Scanner scanner = new Scanner(System.in);

    System.out.print("First Number ('exit' to exit): ");
    String s_uno = scanner.next();
    if (s_uno.equalsIgnoreCase("exit")) {
      System.exit(0);
    }
    Double uno = Double.parseDouble(s_uno);

    System.out.print("Operator (+, -, *, /, ^, %): ");
    String op = scanner.next();
    
    System.out.print("Second Number: ");
    double dos = scanner.nextDouble();
    
    double res = 1.0;

    switch (op) { // switch for the operators
      case "+":
        res = uno + dos;
        break;
      case "-":
        res = uno - dos;
        break;
      case "*":
        res = uno * dos;
        break;
      case "/":
        if (dos != 0) {
          res = uno / dos;
        } else {
          System.out.println("Error");
          return;
        }
        break;
      case "^":
        for (int i = 0; i < dos; i++){ // exponent
          res *= uno;
        }
        break;
      case "%":
        res = uno % dos;
        break;
      default:
        System.out.println("Error"); // if unknown operator
        return;
    }

    System.out.println("Result: " + res);

  }
}
