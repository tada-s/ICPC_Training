import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    static final BigInteger EMPTY = bi(-1);
    static BigInteger dp[][][] = new BigInteger[50 + 1][50 + 1][4000 + 1];

    static int min(int n1, int n2){
        if(n1 < n2) return n1;
        else return n2;
    }

    static BigInteger p(int f, int d, int s){
      if(dp[f][d][s] == EMPTY){
        if(f * d < s){
          dp[f][d][s] = bi(0);
        }else{
          if(d == 1){
            dp[f][d][s] = bi(1);
          }else{
            BigInteger sum = bi(0);
            for(int i = 1; i <= min(f, s - 1); i++){
              sum = sum.add(p(f, d - 1, s - i));
            }
            dp[f][d][s] = sum;
          }
        }
      }
      return dp[f][d][s];
    }    
    
    static BigInteger bi(int n){
        return BigInteger.valueOf(n);
    }

    public static void main(String[] args) {
        for(int i = 0; i <= 50; i++){
         for(int j = 0; j <= 50; j++){
           for(int k = 0; k <= 4000; k++){
             dp[i][j][k] = EMPTY;
           } 
         } 
        }
        Scanner sc = new Scanner(System.in);
        int f, n, s;
        while(sc.hasNextInt()){
            f = sc.nextInt();
            n = sc.nextInt();
            s = sc.nextInt();
            System.out.println(p(f,n,s) + "/" + bi(f).pow(n));
        }
    }
    
}
