package trabalhopc2.FabricaDeTecidos.dao.arraylist;

import trabalhopc2.FabricaDeTecidos.dao.IDAO;
import trabalhopc2.FabricaDeTecidos.model.Tecido;
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

public class TecidoDAO implements IDAO<Tecido> {

    ArrayList<Tecido> tecidoLista;
    //private Tecido[] tecidoLista;

    public TecidoDAO() {
        tecidoLista = new ArrayList();
        //tecidoLista = new Tecido[10];
    }

    public void createVetor(Tecido tecido) {
//        
////        for (int i = 0; i < tecidoLista.length; i++) {
////            if (tecidoLista[i] == null) {
////                tecidoLista[i] = tecido;
////                break;
////            }
////        }
    }

    @Override
    public List<Tecido> findAll() {
        return Arrays.asList();
    }

    public void deletar(String nome) {
//        for (int i = 0; i < tecidoLista.length; i++) {
//            if (tecidoLista[i] != null && tecidoLista[i].getTipoDeTecido().equals(nome)) {
//                tecidoLista[i] = null;
//                break;
//            }
//        }
    }
//

    public Tecido search(String nomeTecido) {
//        for (int i = 0; i < tecidoLista.length; i++) {
//            if (tecidoLista[i] != null && tecidoLista[i].getTipoDeTecido().equals(nomeTecido)) {
//                return tecidoLista[i];
//            }
//        }
        return null;
    }

    @Override
    public Tecido create(Tecido tecido) {
        if (tecidoLista.add(tecido)) {
            int indice = tecidoLista.indexOf(tecido);
            tecido.setID((long) indice);
            return tecido;
        }
        return null;
    }

    @Override
    public boolean delete(Tecido tecido) {
        boolean valido = false;
        if (tecidoLista.remove(tecido)) {
            return valido = true;
        }
        return valido;
    }

    @Override
    public Tecido update(Tecido tecidoAtualiza) {
        tecidoLista.set(tecidoAtualiza.getID().intValue(), tecidoAtualiza);

        return null;
    }

    @Override
    public Tecido findById(int id) {
        return tecidoLista.get(id);
    }

    @Override
    public Tecido findById(long id) {
        return this.findById(id);
    }

    @Override
    public List<Tecido> find(Tecido tecido) {
        Tecido VetorTecido[] = new Tecido[10];

        return null;
    }
}
