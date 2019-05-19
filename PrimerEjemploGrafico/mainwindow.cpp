#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(600,600);        //Reajustando el tamanio del objeto QGraphicsView a 600x600 pixeles
    this->setFixedSize(600,600);  //Fijando el tamanio para que no se vaya a reajustar automaticamente

    escena = new QGraphicsScene();  //Reservando memoria al puntero escena de tipo QGraphicsScene
    ui->fondo->setScene(escena);  //Relacionando la escena al objeto QGraphicsView

    escena->setSceneRect(-250,-250,500,500); //Creando el rectangulo que encierra la escena
                                             //Coordenadas (x,y) de la esquina superior del rectangulo
                                             //Dimensiones ancho y alto del rectangulo

    escena->addLine(-250,0,250,0,QPen(Qt::red));  //Pintando una linea en la escena (x1,y1,x2,y2,color)
    escena->addLine(0,-250,0,250,QPen(Qt::blue)); //Pintando una linea en la escena (x1,y1,x2,y2,color)

    QGraphicsRectItem *rectangulo; //Declarando el puntero que almacenara el rectangulo

    rectangulo = escena->addRect(-150, -150, 90, 90, QPen(Qt::blue), QBrush(Qt::red)); //Agregando el elemento grafico
                                                                                       // a la escena

    QGraphicsEllipseItem *elipse; //Declarando el puntero que almacenara la elipse

    elipse = escena->addEllipse(70,-150 , 100, 65, QPen(Qt::cyan), QBrush(Qt::yellow)); //Agregando el elemento grafico
    // a la escena

    QGraphicsPolygonItem *poligono;  //Declarando el puntero que almacenara el poligono

    QPolygon polygon;   //Declaracion de un objeto QPolygon
    polygon << QPoint(-175,175) << QPoint(-225,225)<< QPoint(-125,225);
 // Con el operador << se agregan al vector las coordenadas QPoint de los puntos
                                                                 // que al conectarse forman el poligono. Se debe tener cuidado en el orden de los
                                                                 //puntos, ya que cada punto se conecta al anterior y el ultimo se conecta al primero
                                                                 //para cerrar el poligono. De eso depende que el trazo del poligono sea el deseado

    poligono = escena->addPolygon(polygon, QPen(Qt::green), QBrush(Qt::blue)); //Agregando el elemento grafico
    // a la escena

    QGraphicsPolygonItem *poligono1;  //Declarando el puntero que almacenara el poligono

    QPolygon polygon1;   //Declaracion de un objeto QPolygon
    polygon1 << QPoint(100,80) << QPoint(120,100)<< QPoint(120,120)<< QPoint(80,120)<< QPoint(80,100);
 // Con el operador << se agregan al vector las coordenadas QPoint de los puntos
                                                                 // que al conectarse forman el poligono. Se debe tener cuidado en el orden de los
                                                                 //puntos, ya que cada punto se conecta al anterior y el ultimo se conecta al primero
                                                                 //para cerrar el poligono. De eso depende que el trazo del poligono sea el deseado

    poligono = escena->addPolygon(polygon1, QPen(Qt::gray), QBrush(Qt::green)); //Agregando el elemento grafico
    // a la escena
}

MainWindow::~MainWindow()
{
    delete ui;
}
