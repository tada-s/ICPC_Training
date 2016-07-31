package pe020_factorialdigitsum;

import java.math.BigInteger;

public class PE020_FactorialDigitSum {

    public static void main(String[] args) {
        BigInteger n = BigInteger.valueOf(1);
        for(int i = 2; i < 100; i++){
            n = n.multiply(BigInteger.valueOf(i));
        }
        long sum = 0;
        String str = n.toString();
        for(int i = 0; i < str.length(); i++){
            sum += str.charAt(i) - '0';
        }
        System.out.print(sum);
    }
    
}
