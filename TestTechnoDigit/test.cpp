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
    else
    {
        std::cout << "Test de connection OK" << std::endl;
    }

}

bool test::test_connection_widget()
{
    //On enregistre le contenu des différents labels
    QString tempDist = m_ui->Distance_Widget->text();
    QString tempAff = m_ui->Affichage_Distance->text();

    int index_unit = m_ui->MenuUnit->currentIndex();
    QTest::mouseClick(m_ui->Distance_Widget,Qt::LeftButton);
    QTest::keyClicks(m_ui->Distance_Widget, "3.1564");
    QTest::keyPress(m_ui->Distance_Widget, Qt::Key_Return);
    QTest::keyRelease(m_ui->Distance_Widget, Qt::Key_Return);

    if(m_ui->Affichage_Distance->text() != "The length is " + m_ui->Distance_Widget->text() + " " + QString(QMetaEnum::fromType<unit>().key(index_unit)))
    {
        m_ui->MenuUnit->setCurrentIndex(index_unit);
        m_ui->Distance_Widget->setText(tempDist);
        m_ui->Affichage_Distance->setText(tempAff);
        return false;
    }
    m_ui->MenuUnit->setCurrentIndex(index_unit);
    m_ui->Distance_Widget->setText(tempDist);
    m_ui->Affichage_Distance->setText(tempAff);
    return true;
}
