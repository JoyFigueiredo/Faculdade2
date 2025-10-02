package trabalhopc2.FabricaDeTecidos.dao.array;

import trabalhopc2.FabricaDeTecidos.dao.IDAO;
import trabalhopc2.FabricaDeTecidos.model.Tecido;
import java.util.Arrays;
import java.util.List;



public class TecidoDAOVetor implements IDAO<Tecido>{

    private Tecido[] tecidoLista;

    public TecidoDAOVetor() {
        tecidoLista = new Tecido[10];
    }

    @Override
    public Tecido create(Tecido tecido) {
        for (int i = 0; i < tecidoLista.length; i++) {
            if (tecidoLista[i] == null) {
                tecidoLista[i] = tecido;
                return tecido;
            }
        }
        return null;
    }

    @Override
    public List<Tecido> findAll() {
         return Arrays.asList();
    }

    public void deletar(String nome) {
        
    }

    public Tecido search(String nomeTecido) {
        for (int i = 0; i < tecidoLista.length; i++) {
            if (tecidoLista[i] != null && tecidoLista[i].getTipoDeTecido().equals(nomeTecido)) {
                return tecidoLista[i];
            }
        }
        return null;
    }

    @Override
    public boolean delete(Tecido nome) {
        boolean valido = false;
       for (int i = 0; i < tecidoLista.length; i++) {
            if (tecidoLista[i] != null && tecidoLista[i].getTipoDeTecido().equals(nome)) {
                tecidoLista[i] = null;
                return valido =true;
            }
        }
       return valido;
    }

    @Override
    public Tecido update(Tecido t) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public Tecido findById(int id) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public Tecido findById(long id) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public List<Tecido> find(Tecido t) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}
