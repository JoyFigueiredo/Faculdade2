package trabalhopc2.FabricaDeTecidos.dao.array;

import trabalhopc2.FabricaDeTecidos.dao.IDAO;
import trabalhopc2.FabricaDeTecidos.model.Loja;
import java.util.Arrays;
import java.util.List;

public class LojaDAOVetor implements IDAO<Loja> {

    private Loja[] lojaLista;

    public LojaDAOVetor() {
        lojaLista = new Loja[10];
    }

    @Override
    public Loja create(Loja loja) {
        for (int i = 0; i < lojaLista.length; i++) {
            if (lojaLista[i] == null) {
                lojaLista[i] = loja;
                int indice = i; 
                loja.setID((long) indice);
                return loja;
            }
        }
        return null;
    }

    @Override
    public List<Loja> findAll() {
        return Arrays.asList(lojaLista);
    }

    public Loja search(String nome) {
        for (int i = 0; i < lojaLista.length; i++) {
            if (lojaLista[i] != null && lojaLista[i].getNomeDaLoja().equalsIgnoreCase(nome)) {
                return lojaLista[i];
            }
        }
        return null;
    }

    @Override
    public boolean delete(Loja t) {
        boolean valido = false;
        for (int i = 0; i < lojaLista.length; i++) {
            if (lojaLista[i] != null && lojaLista[i].getNomeDaLoja().equals(t.getNomeDaLoja())) {
                lojaLista[i] = null;
                return valido = true;
            }
        }
        return valido;
    }

    @Override
    public Loja update(Loja lojaAtualiza) {
        for (int i = 0; i < lojaLista.length; i++) {
            if (lojaLista[i] != null && lojaLista[i].equals(lojaAtualiza)) {
                lojaLista[i] = lojaAtualiza;
                return lojaAtualiza;
            }
        }
        return null;
    }

    @Override
    public Loja findById(int id) {
        for (int i = 0; i < lojaLista.length; i++) {
            if (lojaLista[i] != null && lojaLista[i].getID() == id) {
                return lojaLista[i];
            }
        }
        return null;
    }

    @Override
    public Loja findById(long id) {
        return this.findById((int)id);
    }

    @Override
    public List<Loja> find(Loja loja) {
        Loja[] lojaRascunho = new Loja[10];
        int k = 0;
        for (int i = 0; i < lojaLista.length; i++) {
            if (lojaLista[i] != null && lojaLista[i].getNomeDaLoja().equals(loja.getNomeDaLoja())) {
                lojaRascunho[k] = lojaLista[i];
                k++;
            }
        }
        return Arrays.asList(lojaRascunho);
    }
}
