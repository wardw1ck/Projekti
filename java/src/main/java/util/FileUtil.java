// util/FileUtil.java
package util;

import model.ITUredaj;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class FileUtil {

    public static void spremiUFajl(String path, List<ITUredaj> lista) {
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(path))) {
            out.writeObject(new ArrayList<>(lista));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static List<ITUredaj> ucitajIzFajla(String path) {
        File file = new File(path);
        if (!file.exists()) {
            return new ArrayList<>();
        }
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream(file))) {
            Object obj = in.readObject();
            if (obj instanceof List<?>) {
                return (List<ITUredaj>) obj;
            }
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
        return new ArrayList<>();
    }
}
