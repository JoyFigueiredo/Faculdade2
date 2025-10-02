package Compiladores.src;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.logging.Logger;

public class LeitorTexto {

    private final static int TAMANHO_BUFFER = 20;
    int[] bufferDeLeitura;
    int ponteiro;
    int bufferAtual;
    int inicioLexema;
    private String lexema;

    InputStream is;

    public LeitorTexto(String arquivo) {
        try {
            is = new FileInputStream(new File(arquivo));
            inicializarBuffer(); // Zera o ponteiro e declarar o array 
        } catch (FileNotFoundException e) {
            Logger.getLogger(LeitorTexto.class.getName()).severe("Arquivo não encontrado");
        }
    }

    private void inicializarBuffer() {
        bufferAtual = 2;
        inicioLexema = 0;
        lexema = "";
        bufferDeLeitura = new int[TAMANHO_BUFFER * 2];
        ponteiro = 0;
        recarregarBuffer1();
    }

    private void incrementarPonteiro() {
        ponteiro++;
        if (ponteiro == TAMANHO_BUFFER) {
            recarregarBuffer2();
        } else if (ponteiro == TAMANHO_BUFFER * 2) {
            recarregarBuffer1();
            ponteiro = 0;
        }
    }

    private void recarregarBuffer1() {
        if (bufferAtual == 2) {
            bufferAtual = 1;
            try {
                for (int i = 0; i < TAMANHO_BUFFER; i++) {
                    bufferDeLeitura[i] = is.read();
                    if (bufferDeLeitura[i] == -1) {
                        break;
                    }
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    private void recarregarBuffer2() {
        if (bufferAtual == 1) {
            bufferAtual = 2;
            try {
                for (int i = TAMANHO_BUFFER; i < TAMANHO_BUFFER * 2; i++) {
                    bufferDeLeitura[i] = is.read();
                    if (bufferDeLeitura[i] == -1) {
                        break;
                    }
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public int lerProximoCaracter() {
        int ret = lerCaracterBuffer();
        lexema += (char) ret;
        return ret;
    }

    public int lerCaracterBuffer() {
        int ret = bufferDeLeitura[ponteiro];
        System.out.println(this);
        incrementarPonteiro();
        return ret;
    }

    //Codigo para saltar o caracter que não esta na linguagem
    public void retroceder() {
        ponteiro--;
        lexema = lexema.substring(0, lexema.length() - 1);
        if (ponteiro < 0) {
            recarregarBuffer2();
            ponteiro = (TAMANHO_BUFFER * 2) - 1;
        }
    }

    public void zerar() {
        iniciolezema = ponteiro;
        lexema = "";
    }

    public void confirmar() { //confirmar o lexema
        iniciolezema = ponteiro;
        lexema = "";
    }

    //pegar o original
    public String getLexema() {
        return lexema;
    }

    @Override
    public String toString() {
        String ret = "Buffer: ";
        for (int i : bufferDeLeitura) {
            char c = (char) i;
            if (Character.isWhitespace(c)) {
                ret += " ";
            } else {
                ret += (char) i;
            }
        }
        ret += "\n";
        ret += "          ";
        for (int i = 0; i < ponteiro; i++) {
            ret += " ";
        }
        return lexema;
    }
}
