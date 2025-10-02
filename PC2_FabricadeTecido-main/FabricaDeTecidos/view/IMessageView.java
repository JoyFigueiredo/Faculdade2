
package trabalhopc2.FabricaDeTecidos.view;


public interface IMessageView {
    
    public void showMessage(String msg);    
    public void showErrorMessage(String msg);
    public int askForInt(String question);
    public double askForDouble(String question);
    public String askForString(String question);
    
}
