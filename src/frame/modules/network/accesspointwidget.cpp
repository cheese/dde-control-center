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

#include "accesspointwidget.h"
#include "widgets/labels/normallabel.h"

#include <QVBoxLayout>
#include <QDebug>

#include <dimagebutton.h>
#include <dhidpihelper.h>

DWIDGET_USE_NAMESPACE

using namespace dcc::widgets;
using namespace dcc::network;

AccessPointWidget::AccessPointWidget(QWidget *parent)
    : SettingsItem(parent),

      m_lockIcon(new QLabel),
      m_strengthIcon(new QLabel),
      m_apName(new NormalLabel),
      m_activeIcon(new DImageButton),
      m_detailBtn(new DImageButton),

      m_mainLayout(new QVBoxLayout),

      m_strength(-1),
      m_encrypt(false),
      m_connected(false)
{
    m_lockIcon->setFixedSize(16, 16);
    m_strengthIcon->setFixedSize(16, 16);
    m_activeIcon->setFixedSize(16, 16);
    m_activeIcon->setVisible(false);
    m_activeIcon->setNormalPic(":/network/themes/dark/icons/select.svg");
    m_detailBtn->setObjectName("DetailButton");

    QHBoxLayout *basicInfoLayout = new QHBoxLayout;
    basicInfoLayout->addWidget(m_lockIcon);
    basicInfoLayout->addWidget(m_strengthIcon);
    basicInfoLayout->addWidget(m_apName);
    basicInfoLayout->addStretch();
    basicInfoLayout->addWidget(m_activeIcon);
    basicInfoLayout->addWidget(m_detailBtn);
    basicInfoLayout->setSpacing(5);
    basicInfoLayout->setContentsMargins(0, 5, 0, 5);

    m_mainLayout->addLayout(basicInfoLayout);
    m_mainLayout->setSpacing(0);
    m_mainLayout->setContentsMargins(20, 0, 10, 0);

    setLayout(m_mainLayout);
    setObjectName("AccessPointWidget");

    connect(m_detailBtn, &DImageButton::clicked, [=] { Q_EMIT requestEdit(m_path, m_apName->text()); });
}

void AccessPointWidget::setEncrypt(const bool encrypt)
{
    m_encrypt = encrypt;

    if (!encrypt)
        m_lockIcon->clear();
    else
        m_lockIcon->setPixmap(DHiDPIHelper::loadNxPixmap(":/network/themes/dark/icons/wireless/security.svg"));
}

void AccessPointWidget::setAPName(const QString &name)
{
    m_apName->setText(name);
}

void AccessPointWidget::setPath(const QString &path)
{
    m_path = path;
}

void AccessPointWidget::mouseReleaseEvent(QMouseEvent *e)
{
    SettingsItem::mouseReleaseEvent(e);

    if (!m_connected)
        Q_EMIT requestConnect(m_path, m_apName->text());
}

void AccessPointWidget::setStrength(const int strength)
{
    m_strength = strength;

    if (m_strength < 0)
        m_strength = 0;

    const QString iconName = QString(":/network/themes/dark/icons/wireless/wireless-%1-symbolic.svg").arg(strength / 10 & ~1);
    m_strengthIcon->setPixmap(DHiDPIHelper::loadNxPixmap(iconName));
}

void AccessPointWidget::setConnected(const bool connected)
{
    m_connected = connected;

    m_activeIcon->setVisible(m_connected);
}

void AccessPointWidget::setEditable(const bool editable)
{
    m_detailBtn->setVisible(editable);
}
