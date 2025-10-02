package trabalhopc2.FabricaDeTecidos.menus;

import trabalhopc2.FabricaDeTecidos.model.OpcaoMenu;
import trabalhopc2.FabricaDeTecidos.view.cli.MenuView;

public class ProgramaCentralDaFabrica {

    public void ProgramaCentralDaFabrica() {

        OpcaoMenu[] opcao1 = {OpcaoMenu.LOJA, OpcaoMenu.TECIDO,
            OpcaoMenu.COMPRAR, OpcaoMenu.SAIR};

        MenuView menuPrincipal = new MenuView(opcao1);

        OpcaoMenu opcaoP;

        do {
            opcaoP = menuPrincipal.getOpcao();
            switch (opcaoP) {
                case LOJA:
                    MenuLoja menuLoja = new MenuLoja();
                    menuLoja.MenuLoja();
                    break;

                case TECIDO:
                    MenuTecido menuTecido = new MenuTecido();
                    menuTecido.MenuTecido();
                    break;

                case COMPRAR:
                    break;

                case SAIR:
                    break;

            }
        } while (opcaoP != OpcaoMenu.SAIR);
    }

}
