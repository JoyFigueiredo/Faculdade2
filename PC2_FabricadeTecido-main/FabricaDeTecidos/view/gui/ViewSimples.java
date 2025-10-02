package trabalhopc2.FabricaDeTecidos.view.gui;


import trabalhopc2.FabricaDeTecidos.view.IMessageView;
import javax.swing.JOptionPane;

public class ViewSimples implements IMessageView{

    @Override
    public void showMessage(String msg){
        JOptionPane.showMessageDialog(null, msg);
    }
    
    @Override
    public void showErrorMessage(String msg) {
        JOptionPane.showMessageDialog(null, "Erro: "+msg);
    }

    @Override
    public int askForInt(String question) {
        String answer = JOptionPane.showInputDialog(question);
        return Integer.parseInt(answer);
               
    }

    @Override
    public double askForDouble(String question) {
        String answer = JOptionPane.showInputDialog(question);
        return Double.parseDouble(answer);
               
    }

    @Override
    public String askForString(String question) {
        String answer = JOptionPane.showInputDialog(question);
        return answer;
               
    }

}
