package trabalhopc2.FabricaDeTecidos.menus;

import trabalhopc2.FabricaDeTecidos.controller.LojaControleArray;
import trabalhopc2.FabricaDeTecidos.controller.LojaControleVetor;
import trabalhopc2.FabricaDeTecidos.model.OpcaoMenu;
import trabalhopc2.FabricaDeTecidos.view.cli.MenuView;

public class MenuArmazenamento {

    public static void main(String[] args) {

        OpcaoMenu[] opcaomenu = {OpcaoMenu.VETOR, OpcaoMenu.ARRAYLIST, OpcaoMenu.SAIR};

        MenuView menu = new MenuView(opcaomenu);
        ProgramaCentralDaFabrica programa = new ProgramaCentralDaFabrica();

        OpcaoMenu opcao;
        do {
            opcao = menu.getOpcao();
            switch (opcao) {
                case ARRAYLIST:

                    break;
                case VETOR:
                    programa.ProgramaCentralDaFabrica();
                    break;
                case SAIR:
                    break;
            }

        } while (opcao != OpcaoMenu.SAIR);

    }
}
