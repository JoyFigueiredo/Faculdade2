package Compiladores.src;

import Compiladores.src.Token;
import Compiladores.src.AlgumaLexico;

public class AlgumaLex {
    public static void main(String[] args) {
        AlgumaLexico al = new AlgumaLexico("D:/Faculdade/Compiladores/Compiladores/src/Teste.txt");
        Token t = null;
        while ((t = al.proximoToken()) != null) {
            System.out.print(t);
        }
    }
}
