
/**
 * Write a description of class SqrBJhon here.
 *
 * @author (Brian Jhon)
 * @version (a version number or a date)
 */
import java.awt.Font;
import java.util.Random;
public class SqrBJhon
{
    private double x,y; //0-0.9999
    private double halfWidth, halfHeight; //0-0.50
    private boolean filled; //false
    private int red,green,blue; //0-255
    
    public SqrBJhon()
    {
        x = 0.50;
        y = 0.50;
        Random fill = new Random();
        int fillNum = fill.nextInt(2);
        halfWidth = halfHeight = (fill.nextInt(5)+6)/100.0;
        red = green = blue = 100;
    }
    
    public SqrBJhon(double x, double y, double halfWidth, double halfHeight)
    {
        Random fill = new Random();
        int fillNum = fill.nextInt(2);
        this.x = x;
        this.y = y;
        this.halfWidth = halfWidth;
        this.halfHeight = halfHeight;
    }
    
    public double getArea()
    {
        double area = halfWidth * halfHeight;
        return area;
    }
    
    public double getPerimeter()
    {
        double perimeter = 2*halfWidth + 2*halfHeight;
        return perimeter;
    }
    
    public double getWidth()
    {
        return halfWidth;
    }
    
    public double getHeight()
    {
        return halfHeight;
    }
    
    public int getRed()
    {
        return red;
    }
    
    public int getGreen()
    {
        return green;
    }
    
    public int getBlue()
    {
        return blue;
    }
    
    public double getX()
    {
        return x;
    }
    
    public double getY()
    {
        return y;
    }
    
    public void setX(double x)
    {
        this.x = x;
    }
    
    public void setY(double y)
    {
        this.y = y;
    }
    
    public void setRGB(int r, int g, int b)
    {
        red = r;
        green = g;
        blue = b;
    }
    
    public void moveLeft()
    {
        eraseMe();
        x = x - 0.2;
        drawMe();
    }
    
    public void moveRight()
    {
        eraseMe();
        x = x + 0.2;
        drawMe();
    }
    
     public void moveDown() 
     {
        eraseMe();
        y = y - 0.2;
        drawMe();
    }
    
    public void moveUp() 
    {
        eraseMe();
        y = y + 0.2;
        drawMe();
    }
    
    public void drawMe()
    {
        StdDraw.setPenColor(red,green,blue);
        StdDraw.filledRectangle(x,y, halfWidth,halfHeight);
    }
    
    public void eraseMe()
    {
        StdDraw.setPenColor(StdDraw.WHITE);
        StdDraw.filledRectangle(x,y, halfWidth,halfHeight);
        StdDraw.rectangle(x,y, halfWidth,halfHeight);
        
    }
}
