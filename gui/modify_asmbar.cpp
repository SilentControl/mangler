#include "modify_asmbar.hpp"
#include <QHBoxLayout>

ModifyASMBar::ModifyASMBar(QWidget *parent) : QWidget(parent)
{
    modify = new QLabel(QString("Modify:"), this);
    text = new QTextEdit(this);
    ok = new QPushButton(QString("OK"), this);

    text->setMaximumHeight(40);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(modify);
    layout->addWidget(text);
    layout->addWidget(ok);
    setLayout(layout);
    setMaximumHeight(80);
}

