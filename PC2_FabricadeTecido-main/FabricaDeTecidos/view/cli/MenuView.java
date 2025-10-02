package trabalhopc2.FabricaDeTecidos.view.cli;

import trabalhopc2.FabricaDeTecidos.model.OpcaoMenu;

public class MenuView extends ViewSimples {

    OpcaoMenu opcoesMenu[];
    

    public MenuView(OpcaoMenu[] opcoes) {
        this.opcoesMenu = opcoes;
    }

    public OpcaoMenu getOpcao() {

        OpcaoMenu escolha;

        //do{
        for (int i = 0; i < opcoesMenu.length; i++) {
            showMessage(i + " - " + opcoesMenu[i].getValue());
        }
        int numero = askForInt("Escolha uma Opção");

        //}while 
        escolha = opcoesMenu[numero];
        return escolha;

    }
}
