package trabalhopc2.FabricaDeTecidos.view.cli;

import trabalhopc2.FabricaDeTecidos.model.Tecido;
import trabalhopc2.FabricaDeTecidos.view.IViewCrud;

public class TecidoView extends ViewSimples implements IViewCrud<Tecido>{

    @Override
    public Tecido create(Tecido l) {
        Tecido tecido = new Tecido();

        this.showMessage("Qual Malha: ");
        tecido.setMalha(entrada.next());

        this.showMessage(" Tipo de Tecido: ");
        tecido.setTipoDeTecido(entrada.next());

        this.showMessage("Preço : (somente digitos)");
        tecido.setPreco(entrada.nextDouble());

        this.showMessage("Tamanho: ");
        tecido.setTamanho(entrada.nextDouble());
        return tecido;
    }

    @Override
    public void list(Tecido[] tecido) {
        System.out.println("Listagem de Tecidos ");
        for (int i = 0; i < tecido.length; i++) {
            if (tecido[i] != null) {
                System.out.println(tecido[i].getMalha() + " " + tecido[i].getTipoDeTecido());
            }
        }
    }

    @Override
    public String delete() {
        this.showMessage("Qual Tipo de Tecido quer deletar: ");
        String nomeDeletar = entrada.next();
        return nomeDeletar;
    }

    @Override
    public String search() {
        this.showMessage("Qual Tipo de Tecido Procura: ");
        String nomeTecido = entrada.next();
        return nomeTecido;
    }

    @Override
    public void read(Tecido tecido) {
        if (tecido == null) {
            this.showErrorMessage("Loja nao existe.");
        } else {
            System.out.println("Tipo do Tecido: " + tecido.getTipoDeTecido() + "/n Malha: " + tecido.getMalha());
            System.out.println("Preco : " + tecido.getPreco());
        }
    }

    @Override
    public Tecido edit(Tecido t) {
        if (t == null) {
            this.showErrorMessage("Nao encontrado.");
        } else {
            this.showMessage("Qual Malha: ");
            t.setMalha(entrada.next());

            this.showMessage(" Tipo de Tecido: ");
            t.setTipoDeTecido(entrada.next());

            this.showMessage("Preço : (somente digitos)");
            t.setPreco(entrada.nextDouble());

            this.showMessage("Tamanho: ");
            t.setTamanho(entrada.nextDouble());

        }
        return t;
    }
}
