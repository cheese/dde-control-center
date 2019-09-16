/*
 * Copyright (C) 2011 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     liuhong <liuhong_cm@deepin.com>
 *
 * Maintainer: liuhong <liuhong_cm@deepin.com>
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

#pragma once

#include "window/namespace.h"
#include "widgets/contentwidget.h"
#include "modules/accounts/user.h"
#include "modules/accounts/avatarwidget.h"
#include "widgets/settingsgroup.h"
#include "widgets/nextpagewidget.h"
#include "widgets/switchwidget.h"
#include "avatarlistwidget.h"
#include "modules/accounts/fingermodel.h"

#include <com_deepin_daemon_fprintd_device.h>

DWIDGET_BEGIN_NAMESPACE
class DIconButton;
DWIDGET_END_NAMESPACE

QT_BEGIN_NAMESPACE
class QVBoxLayout;
class QHBoxLayout;
class QPushButton;
class QLabel;
class QLineEdit;
class QEvent;
class QCommandLinkButton;
class QStackedWidget;
QT_END_NAMESPACE

namespace dcc {
namespace account {
class FingerModel;
}
}

using com::deepin::daemon::fprintd::Device;

namespace DCC_NAMESPACE {
namespace accounts {
class AccountsDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AccountsDetailWidget(dcc::accounts::User *user, QWidget *parent = nullptr);
    void initWidgets();
    void initDatas();
    void updateLineEditDisplayStyle();
    void setFingerModel(dcc::accounts::FingerModel *model);
    void setFingerWgtsVisible(bool visible = false);

Q_SIGNALS:
    void requestShowPwdSettings(dcc::accounts::User *user);
    void requestSetAutoLogin(dcc::accounts::User *user, const bool autoLogin);
    void requestNopasswdLogin(dcc::accounts::User *user, const bool nopasswdLogin);
    void requestDeleteAccount(dcc::accounts::User *user, const bool deleteHome);
    void requestBack();
    void requestAddNewAvatar(dcc::accounts::User *user);
    void requestSetAvatar(dcc::accounts::User *user, const QString &filePath);
    void requestDeleteAvatar(dcc::accounts::User *user, const QString &iconPath);
    void requestShowFullnameSettings(dcc::accounts::User *user, const QString &fullname);
    void requestShowFingerSettings(dcc::accounts::User *user);
    void requestAddThumbs(const QString &name, const QString &thumb);
    void requestCleanThumbs(dcc::accounts::User *user);

private Q_SLOTS:
    void deleteUserClicked();
    void onThumbsListChanged(const QList<dcc::accounts::FingerModel::UserThumbs> &thumbs);

private:
    dcc::accounts::User *m_curUser;
    dcc::accounts::AvatarWidget *m_avatar;//账户图片
    QLabel *m_shortnameBtn;//账户名小图标
    QLabel *m_shortName;//账户名
    QLabel *m_fullName;//账户全名
    DTK_WIDGET_NAMESPACE::DIconButton *m_fullnameBtn;//账户全名编辑按钮
    QLineEdit *m_inputLineEdit;//账户全名编辑框
    QStackedWidget *m_mainStackedWidget;
    QPushButton *m_modifyPassword;//修改密码
    QPushButton *m_deleteAccount;//删除账户
    dcc::widgets::SwitchWidget *m_autoLogin;//自动登录
    dcc::widgets::SwitchWidget *m_nopasswdLogin;//无密码登录
    dcc::accounts::FingerModel *m_model;
    dcc::widgets::SettingsGroup *m_listGrp;//指纹列表
    QLabel *m_fingetitleLabel;
    QCommandLinkButton *m_addBtn;
    QCommandLinkButton *m_clearBtn;
    QString m_notUseThumb;
    AvatarListWidget *m_avatarListWidget;//图像列表
};

}   // namespace accounts
}   // namespace dccV20
