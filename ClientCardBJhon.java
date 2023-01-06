
/**
 * Write a description of class ClientCardBJhon here.
 *
 * @author (Brian Jhon)
 * @version (a version number or a date)
 */
import java.awt.Font;
public class ClientCardBJhon
{
   public static void main(String[] args) {
        
        CardBJhon[] sqr = new CardBJhon[25];
        Font font = new Font("Arial", Font.BOLD, 20);
        int count = 0;
        for(int i = 0; i < 5; i++) 
        {
            System.out.println();
            for(int j = 0; j < 5; j++) 
            {
                sqr[count] = new CardBJhon(0.2+(j*0.15),0.15+(i*0.15)); 
                sqr[count].drawMe();
                //the terminal output for numbers for squares
                //will be upside down compared to StdDraw
                System.out.print(sqr[count].getValue() + " ");
                count++;
            }
        }
    
        StdDraw.setFont(font);
        StdDraw.setPenColor(StdDraw.BLUE);
        StdDraw.text(0.5,0.95,"Move using w,s,a,d keys. Flip 5 Squares.");
        char key = '0';
        int value;
        int flipCount = 0;
        int current = 0;
        int previous = 0;
        while(flipCount < 5) {
            sqr[current].selected();
            if(StdDraw.hasNextKeyTyped())
            {
                key = StdDraw.nextKeyTyped();
                value = key;
                if (key == 'w') 
                {
                    if(current >= 20)
                    {
                        current = current - 20;
                    }
                    else
                    {
                        current = current + 5;
                    }
                }
                else if (key == 'a') 
                {
                    if(current == 0 || current == 5 || current == 10 || current == 15 || current == 20)
                    {
                        current = current + 4;  
                    }
                    else
                    {
                        current = current - 1;
                    }
                }
        
                else if (key == 's') 
                {
                    if(current <= 4)
                    {
                        current = current + 20;
                    }
                    else
                    {
                        current = current - 5;
                    }
                }
                else if (key == 'd') 
                {
                    if(current == 4 || current == 9 || current == 14 || current == 19 || current == 24)
                    {
                        current = current - 4;
                    }
                    else
                    {
                        current = current + 1;
                    }
                }
                else if (key == ' ') 
                {
                    sqr[current].flip();
                    flipCount++;
                }
                sqr[previous].deselected();
                previous = current;
                System.out.println("key:["+key+"]="+value);
            } 
            StdDraw.pause(150);
        }
    }
}
