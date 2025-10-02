package trabalhopc2.FabricaDeTecidos.model;

public enum OpcaoMenu {

    CRIAR("Criar"),
    EDITAR("Editar"),
    DELETAR("Deletar"),
    PROCURAR("Procurar"),
    LISTAR("Listar"),
    LOJA("Para Loja"),
    TECIDO("Para Tecido"),
    COMPRAR("Para Comprar"),
    VETOR("Vetor"),
    ARRAYLIST("ArrayList"),
    SAIR("Sair");

    private String opcao;

    OpcaoMenu(String opcao) {
        this.opcao = opcao;
    }

    public String getValue() {
        return opcao;
    }
}
