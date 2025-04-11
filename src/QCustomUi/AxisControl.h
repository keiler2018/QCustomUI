#pragma once

#include "qcustomui_global.h"

#include <QLineEdit>
#include <QWidget>

#include <memory>

class QStyleOptionFrame;

class QCUSTOMUI_EXPORT AxisControl : public QWidget
{
    Q_PROPERTY(QString path READ path WRITE setPath)
    Q_PROPERTY(bool readOnly READ readOnly WRITE setReadOnly)
    Q_OBJECT
public:
    explicit AxisControl(QWidget* parent = nullptr);
    ~AxisControl();

    void setPath(QString path);
    QString path() const;
    void setReadOnly(bool flag);
    bool readOnly() const;
    void setLineEdit(QLineEdit* editor);
    QLineEdit* lineEdit() const;
signals:
    void pathChanged(const QString& path);
    void pathClicked(const QString& path);

protected:
    void paintEvent(QPaintEvent* event) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    bool event(QEvent* e) override;
    void resizeEvent(QResizeEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    bool eventFilter(QObject* watched, QEvent* event) override;
    virtual void initStyleOption(QStyleOptionFrame* option) const;
    void cancelEditor();

private:
    void generatorNodes();

private:
    struct Impl;
    std::unique_ptr<Impl> m_impl;
};
