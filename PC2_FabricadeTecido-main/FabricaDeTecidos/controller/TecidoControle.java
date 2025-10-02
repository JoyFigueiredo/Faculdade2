package trabalhopc2.FabricaDeTecidos.controller;

import trabalhopc2.FabricaDeTecidos.dao.array.TecidoDAOVetor;
import trabalhopc2.FabricaDeTecidos.model.Tecido;
import trabalhopc2.FabricaDeTecidos.view.cli.TecidoView;

public class TecidoControle {

    private TecidoView tela;
    TecidoDAOVetor tecidoDAO;

    public TecidoControle() {
        tela = new TecidoView();
        tecidoDAO = new TecidoDAOVetor();
    }

//    public void list() {
//        Tecido[] listaTecido = tecidoDAO.findAll();
//        tela.list(listaTecido);
//    }
//
//    @Override
//    public Tecido create() {
//        Tecido tecido = tela.create(null);
//        tecidoDAO.createVetor(tecido);
//        return tecido;
//    }
//
//    @Override
//    public void delete() {
//        String nomeDeletar = tela.delete();
//        tecidoDAO.deletar(nomeDeletar);
//    }
//
//    @Override
//    public void search() {
//        String nomeProcurar = tela.search();
//        Tecido tecido = tecidoDAO.search(nomeProcurar);
//        tela.read(tecido);
//    }
//
//    @Override
//    public void edit() {
//        String nomeProcurar = tela.search();
//        Tecido tecido = tecidoDAO.search(nomeProcurar);
//        tela.edit(tecido);
//    }
}
