#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>  //Para poder utilizar escenas
#include <QGraphicsItem>  // Para poder utilizar elementos graficos

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena; //Puntero a escena para hacer interfaz entre el QGraphicsView y los elementos graficos

};

#endif // MAINWINDOW_H
