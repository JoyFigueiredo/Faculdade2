package trabalhopc2.FabricaDeTecidos.controller;

import java.util.List;

public interface IControleSimples<T> {
    
    public void showInicialScreen();

    public T        create();
    public void     read(T objeto);
    public T        update(T objeto);    
    public boolean  delete(T objeto);
    
    public void print(); 
    
    //A serem usados com integração com Grid
    public List<T> getAll();
    
    public boolean  filter(String column, String valor);
    public T        getAObject();    
}
