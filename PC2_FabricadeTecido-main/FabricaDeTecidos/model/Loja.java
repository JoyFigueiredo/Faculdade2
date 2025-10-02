/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalhopc2.FabricaDeTecidos.model;

/**
 *
 * @author Joice
 */
public class Loja {

    private static final long serialVersionUID = 1L;
    
    private Long id;
    private String Dono;
    private String nomeDaLoja;
    private String CNPJ;
    private String email;
    private String senha;

    public Loja() {
    }

    public Loja(Long id) {
        this.id = id;
    }

    public Loja(String dono) {
        this.Dono = dono;
    }

    public Loja(String dono, String nomeDaLoja) {
        this.Dono = dono;
        this.nomeDaLoja = nomeDaLoja;
    }

    public Loja(String dono, String nomeDaLoja, String CNPJ, String email) {
        this.Dono = dono;
        this.nomeDaLoja = nomeDaLoja;
        this.CNPJ = CNPJ;
        this.email = email;
    }

    public void setDono(String dono) {
        this.Dono = dono;
    }

    public void setNomeDaLoja(String nome) {
        this.nomeDaLoja = nome;
    }

    public boolean setCNPJ(String CNPJ) {
        this.CNPJ = CNPJ;
        return true;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getDono() {
        return Dono;
    }

    public String getNomeDaLoja() {
        return nomeDaLoja;
    }

    public String getCNPJ() {
        return CNPJ;
    }

    public String getEmail() {
        return email;
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
        if (!(object instanceof Loja)) {
            return false;
        }
        Loja other = (Loja) object;
        if ((this.id == null && other.id != null) || (this.id != null && !this.id.equals(other.id))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "Nome da Loja: " + this.getNomeDaLoja() + " CNPJ: " + this.CNPJ;
    }
}
