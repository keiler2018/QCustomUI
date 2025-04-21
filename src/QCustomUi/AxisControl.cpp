#include "AxisControl.h"

#include <QHoverEvent>
#include <QLineEdit>
#include <QPushButton>
#include <QPainter>
#include <QStyle>
#include <QStyleOption>
#include <QHboxLayout>
#include <QDoubleSpinBox>
#include <UnitLineEdit.h>
#include "ui_AxisControl.h"

struct AxisControl::Impl
{
    QPushButton* yPositiveButton;
    QPushButton* yNegativeButton;
    QPushButton* xPositiveButton;
    QPushButton* xNegativeButton;
    QPushButton* homeButton;

    QPushButton* zPositiveButton;
    QPushButton* zNegativeButton;

    UnitLineEdit* xTargetPosition;
    UnitLineEdit* yTargetPosition;
    UnitLineEdit* zTargetPosition;
    QPushButton* xMoveToButton;
    QPushButton* yMoveToButton;
    QPushButton* zMoveToButton;
};


/*!
    \brief      构造函数 .
*/
AxisControl::AxisControl(QWidget* parent /*= nullptr*/) : QWidget(parent), ui(new Ui::AxisControl),m_impl(std::make_unique<Impl>()) {
    ui->setupUi(this);
}

/*!
    \brief      析构函数.
*/
AxisControl::~AxisControl() {}