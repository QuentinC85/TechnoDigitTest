#include <test.h>
#include <iostream>



void test::button_test_clicked()
{
    this->launch_test();
}


void test::launch_test()
{
    if(test_connection_widget()==false)
    {
        std::cout << "Test de connection entre les widgets echoues" << std::endl;
    }

}

bool test::test_connection_widget()
{
    QString tempDist = m_ui->Distance_Widget->text();
    QString tempAff = m_ui->Affichage_Distance->text();
    m_ui->Distance_Widget->setText("3.1564 km");
    //Ajouter une méthode qui regroupe les actions nécessaire au changement
    if(m_ui->Affichage_Distance->text() !=m_ui->Distance_Widget->text())
    {
        m_ui->Distance_Widget->setText(tempDist);
        m_ui->Affichage_Distance->setText(tempAff);
        return false;
    }
    m_ui->Distance_Widget->setText(tempDist);
    m_ui->Affichage_Distance->setText(tempAff);
    return true;
}
