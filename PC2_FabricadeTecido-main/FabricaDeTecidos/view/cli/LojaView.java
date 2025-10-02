package trabalhopc2.FabricaDeTecidos.view.cli;

import trabalhopc2.FabricaDeTecidos.model.Loja;
import trabalhopc2.FabricaDeTecidos.view.IViewCrud;
import java.util.List;

public class LojaView extends ViewSimples {

    public Loja create(Loja l) {
        Loja loja = new Loja();

        this.showMessage("Nome da Loja: ");
        loja.setNomeDaLoja(entrada.next());

        this.showMessage(" Nome do Dono da loja: ");
        loja.setDono(entrada.next());

        this.showMessage("CNPJ : (somente digitos)");
        loja.setCNPJ(entrada.next());

        this.showMessage("Email da loja: ");
        loja.setEmail(entrada.next());
        return loja;
    }

    public Loja edit(Loja loja) {

        if (loja != null) {
            this.showMessage("Nome da Loja: ");
            loja.setNomeDaLoja(entrada.next());

            this.showMessage(" Nome do Dono da loja: ");
            loja.setDono(entrada.next());

            this.showMessage("CNPJ : (somente digitos)");
            loja.setCNPJ(entrada.next());

            this.showMessage("Email da loja: ");
            loja.setEmail(entrada.next());

        } else {
            this.showErrorMessage("Nao encontrado.");
        }
        return loja;
    }

    public void list(List<Loja> loja) {
        System.out.println("Listagem de Lojas ");
        for (int i = 0; i < loja.size(); i++) {
            if (loja.get(i) != null) {
                System.out.println("id: " + loja.get(i).getID() + "\t Nome Loja: " + loja.get(i).getNomeDaLoja() + "\t Dono: " + loja.get(i).getDono());
            }
        }
    }

    public String delete() {
        this.showMessage("Qual loja quer deletar: (nome)");
        String nomeDeletar = entrada.next();
        return nomeDeletar;
    }

    public Long find() {
        this.showMessage("Qual Loja procura: (seu id)");
        Long id = entrada.nextLong();
        return id;
    }

    public void read(Loja loja) {
        if (loja == null) {
            this.showErrorMessage("Loja nao existe.");
        } else {
            System.out.println("id" + loja.getID() + "\t Nome Loja: " + loja.getNomeDaLoja() + "\t Dono: " + loja.getDono());
            System.out.println("CNPJ: " + loja.getCNPJ());
        }
    }

}
