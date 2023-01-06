
/**
 * Write a description of class CardBJhon here.
 *
 * @author (Brian Jhon)
 * @version (a version number or a date)
 */
import java.util.Random;
public class CardBJhon extends SqrBJhon
{
    
    String value;
    boolean flipped;

    public CardBJhon() 
    {
        super();
        super.setRGB(200,200,200);
        Random rand = new Random();
        value = Integer.toString(rand.nextInt(5) + 1);
        flipped = false;    
    }
    
    public CardBJhon(double x, double y) 
    {
        super(x,y,0.07,0.07);
        setRGB(120,120,120);
        Random rand = new Random();
        value = Integer.toString(rand.nextInt(5) + 1);
        flipped = false;
    }
    
    public String getValue() 
    
    {
        return value;
    }
    
    public void flip() 
    {
        if (flipped == true) 
        {
            flipped = false;
            setRGB(125,100,200);
            drawMe();
        }
        else 
        {
            flipped = true;
            setRGB(0,0,255);
            drawMe();
            StdDraw.setPenColor(StdDraw.YELLOW);
            StdDraw.text(getX(),getY(), value);
        }
    }
    
    public void selected() 
    {
        StdDraw.setPenColor(StdDraw.RED);
        StdDraw.rectangle(getX(),getY(),getWidth(),getHeight());
    }
    
    public void deselected() 
    {
        StdDraw.setPenColor(StdDraw.WHITE);
        StdDraw.rectangle(getX(),getY(),getWidth(),getHeight());
        StdDraw.setPenColor(StdDraw.BLACK);
        StdDraw.rectangle(getX(),getY(),getWidth(),getHeight());
    }
}
