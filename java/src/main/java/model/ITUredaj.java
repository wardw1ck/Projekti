package model;

import java.io.Serializable;

public abstract class ITUredaj implements Elektronika, Serializable {
    protected String naziv;
    protected String proizvodjac;
    protected double cijena;

    public ITUredaj(String naziv, String proizvodjac, double cijena) {
        this.naziv = naziv;
        this.proizvodjac = proizvodjac;
        this.cijena = cijena;
    }

    public abstract String getTip();

    public String getNaziv() { return naziv; }
    public String getProizvodjac() { return proizvodjac; }
    public double getCijena() { return cijena; }

    public void setNaziv(String naziv) { this.naziv = naziv; }
    public void setProizvodjac(String proizvodjac) { this.proizvodjac = proizvodjac; }
    public void setCijena(double cijena) { this.cijena = cijena; }

    @Override
    public void ukljuci() {
        System.out.println(naziv + " je uključen.");
    }

    @Override
    public String toString() {
        return getTip() + ": " + naziv + ", " + proizvodjac + ", " + cijena + " EUR";
    }
}
