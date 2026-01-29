module projekt2 {
    requires javafx.controls;
    requires javafx.fxml;

    opens app to javafx.fxml;
    opens model to javafx.base;

    exports app;
}
