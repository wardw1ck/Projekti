package model;

public class Monitor extends ITUredaj { private String gpu;

    public Monitor(String naziv, String proizvodjac, double cijena) {
        super(naziv, proizvodjac, cijena);
    }

    public String getGpu() { return gpu; }
    public void setGpu(String gpu) { this.gpu = gpu; }

    @Override
    public String getTip() {
        return "PC";
    }
}