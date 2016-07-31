/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package pe016_powerdigitsum;

import java.math.BigInteger;

/**
 *
 * @author Tadashi
 */
public class PE016_PowerDigitSum {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        BigInteger b = BigInteger.valueOf(2);
        b = b.pow(1000);
        String str = b.toString();
        int sum = 0;
        for(int i = 0; i < str.length(); i++){
            sum += str.charAt(i) - '0';
        }
        System.out.print(sum);
    }
    
}
