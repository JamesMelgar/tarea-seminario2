/********************************************************************************
** Form generated from reading UI file 'inicio.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_H
#define UI_INICIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inicio
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *txt_entrada;
    QPlainTextEdit *txt_salida;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *gramatica;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *Prueba;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *inicio)
    {
        if (inicio->objectName().isEmpty())
            inicio->setObjectName(QString::fromUtf8("inicio"));
        inicio->resize(840, 559);
        centralWidget = new QWidget(inicio);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 821, 381));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        txt_entrada = new QTextEdit(horizontalLayoutWidget);
        txt_entrada->setObjectName(QString::fromUtf8("txt_entrada"));

        horizontalLayout->addWidget(txt_entrada);

        txt_salida = new QPlainTextEdit(horizontalLayoutWidget);
        txt_salida->setObjectName(QString::fromUtf8("txt_salida"));

        horizontalLayout->addWidget(txt_salida);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 419, 821, 61));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        gramatica = new QPushButton(horizontalLayoutWidget_2);
        gramatica->setObjectName(QString::fromUtf8("gramatica"));

        horizontalLayout_2->addWidget(gramatica);

        pushButton_3 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        Prueba = new QPushButton(horizontalLayoutWidget_2);
        Prueba->setObjectName(QString::fromUtf8("Prueba"));

        horizontalLayout_2->addWidget(Prueba);

        inicio->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(inicio);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 840, 22));
        inicio->setMenuBar(menuBar);
        mainToolBar = new QToolBar(inicio);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        inicio->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(inicio);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        inicio->setStatusBar(statusBar);

        retranslateUi(inicio);

        QMetaObject::connectSlotsByName(inicio);
    } // setupUi

    void retranslateUi(QMainWindow *inicio)
    {
        inicio->setWindowTitle(QApplication::translate("inicio", "inicio", nullptr));
        gramatica->setText(QApplication::translate("inicio", "generar", nullptr));
        pushButton_3->setText(QApplication::translate("inicio", "3D", nullptr));
        pushButton_2->setText(QApplication::translate("inicio", "Abrir", nullptr));
        Prueba->setText(QApplication::translate("inicio", "Prueba", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inicio: public Ui_inicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_H
