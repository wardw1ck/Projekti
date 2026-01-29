package model;

public class Laptop extends ITUredaj {
    private int baterija;

    public Laptop(String naziv, String proizvodjac, double cijena) {
        super(naziv, proizvodjac, cijena);
        this.baterija = baterija;
    }

    public int getBaterija() { return baterija; }
    public void setBaterija(int baterija) { this.baterija = baterija; }

    @Override
    public String getTip() {
        return "Laptop";
    }
}
