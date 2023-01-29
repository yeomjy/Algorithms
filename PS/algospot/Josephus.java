import java.util.LinkedList;
import java.util.Scanner;

public class Josephus {

    public static void main(String[] args) {

        int n, m, c, k;
        Scanner sc = new Scanner(System.in);

        c = sc.nextInt();

        for (int _c = 0; _c < c; _c++) {
            LinkedList<Integer> l = new LinkedList<>();
            n = sc.nextInt();
            m = sc.nextInt();

            for (int i = 0; i < n; i++) {
                l.add(i + 1);
            }

            k = 0;

            for (int i = 0; i < n - 2; i++) {
                l.remove(k);
                k = (k + m - 1) % l.size();
            }
            int x = l.get(0);
            int y = l.get(1);

            if (x > y)
                System.out.println(y + " " + x);
            else
                System.out.println(x + " " + y);
        }
    }
}
