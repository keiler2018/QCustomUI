#pragma once

#include "qcustomui_global.h"

#include <QLineEdit>
#include <QWidget>

#include <memory>

namespace Ui
{
class AxisControl;
}

class QCUSTOMUI_EXPORT AxisControl : public QWidget
{
    Q_OBJECT
public:
    explicit AxisControl(QWidget* parent = nullptr);
    ~AxisControl();

private:
    Ui::AxisControl* ui;

    struct Impl;
    std::unique_ptr<Impl> m_impl;
};
