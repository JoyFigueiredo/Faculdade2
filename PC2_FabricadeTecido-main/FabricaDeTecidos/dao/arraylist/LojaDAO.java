package trabalhopc2.FabricaDeTecidos.dao.arraylist;

import trabalhopc2.FabricaDeTecidos.dao.IDAO;
import trabalhopc2.FabricaDeTecidos.model.Loja;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LojaDAO implements IDAO<Loja> {

    ArrayList<Loja> lojaLista;

    public LojaDAO() {
        lojaLista = new ArrayList();
    }

    public Loja search(String nome) {
        for (int i = 0; i < lojaLista.size(); i++) {
            if (lojaLista.get(i).getNomeDaLoja().equalsIgnoreCase(nome)) {
                return lojaLista.get(i);
            }
        }
        return null;
    }

    @Override
    public Loja create(Loja loja) {
        if (lojaLista.add(loja)) {
            //indice
            int indice = lojaLista.indexOf(loja);
            loja.setID((long) indice);
            return loja;
        }
        return null;
    }

    @Override
    public ArrayList<Loja> findAll() {
        return lojaLista;
    }

    @Override
    public Loja update(Loja lojaAtualza) {
        return lojaLista.set(lojaAtualza.getID().intValue(), lojaAtualza);
    }

    @Override
    public Loja findById(int id) {
        return lojaLista.get(id);
    }

    @Override
    public Loja findById(long id) {
        return this.findById((int) id);
    }

    @Override
    public ArrayList<Loja> find(Loja loja) {
        ArrayList<Loja> lojaRascunho = new ArrayList();
        for (int i = 0; i < lojaLista.size(); i++) {
            if (lojaLista.get(i).getNomeDaLoja().equals(loja.getNomeDaLoja())) {
                lojaRascunho.add(lojaLista.get(i));
            }
        }
        return lojaRascunho;
    }

    @Override
    public boolean delete(Loja loja) {
        boolean valido = false;
        if (lojaLista.remove(loja)) {
            return valido = true;
        }
        return valido;

    }

}
