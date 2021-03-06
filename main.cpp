#include "gestionprojet.h"
#include "agenda.h"
#include "mainwindow.h"
#include "fenajoutereve.h"
#include "iostream"
#include "sstream"
#include <QCoreApplication>
#include <QApplication>


///EXEMPLE: ui->lineEdit_titre->accessibleDescription();
///Pour recuperer la valeur entree je pense :)


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    try{
    QTime d1=QTime(3,0);
    QDate date1= QDate(1925,7,3);
    QDate date2= QDate (1925,11,3);
    //TacheUnitaire* tU1 = new TacheUnitaire("112","Assembler la charpente",d1,date1,date2,false);
    //TacheComposite* tc1 = new TacheComposite("lid","manger");
    Projet* p = new Projet("0","Construire une maison","C'est pas très dur");
    TacheManager::getInstance().addItem(p);
    TacheManager::getInstance().getTache("0").ajouterTacheUnitaire("1","Faire les courses chez castorama",d1,date1,date2,false);
    TacheManager::getInstance().getTache("0").ajouterTacheComposite("2","Assembler les morceaux");
    TacheManager::getInstance().getTache("0").ajouterTacheUnitaire("3","Obtenir un permis de construire",d1,date1,date2,false);
    TacheManager::getInstance().getTache("2").ajouterTacheUnitaire("12","Assembler la charpente",d1,date1,date2,false);
    TacheManager::getInstance().getTache("2").ajouterTacheComposite("11","Assembler les briques");
    TacheManager::getInstance().getTache("11").ajouterTacheUnitaire("111","Mettre du ciment",d1,date1,date2,false);
    TacheManager::getInstance().getTache("11").ajouterTacheUnitaire("112","Poser sa brique",d1,date1,date2,false);
    TacheManager::getInstance().getTache("11").ajouterTacheUnitaire("113","Attendre le sechage",d1,date1,date2,false);
    dynamic_cast<TacheUnitaire*>(&TacheManager::getInstance().getTache("112"))->ajouterTachePrecedente(&TacheManager::getInstance().getTache("113"));
    TacheManager::getInstance().save("test1.xml","0");
    TacheManager::getInstance().creerTreeModel("Arbre.txt","0");
    MainWindow w;
    w.show();

    }
    catch (CalendarException &e){std::cout<<"Exception levee"<<e.getInfo().toStdString();}
    return a.exec();
    a.closeAllWindows();
}
