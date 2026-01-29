package model;

public class Mobitel extends model.ITUredaj {
    private int memorija;

    public Mobitel(String naziv, String proizvodjac, double cijena) {
        super(naziv, proizvodjac, cijena);
        this.memorija = memorija;
    }

    public int getMemorija() { return memorija; }
    public void setMemorija(int memorija) { this.memorija = memorija; }

    @Override
    public String getTip() {
        return "Mobitel";
    }
}