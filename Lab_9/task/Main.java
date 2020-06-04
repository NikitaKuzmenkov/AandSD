import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        BinHeap heap = new BinHeap();
        int number;
        do {
            System.out.println("1 - ADD;");
            System.out.println("2 - DELETE;");
            System.out.println("3 - CLEAR");
            int a = scan.nextInt();
            switch (a) {
                case 1:
                    System.out.println("Enter the number: ");
                    heap.insert(scan.nextInt());
                    break;
                case 2:
                    heap.Min();
                    break;
                case 3:
                    heap.clear();
                    break;
                default:
                    break;
            }
            heap.print();
            System.out.println("\n4 - CONTINUE...");
            number=scan.nextInt();
        } while (number == 4 );
    }
}