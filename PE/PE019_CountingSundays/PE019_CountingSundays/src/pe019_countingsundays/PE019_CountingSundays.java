/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package pe019_countingsundays;

import java.text.SimpleDateFormat;
import java.util.Locale;
import java.util.Date;

public class PE019_CountingSundays {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int cDay = 0;
        Date date = null;
        SimpleDateFormat sdf = new SimpleDateFormat("d MM yyyy",new Locale("en"));
        for(int y = 1901; y <= 2000; y++){
            for(int m = 1; m <= 12; m++){
                try{ date = sdf.parse("1 " + m + " " + y); }catch(Exception e){}
                String str = date.toString();
                if(str.startsWith("Sun")){
                    cDay++;
                }
            }
        }
        System.out.print(cDay);
    }
    
}
