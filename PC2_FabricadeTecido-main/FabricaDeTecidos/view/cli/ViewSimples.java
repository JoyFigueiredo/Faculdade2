package trabalhopc2.FabricaDeTecidos.view.cli;


import trabalhopc2.FabricaDeTecidos.view.IMessageView;
import java.util.Scanner;

public class ViewSimples implements IMessageView{
    
    protected Scanner entrada;

    public ViewSimples() {
        entrada = new Scanner(System.in);
    }
    
    @Override
    public void showMessage(String msg){
        System.out.println(msg);
    }
    
    @Override
    public void showErrorMessage(String msg) {
        System.out.println(msg);
    }

    @Override
    public int askForInt(String question) {
        showMessage(question);
        int inteiro = entrada.nextInt();
        return inteiro;
                
    }
    
    @Override
    public double askForDouble(String question) {
        showMessage(question);
        double d = entrada.nextDouble();
        return d;
                
    }

    @Override
    public String askForString(String question) {
        showMessage(question);
        return entrada.next();
    }
}
