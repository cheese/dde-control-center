/*
 * Copyright (C) 2011 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
 *
 * Maintainer: sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PERSONALIZATIONWIDGET_H
#define PERSONALIZATIONWIDGET_H

#include "modulewidget.h"
#include "personalizationmodel.h"
#include "switchwidget.h"
#include <QPushButton>
#include <QVBoxLayout>

namespace dcc
{
namespace widgets {
class SettingsGroup;
}
namespace personalization
{
class PersonalizationWidget : public dcc::ModuleWidget
{
    Q_OBJECT

public:
    explicit PersonalizationWidget();

public slots:
    void setModel(PersonalizationModel *const model);

signals:
    void showThemeWidget();
    void showFontsWidget();
    void requestSwitchWM();

private:
    dcc::widgets::SettingsGroup *m_userGroup;
    dcc::widgets::SwitchWidget *m_wmSwitch;
};
}
}


#endif // PERSONALIZATIONWIDGET_H
