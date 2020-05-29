import java.awt.*;
import javax.swing.*;
import java.io.*;
import java.net.*;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.ArrayList;

public class GUIServidor{

    public static void main(String args[]) {
        
        JFrame frame = new JFrame("GUIServidor");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);        
        newPanel panel = new newPanel();
        frame.add(panel);
        frame.setSize(900, 700);
        frame.setVisible(true);
        
        DatagramSocket sock = null;
        try{		
            sock = new DatagramSocket(7200);
            byte[] buffer = new byte[65536];
            DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
            while(true){
                sock.receive(reply);                
                byte[] data = reply.getData();
                ByteBuffer buf = ByteBuffer.wrap(data);
                buf.order(ByteOrder.LITTLE_ENDIAN);
                
                int operationId=buf.getInt(8);
                
                if(operationId==1){//Dibujar
                    int x=buf.getInt(12);
                    int y=buf.getInt(16);       
                    panel.drawCoord(x,y,x,y,Color.GREEN);    
                }else{//Borrar
                    int x=buf.getInt(12);
                    int y=buf.getInt(16);
                    panel.drawCoord(x,y,x,y,Color.BLACK);    
                }
                
                
            }
        }catch(IOException e){
            System.err.println("IOException " + e);
        }     
    }
}

class newPanel extends JPanel{     
    
    ArrayList<Line>lines = new ArrayList<>();
    
    public newPanel(){ 
        this.setBackground(Color.BLACK);
    }
    
    public void drawCoord(int x1, int y1,int x2,int y2,Color colr){
        lines.add(new Line(x1,y1,x2,y2,colr));
        repaint();
    }
    
    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        for(int i=0;i<lines.size();i++) {
            g.setColor(lines.get(i).getColr());
            g.drawLine(lines.get(i).getX1(), lines.get(i).getY1(),lines.get(i).getX2(),lines.get(i).getY2());   
        }
    }
}

class Line{
    private final int x1;
    private final int y1;
    private final int x2;
    private final int y2;
    private final Color colr;
    
    public Line(int x1,int y1,int x2,int y2, Color colr){
        this.x1=x1;
        this.y1=y1;
        this.x2=x2;
        this.y2=y2;
        this.colr=colr;
    }

    public int getX1() {
        return x1;
    }

    public int getY1() {
        return y1;
    }

    public int getX2() {
        return x2;
    }

    public int getY2() {
        return y2;
    }

    public Color getColr() {
        return colr;
    }
    
}