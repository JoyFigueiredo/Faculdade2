package trabalhopc2.FabricaDeTecidos.menus;

import trabalhopc2.FabricaDeTecidos.controller.LojaControleVetor;
import trabalhopc2.FabricaDeTecidos.model.OpcaoMenu;
import trabalhopc2.FabricaDeTecidos.view.cli.MenuView;

public class MenuLoja {

    public void MenuLoja() {
        OpcaoMenu[] opcaomenu = {OpcaoMenu.CRIAR, OpcaoMenu.DELETAR, OpcaoMenu.LISTAR,
            OpcaoMenu.EDITAR, OpcaoMenu.PROCURAR, OpcaoMenu.SAIR};

        MenuView menu = new MenuView(opcaomenu);
        LojaControleVetor lojaControle = new LojaControleVetor();

        OpcaoMenu opcao;
        do {
            opcao = menu.getOpcao();
            switch (opcao) {
                case CRIAR:
                    lojaControle.create();
                    break;
                case DELETAR:
                    lojaControle.delete(null);
                    break;
                case LISTAR:
                    lojaControle.list();
                    break;
                case EDITAR:
                    lojaControle.update(null);
                    break;
                case PROCURAR:
                    lojaControle.read(null);
                    break;
                case SAIR:
                    break;
            }

        } while (opcao != OpcaoMenu.SAIR);

    }
}
