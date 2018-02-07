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

#ifndef THEMEITEMPIC_H
#define THEMEITEMPIC_H

#include <QWidget>

namespace dcc
{
namespace widgets
{
class TranslucentFrame;
}
namespace personalization
{
class ThemeItemPic : public QWidget
{
    Q_OBJECT
public:
    explicit ThemeItemPic(QWidget *parent = 0);
    void setPicPath(const QString &path);

    void paintEvent(QPaintEvent *event);

private:
    QString m_picPath;

};


}
}


#endif // THEMEITEMPIC_H
