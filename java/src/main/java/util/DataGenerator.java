// util/DataGenerator.java
package util;

import model.*;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class DataGenerator {
    public static List<ITUredaj> generirajUredaje() {
        List<ITUredaj> lista = new ArrayList<>();
        Random rand = new Random();

        for (int i = 1; i <= 3; i++) {
            lista.add(new Laptop("Laptop" + i, "Dell", rand.nextDouble(500, 1500)));
            lista.add(new Mobitel("Mobitel" + i, "Samsung", rand.nextDouble(300, 1000)));
            lista.add(new Monitor("Monitor" + i, "LG", rand.nextDouble(200, 800)));
        }

        return lista;
    }
}
