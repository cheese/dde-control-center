#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QColor>
#include <QString>
#include <QEasingCurve>

namespace DCC {

static const uint SideBarWidth = 48;

static const QColor BgLightColor = "#252627";
static const QColor BgDarkColor = "#1A1B1B";

static const QColor TextNormalColor = "#b4b4b4";
static const QColor TextHoverColor = "#ffffff";

static const uint ControlCenterWidth = 360;

static const uint HomeScreen_TopWidgetHeight = 150;
static const uint HomeScreen_BottomWidgetHeight = 86;

static const uint FrameAnimationDuration = 300;
static const QEasingCurve FrameShowCurve = QEasingCurve::InQuart;
static const QEasingCurve FrameHideCurve = QEasingCurve::OutQuart;

static const uint TipsMoveAnimationDuration = 200;
static const QEasingCurve TipsMoveCurve = QEasingCurve::OutCubic;

static const QString IconPath = ":/resources/images/";
}

#endif // CONSTANTS_H

