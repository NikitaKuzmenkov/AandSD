import java.util.Scanner;

public class Binary{	
	public static void printMenu(){
		System.out.println();
		System.out.println("\t1 - Ввод узла;");
		System.out.println("\t2 - Вывод дерева;");
		System.out.println("\t3 - Поиск узла;");
		System.out.println("\t4 - Удаление узла;");
		System.out.println("\t5 - Порядок;");
		System.out.println("\t6 - Анализ узлов;");
		System.out.println("\t0 - Конец программы;");
		System.out.println();
	}
	public static void main(String[] args){
		BinaryTree tree = new BinaryTree();
		Scanner in = new Scanner(System.in);
		char controlButton;  
		while(true){
			printMenu();
			System.out.print("");
			controlButton = in.next().charAt(0);

			switch (controlButton) {
           	case  ('1'):
                System.out.print("Ввод узла:");
               	tree.insert(in.nextInt());
				          
				System.out.println("\n\tУзел добавлен...");
               	break;
           	case ('2'):
           		tree.print(0, tree.root, "\nКорень: ");
                break;
           	case ('3'):
                System.out.print("Ввод ключа:");
               	boolean check = tree.find(in.nextInt()).exist;
				          
				System.out.println(check ? "\n\tУзел найден" : "\n\tУзел не найден...");
               	break;
           	case ('4'):
				System.out.print("Ввод узла: ");
               	tree.delete(in.nextInt());
				          
				System.out.println("\n\tУзел добавлен...");
               	break;
           	case ('5'):
			   		System.out.println("\nrправ.: ");
					tree.preOrder(tree.root);
			   		System.out.println("\nреверс.: ");
					tree.postOrder(tree.root);
			   		System.out.println("\nсимметрич.: ");
					tree.inOrder(tree.root);
               	break;
            case ('6'):
            System.out.print("Ввод узла: ");
                  int tempKey = in.nextInt();
            System.out.println("Глубина: " + tree.depth(tempKey));
            System.out.println("Высота: " + tree.hight(tempKey));
            System.out.println("уровень: " + tree.layer(tempKey));
                break;
            case ('7'):
                  tree.task();
                break;
           	case ('0'):
           	    System.out.println("\tКонец программы...\n");
           		System.exit(0);
              	break;
           	default:
               	System.out.println("\tОшибка...");
               break;
       		}
		}

	}
}