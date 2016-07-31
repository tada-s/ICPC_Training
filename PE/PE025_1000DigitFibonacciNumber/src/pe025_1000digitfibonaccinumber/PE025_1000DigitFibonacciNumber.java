package pe025_1000digitfibonaccinumber;

import java.math.BigInteger;

public class PE025_1000DigitFibonacciNumber {
    
    public static void main(String[] args) {
        BigInteger n1 = BigInteger.valueOf(1);
        BigInteger n2 = BigInteger.valueOf(1);
        BigInteger n3 = n1.add(n2);
        int t = 3;
        while(n3.toString().length() < 1000){
            n1 = n2;
            n2 = n3;
            n3 = n1.add(n2);
            t++;
        }
        System.out.print(t);
    }
    
}
