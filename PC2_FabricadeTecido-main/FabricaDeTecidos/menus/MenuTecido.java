package trabalhopc2.FabricaDeTecidos.menus;

import trabalhopc2.FabricaDeTecidos.controller.TecidoControle;
import trabalhopc2.FabricaDeTecidos.model.OpcaoMenu;
import trabalhopc2.FabricaDeTecidos.view.cli.MenuView;

public class MenuTecido {

    public void MenuTecido() {
        OpcaoMenu[] opcaomenu = {OpcaoMenu.CRIAR, OpcaoMenu.DELETAR, OpcaoMenu.LISTAR,
            OpcaoMenu.EDITAR, OpcaoMenu.PROCURAR, OpcaoMenu.SAIR};

        MenuView menu = new MenuView(opcaomenu);
        TecidoControle tecidoControle = new TecidoControle();

        OpcaoMenu opcao;
        do {
            opcao = menu.getOpcao();
            switch (opcao) {
                case CRIAR:
                    //tecidoControle.create();

                    break;
                case DELETAR:
                   //tecidoControle.delete();
                    break;
                case LISTAR:
                   // tecidoControle.list();
                    break;
                case EDITAR:
                   // tecidoControle.edit();
                    break;
                case PROCURAR:
                   // tecidoControle.search();
                    break;
                case SAIR:
                    break;
            }

        } while (opcao != OpcaoMenu.SAIR);
    }
}
