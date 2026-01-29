package repository;

import model.ITUredaj;
import util.DataGenerator;
import util.FileUtil;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

import static util.DataGenerator.generirajUredaje;

public class UredajRepository {
    private static UredajRepository instance;
    private final List<ITUredaj> uredaji = new ArrayList<>();

    private UredajRepository() {
        // Generiraj podatke jednom pri inicijalizaciji
        uredaji.addAll(generirajUredaje());
    }

    public static UredajRepository getInstance() {
        if (instance == null) {
            instance = new UredajRepository();
        }
        return instance;
    }

    public void dodaj(ITUredaj u) {
        uredaji.add(u);
    }

    public void obrisi(ITUredaj u) {
        uredaji.remove(u);
    }

    public List<ITUredaj> dohvatiSve() {
        return new ArrayList<>(uredaji);
    }

    private final String filePath = "uredaji.ser";


    public void spremi() {
        FileUtil.spremiUFajl(filePath, uredaji);
    }

    public void ucitaj() {
        uredaji.clear();
        uredaji.addAll(FileUtil.ucitajIzFajla(filePath));
    }

    public void inicijaliziraj() {
        File f = new File(filePath);
        if (!f.exists()) {
            generirajUredaje();
            spremi();
        } else {
            ucitaj();
        }
    }



}
