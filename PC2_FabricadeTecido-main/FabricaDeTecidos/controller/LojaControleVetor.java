package trabalhopc2.FabricaDeTecidos.controller;

import trabalhopc2.FabricaDeTecidos.dao.array.LojaDAOVetor;
import trabalhopc2.FabricaDeTecidos.model.Loja;
import trabalhopc2.FabricaDeTecidos.view.cli.LojaView;
import java.util.Arrays;
import java.util.List;

public class LojaControleVetor implements IControleSimples<Loja>{

    private LojaView tela;
    LojaDAOVetor lojaDAO;

    public LojaControleVetor() {
        tela = new LojaView();
        lojaDAO = new LojaDAOVetor();
    }

    @Override
    public Loja create() {
        Loja loja = tela.create(null);
        lojaDAO.create(loja);
        return loja;
    }

    public void list() {
        List<Loja> listaLoja = lojaDAO.findAll();
        tela.list(listaLoja);
    }

    @Override
    public boolean delete(Loja l) {
        String nome = tela.delete();
        Loja loja = lojaDAO.search(nome);

        return lojaDAO.delete(loja);
    }

    @Override
    public void read(Loja l) {
        Long id = tela.find();
        Loja loja = lojaDAO.findById(id);
        tela.read(loja);
    }

    @Override
    public Loja update(Loja l) {
        int id = tela.askForInt("Quem para alterar: (id)");
        Loja loja = lojaDAO.findById(id);
        return tela.edit(loja);

    }

    @Override
    public void showInicialScreen() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void print() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public List<Loja> getAll() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public boolean filter(String column, String valor) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public Loja getAObject() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

}
