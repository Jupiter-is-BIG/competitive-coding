import java.util.Scanner;
public class A {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(int i = 0; i < t; ++i) {
            s.nextLine();
            long a , b;
            a = s.nextInt();
            b = s.nextInt();
            // if a not | b then lcm (a,b) [a <= b]
            // otherwise, b^2/a
            if (b%a != 0) {
                System.out.println(lcm(a,b));
            } else {
                System.out.println((b*b)/a);
            }
        }
        s.close();
    } 

   static long lcm(long num1, long num2){
        long gcd = gcd(num1,num2);
        return((num1*num2)/gcd);
    }
    public static long gcd(long a, long b) {
        if (b==0) return a;
        return gcd(b,a%b);
    } 
}
