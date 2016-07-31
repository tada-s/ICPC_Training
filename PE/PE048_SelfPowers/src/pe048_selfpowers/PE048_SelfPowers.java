package pe048_selfpowers;

import java.math.BigInteger;

public class PE048_SelfPowers {

    public static void main(String[] args) {
        BigInteger sum = BigInteger.valueOf(0);
        for(int i = 1; i < 1000; i++){
            BigInteger aux = BigInteger.valueOf(i);
            aux = aux.pow(i);
            sum = sum.add(aux).mod(BigInteger.valueOf((long)1e10));
        }
        System.out.print(sum);
    }
    
}
