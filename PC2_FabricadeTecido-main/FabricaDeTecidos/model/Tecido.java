/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalhopc2.FabricaDeTecidos.model;

/**
 *
 * @author aluno
 */
public class Tecido {

    private String tipoDeTecido;
    private String malha;
    private double preco;
    private double tamanho;
    private Long id;

    public Tecido() {

    }

    public Tecido(String tipoDeTecido, String malha) {
        this.tipoDeTecido = tipoDeTecido;
        this.malha = malha;
    }

    public Tecido(int id, String tipoDeTecido, String malha, double preco) {
        this.tipoDeTecido = tipoDeTecido;
        this.malha = malha;
        this.preco = preco;
    }

    public void setTipoDeTecido(String tipo) {
        this.tipoDeTecido = tipo;
    }

    public void setMalha(String malha) {
        this.malha = malha;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public void setTamanho(double tamanho) {
        this.tamanho = tamanho;
    }

    public String getTipoDeTecido() {
        return tipoDeTecido;
    }

    public String getMalha() {
        return malha;
    }

    public double getPreco() {
        return preco;
    }

    public double getTamanho() {
        return tamanho;
    }

    public void setID(Long id) {
        this.id = id;
    }

    public Long getID() {
        return id;
    }

    @Override
    public int hashCode() {
        int hash = 0;
        hash += (id != null ? id.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof Tecido)) {
            return false;
        }
        Tecido other = (Tecido) object;
        if ((this.id == null && other.id != null) || (this.id != null && !this.id.equals(other.id))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "Tecido: " + this.getTipoDeTecido() + "Malha: " + this.getMalha();

    }
}
