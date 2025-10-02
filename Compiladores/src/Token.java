package Compiladores.src;
public class Token {
    public tipoToken tt;
    public String lexema;

    public Token(tipoToken tt, String lexema){
        this.lexema = lexema;
        this.tt = tt;
    }

    @Override
    public String toString(){
        return "<" + tt + ", " + lexema + ">";
    }
    
}
