import java.math.BigInteger;
import java.util.Scanner;
 
public class Main {
 
    private static BigInteger gcd(BigInteger a, BigInteger b) {
        BigInteger t;
        while (a.compareTo(BigInteger.ZERO) != 0) {
            t = a;
            a = b.mod(a);
            b = t;
        }
        return b;
    }
 
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        BigInteger a, b, g;
        for(int i= 0; i<n;++i){
            a = s.nextBigInteger();
            s.next();
            b = s.nextBigInteger();
            g = gcd(a, b);
            System.out.println(a.divide(g) + " / " + b.divide(g));
        }
    }
}