package Compiladores.src;

public class AlgumaLexico {

    LeitorTexto lt;

    public AlgumaLexico(String arquivo) {
        lt = new LeitorTexto(arquivo);
    }

    public Token proximoToken() {
        //vai ler ate achar um erro
        int caracterLido = -1;
        //Pula o espaço em branco, pois ele não gera token
        while ((caracterLido = lt.lerProximoCaracter()) != -1) {
            char c = (char) caracterLido;
            if (c == ' ' || c == '\n') {
                continue;
            }
            if (c > 31 || c < 127) {
                continue;
            }

            if (c == 'É') {
                return new Token(tipoToken.PONTUACAO, "É");
            } else if (c == 'é') {
                return new Token(tipoToken.PONTUACAO, "é");
            } else {
                lt.retroceder();
                return new Token(tipoToken.PONTUACAO, "é");
            }

        }
        return null;
    }
}
