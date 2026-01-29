// ui/MainApp.java
package app;


import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;
import model.*;
import repository.UredajRepository;

import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

public class MainApp extends Application {
    private TableView<ITUredaj> tableView;
    private ObservableList<ITUredaj> uredaji;
    private final UredajRepository repository = UredajRepository.getInstance();

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Inventar IT Uređaja");

        repository.inicijaliziraj();
        repository.ucitaj();
        uredaji = FXCollections.observableArrayList(repository.dohvatiSve());

        tableView = new TableView<>(uredaji);
        TableColumn<ITUredaj, String> nazivCol = new TableColumn<>("Naziv");
        nazivCol.setCellValueFactory(new PropertyValueFactory<>("naziv"));

        TableColumn<ITUredaj, String> proizvodjacCol = new TableColumn<>("Proizvođač");
        proizvodjacCol.setCellValueFactory(new PropertyValueFactory<>("proizvodjac"));

        TableColumn<ITUredaj, Double> cijenaCol = new TableColumn<>("Cijena");
        cijenaCol.setCellValueFactory(new PropertyValueFactory<>("cijena"));

        TableColumn<ITUredaj, String> kategorijaCol = new TableColumn<>("Kategorija");
        kategorijaCol.setCellValueFactory(new PropertyValueFactory<>("tip"));

        tableView.getColumns().addAll(nazivCol, proizvodjacCol, cijenaCol, kategorijaCol);

        TextField nazivField = new TextField();
        nazivField.setPromptText("Naziv uređaja");

        TextField proizvodjacField = new TextField();
        proizvodjacField.setPromptText("Proizvođač");

        TextField cijenaField = new TextField();
        cijenaField.setPromptText("Cijena");

        ComboBox<String> tipCombo = new ComboBox<>();
        tipCombo.getItems().addAll("Laptop", "Mobitel", "Monitor");
        tipCombo.setValue("Laptop");

        Button dodajBtn = new Button("Dodaj");
        dodajBtn.setOnAction(e -> {
            try {
                String naziv = nazivField.getText();
                String proizvodjac = proizvodjacField.getText();
                double cijena = Double.parseDouble(cijenaField.getText());
                String tip = tipCombo.getValue();
                Elektronika el = () -> System.out.println("Nešto");

                ITUredaj novi;
                switch (tip) {
                    case "Mobitel" -> novi = new Mobitel(naziv, proizvodjac, cijena);
                    case "Monitor" -> novi = new Monitor(naziv, proizvodjac, cijena);
                    default -> novi = new Laptop(naziv, proizvodjac, cijena);
                }

                repository.dodaj(novi);
                osvjezi();
            } catch (NumberFormatException ex) {
                showAlert("Greška", "Cijena mora biti broj.");
            }
        });

        Button obrisiBtn = new Button("Obriši");
        obrisiBtn.setOnAction(e -> {
            String naziv = nazivField.getText();
            Optional<ITUredaj> target = repository.dohvatiSve()
                    .stream()
                    .filter(u -> u.getNaziv().equalsIgnoreCase(naziv))
                    .findFirst();
            target.ifPresent(repository::obrisi);
            osvjezi();
        });

        Button filtrirajBtn = new Button("Filter < 1000");
        filtrirajBtn.setOnAction(e -> {
            List<ITUredaj> filtrirano = repository.dohvatiSve().stream()
                    .filter(u -> u.getCijena() < 1000)
                    .collect(Collectors.toList());
            uredaji.setAll(filtrirano);
        });

        Button spremiBtn = new Button("Spremi");
        spremiBtn.setOnAction(e -> {
            repository.spremi();
            showAlert("Info", "Podaci su spremljeni.");
        });

        HBox akcije = new HBox(10, nazivField, proizvodjacField, cijenaField, tipCombo, dodajBtn, obrisiBtn, filtrirajBtn, spremiBtn);

        BorderPane root = new BorderPane();
        root.setCenter(tableView);
        root.setBottom(akcije);

        Scene scene = new Scene(root, 1000, 550);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void osvjezi() {
        uredaji.setAll(repository.dohvatiSve());
    }

    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
