﻿/*********************************************************************************
**                                                                              **
**  Copyright (C) 2019-2025 LiLong                                              **
**  This file is part of QCustomUi.                                             **
**                                                                              **
**  QCustomUi is free software: you can redistribute it and/or modify           **
**  it under the terms of the GNU Lesser General Public License as published by **
**  the Free Software Foundation, either version 3 of the License, or           **
**  (at your option) any later version.                                         **
**                                                                              **
**  QCustomUi is distributed in the hope that it will be useful,                **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of              **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               **
**  GNU Lesser General Public License for more details.                         **
**                                                                              **
**  You should have received a copy of the GNU Lesser General Public License    **
**  along with QCustomUi.  If not, see <https://www.gnu.org/licenses/>.         **
**********************************************************************************/
#pragma once

#include <QDesignerCustomWidgetInterface>

class ClassifyTreeView
    : public QObject
    , public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)
public:
    explicit ClassifyTreeView(QObject* parent = nullptr);

    bool isContainer() const override { return false; }
    bool isInitialized() const override { return m_initialized; }
    QIcon icon() const override { return QIcon(); }
    QString domXml() const override;
    QString group() const override { return "Item Views (Model-Based)"; }
    QString includeFile() const override { return "QCustomUi/QCtmClassifyTreeView.h"; }
    QString name() const override { return "QCtmClassifyTreeView"; }
    QString toolTip() const override { return "QCtmClassifyTreeView"; }
    QString whatsThis() const override { return "QCtmClassifyTreeView"; }
    QWidget* createWidget(QWidget* parent) override;
    void initialize(QDesignerFormEditorInterface* core) override
    {
        if (m_initialized)
            return;
        m_initialized = true;
    }

private:
    bool m_initialized { false };
};
