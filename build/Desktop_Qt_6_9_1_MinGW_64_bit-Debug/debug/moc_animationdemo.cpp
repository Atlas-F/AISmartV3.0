/****************************************************************************
** Meta object code from reading C++ file 'animationdemo.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../animationdemo.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'animationdemo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN13AnimationDemoE_t {};
} // unnamed namespace

template <> constexpr inline auto AnimationDemo::qt_create_metaobjectdata<qt_meta_tag_ZN13AnimationDemoE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "AnimationDemo",
        "slideAnimation",
        "",
        "QWidget*",
        "target",
        "startRect",
        "endRect",
        "duration",
        "AnimationCallback",
        "callback",
        "fadeAnimation",
        "fadeIn",
        "colorAnimation",
        "startStyle",
        "endStyle",
        "complexAnimation",
        "TransformWidget*",
        "startRotation",
        "endRotation",
        "startScale",
        "endScale",
        "bounceAnimation",
        "startPos",
        "endPos",
        "fallduration",
        "bounceUpDuration",
        "bounceUstartPos",
        "bounceUpendPos",
        "swingAnimation",
        "startAngle",
        "endAngle",
        "pathAnimation",
        "pathWidget",
        "QPainterPath&",
        "path",
        "sequenceAnimation",
        "QList<QPoint>",
        "points",
        "flipAnimation",
        "FlipWidget*",
        "startColor",
        "endColor"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'slideAnimation'
        QtMocHelpers::SlotData<void(QWidget *, const QRect &, const QRect &, int, AnimationCallback)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QRect, 5 }, { QMetaType::QRect, 6 }, { QMetaType::Int, 7 },
            { 0x80000000 | 8, 9 },
        }}),
        // Slot 'slideAnimation'
        QtMocHelpers::SlotData<void(QWidget *, const QRect &, const QRect &, int)>(1, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QRect, 5 }, { QMetaType::QRect, 6 }, { QMetaType::Int, 7 },
        }}),
        // Slot 'slideAnimation'
        QtMocHelpers::SlotData<void(QWidget *, const QRect &, const QRect &)>(1, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QRect, 5 }, { QMetaType::QRect, 6 },
        }}),
        // Slot 'slideAnimation'
        QtMocHelpers::SlotData<void(QWidget *, const QRect &)>(1, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QRect, 5 },
        }}),
        // Slot 'slideAnimation'
        QtMocHelpers::SlotData<void(QWidget *)>(1, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'fadeAnimation'
        QtMocHelpers::SlotData<void(QWidget *, bool, int, AnimationCallback)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Bool, 11 }, { QMetaType::Int, 7 }, { 0x80000000 | 8, 9 },
        }}),
        // Slot 'fadeAnimation'
        QtMocHelpers::SlotData<void(QWidget *, bool, int)>(10, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Bool, 11 }, { QMetaType::Int, 7 },
        }}),
        // Slot 'fadeAnimation'
        QtMocHelpers::SlotData<void(QWidget *, bool)>(10, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Bool, 11 },
        }}),
        // Slot 'colorAnimation'
        QtMocHelpers::SlotData<void(QWidget *, const QString &, const QString &, int, AnimationCallback)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QString, 13 }, { QMetaType::QString, 14 }, { QMetaType::Int, 7 },
            { 0x80000000 | 8, 9 },
        }}),
        // Slot 'colorAnimation'
        QtMocHelpers::SlotData<void(QWidget *, const QString &, const QString &, int)>(12, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QString, 13 }, { QMetaType::QString, 14 }, { QMetaType::Int, 7 },
        }}),
        // Slot 'colorAnimation'
        QtMocHelpers::SlotData<void(QWidget *, const QString &, const QString &)>(12, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QString, 13 }, { QMetaType::QString, 14 },
        }}),
        // Slot 'colorAnimation'
        QtMocHelpers::SlotData<void(QWidget *, const QString &)>(12, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QString, 13 },
        }}),
        // Slot 'colorAnimation'
        QtMocHelpers::SlotData<void(QWidget *)>(12, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'complexAnimation'
        QtMocHelpers::SlotData<void(TransformWidget *, qreal, qreal, qreal, qreal, int, AnimationCallback)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 16, 4 }, { QMetaType::QReal, 17 }, { QMetaType::QReal, 18 }, { QMetaType::QReal, 19 },
            { QMetaType::QReal, 20 }, { QMetaType::Int, 7 }, { 0x80000000 | 8, 9 },
        }}),
        // Slot 'complexAnimation'
        QtMocHelpers::SlotData<void(TransformWidget *, qreal, qreal, qreal, qreal, int)>(15, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 16, 4 }, { QMetaType::QReal, 17 }, { QMetaType::QReal, 18 }, { QMetaType::QReal, 19 },
            { QMetaType::QReal, 20 }, { QMetaType::Int, 7 },
        }}),
        // Slot 'complexAnimation'
        QtMocHelpers::SlotData<void(TransformWidget *, qreal, qreal, qreal, qreal)>(15, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 16, 4 }, { QMetaType::QReal, 17 }, { QMetaType::QReal, 18 }, { QMetaType::QReal, 19 },
            { QMetaType::QReal, 20 },
        }}),
        // Slot 'complexAnimation'
        QtMocHelpers::SlotData<void(TransformWidget *, qreal, qreal, qreal)>(15, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 16, 4 }, { QMetaType::QReal, 17 }, { QMetaType::QReal, 18 }, { QMetaType::QReal, 19 },
        }}),
        // Slot 'complexAnimation'
        QtMocHelpers::SlotData<void(TransformWidget *, qreal, qreal)>(15, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 16, 4 }, { QMetaType::QReal, 17 }, { QMetaType::QReal, 18 },
        }}),
        // Slot 'complexAnimation'
        QtMocHelpers::SlotData<void(TransformWidget *, qreal)>(15, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 16, 4 }, { QMetaType::QReal, 17 },
        }}),
        // Slot 'complexAnimation'
        QtMocHelpers::SlotData<void(TransformWidget *)>(15, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 16, 4 },
        }}),
        // Slot 'bounceAnimation'
        QtMocHelpers::SlotData<void(QWidget *, const QPoint &, const QPoint &, int, int, const QPoint &, const QPoint &, AnimationCallback)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QPoint, 22 }, { QMetaType::QPoint, 23 }, { QMetaType::Int, 24 },
            { QMetaType::Int, 25 }, { QMetaType::QPoint, 26 }, { QMetaType::QPoint, 27 }, { 0x80000000 | 8, 9 },
        }}),
        // Slot 'bounceAnimation'
        QtMocHelpers::SlotData<void(QWidget *, const QPoint &, const QPoint &, int, int, const QPoint &, const QPoint &)>(21, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QPoint, 22 }, { QMetaType::QPoint, 23 }, { QMetaType::Int, 24 },
            { QMetaType::Int, 25 }, { QMetaType::QPoint, 26 }, { QMetaType::QPoint, 27 },
        }}),
        // Slot 'bounceAnimation'
        QtMocHelpers::SlotData<void(QWidget *, const QPoint &, const QPoint &, int, int, const QPoint &)>(21, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QPoint, 22 }, { QMetaType::QPoint, 23 }, { QMetaType::Int, 24 },
            { QMetaType::Int, 25 }, { QMetaType::QPoint, 26 },
        }}),
        // Slot 'bounceAnimation'
        QtMocHelpers::SlotData<void(QWidget *, const QPoint &, const QPoint &, int, int)>(21, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QPoint, 22 }, { QMetaType::QPoint, 23 }, { QMetaType::Int, 24 },
            { QMetaType::Int, 25 },
        }}),
        // Slot 'bounceAnimation'
        QtMocHelpers::SlotData<void(QWidget *, const QPoint &, const QPoint &, int)>(21, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QPoint, 22 }, { QMetaType::QPoint, 23 }, { QMetaType::Int, 24 },
        }}),
        // Slot 'bounceAnimation'
        QtMocHelpers::SlotData<void(QWidget *, const QPoint &, const QPoint &)>(21, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QPoint, 22 }, { QMetaType::QPoint, 23 },
        }}),
        // Slot 'bounceAnimation'
        QtMocHelpers::SlotData<void(QWidget *, const QPoint &)>(21, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QPoint, 22 },
        }}),
        // Slot 'bounceAnimation'
        QtMocHelpers::SlotData<void(QWidget *)>(21, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'swingAnimation'
        QtMocHelpers::SlotData<void(TransformWidget *, qreal, qreal, int, AnimationCallback)>(28, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 16, 4 }, { QMetaType::QReal, 29 }, { QMetaType::QReal, 30 }, { QMetaType::Int, 7 },
            { 0x80000000 | 8, 9 },
        }}),
        // Slot 'swingAnimation'
        QtMocHelpers::SlotData<void(TransformWidget *, qreal, qreal, int)>(28, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 16, 4 }, { QMetaType::QReal, 29 }, { QMetaType::QReal, 30 }, { QMetaType::Int, 7 },
        }}),
        // Slot 'swingAnimation'
        QtMocHelpers::SlotData<void(TransformWidget *, qreal, qreal)>(28, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 16, 4 }, { QMetaType::QReal, 29 }, { QMetaType::QReal, 30 },
        }}),
        // Slot 'pathAnimation'
        QtMocHelpers::SlotData<void(QWidget *, QPainterPath &, int, AnimationCallback)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 32 }, { 0x80000000 | 33, 34 }, { QMetaType::Int, 7 }, { 0x80000000 | 8, 9 },
        }}),
        // Slot 'pathAnimation'
        QtMocHelpers::SlotData<void(QWidget *, QPainterPath &, int)>(31, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 32 }, { 0x80000000 | 33, 34 }, { QMetaType::Int, 7 },
        }}),
        // Slot 'pathAnimation'
        QtMocHelpers::SlotData<void(QWidget *, QPainterPath &)>(31, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 32 }, { 0x80000000 | 33, 34 },
        }}),
        // Slot 'sequenceAnimation'
        QtMocHelpers::SlotData<void(QWidget *, const QVector<QPoint> &, int, AnimationCallback)>(35, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 36, 37 }, { QMetaType::Int, 7 }, { 0x80000000 | 8, 9 },
        }}),
        // Slot 'sequenceAnimation'
        QtMocHelpers::SlotData<void(QWidget *, const QVector<QPoint> &, int)>(35, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 36, 37 }, { QMetaType::Int, 7 },
        }}),
        // Slot 'sequenceAnimation'
        QtMocHelpers::SlotData<void(QWidget *, const QVector<QPoint> &)>(35, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 36, 37 },
        }}),
        // Slot 'flipAnimation'
        QtMocHelpers::SlotData<void(FlipWidget *, qreal, qreal, const QColor &, const QColor &, int, AnimationCallback)>(38, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 39, 4 }, { QMetaType::QReal, 29 }, { QMetaType::QReal, 30 }, { QMetaType::QColor, 40 },
            { QMetaType::QColor, 41 }, { QMetaType::Int, 7 }, { 0x80000000 | 8, 9 },
        }}),
        // Slot 'flipAnimation'
        QtMocHelpers::SlotData<void(FlipWidget *, qreal, qreal, const QColor &, const QColor &, int)>(38, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 39, 4 }, { QMetaType::QReal, 29 }, { QMetaType::QReal, 30 }, { QMetaType::QColor, 40 },
            { QMetaType::QColor, 41 }, { QMetaType::Int, 7 },
        }}),
        // Slot 'flipAnimation'
        QtMocHelpers::SlotData<void(FlipWidget *, qreal, qreal, const QColor &, const QColor &)>(38, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 39, 4 }, { QMetaType::QReal, 29 }, { QMetaType::QReal, 30 }, { QMetaType::QColor, 40 },
            { QMetaType::QColor, 41 },
        }}),
        // Slot 'flipAnimation'
        QtMocHelpers::SlotData<void(FlipWidget *, qreal, qreal, const QColor &)>(38, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 39, 4 }, { QMetaType::QReal, 29 }, { QMetaType::QReal, 30 }, { QMetaType::QColor, 40 },
        }}),
        // Slot 'flipAnimation'
        QtMocHelpers::SlotData<void(FlipWidget *, qreal, qreal)>(38, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 39, 4 }, { QMetaType::QReal, 29 }, { QMetaType::QReal, 30 },
        }}),
        // Slot 'flipAnimation'
        QtMocHelpers::SlotData<void(FlipWidget *, qreal)>(38, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 39, 4 }, { QMetaType::QReal, 29 },
        }}),
        // Slot 'flipAnimation'
        QtMocHelpers::SlotData<void(FlipWidget *)>(38, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 39, 4 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<AnimationDemo, qt_meta_tag_ZN13AnimationDemoE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject AnimationDemo::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13AnimationDemoE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13AnimationDemoE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13AnimationDemoE_t>.metaTypes,
    nullptr
} };

void AnimationDemo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<AnimationDemo *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->slideAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QRect>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QRect>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<AnimationCallback>>(_a[5]))); break;
        case 1: _t->slideAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QRect>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QRect>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 2: _t->slideAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QRect>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QRect>>(_a[3]))); break;
        case 3: _t->slideAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QRect>>(_a[2]))); break;
        case 4: _t->slideAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        case 5: _t->fadeAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<AnimationCallback>>(_a[4]))); break;
        case 6: _t->fadeAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 7: _t->fadeAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 8: _t->colorAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<AnimationCallback>>(_a[5]))); break;
        case 9: _t->colorAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 10: _t->colorAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 11: _t->colorAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 12: _t->colorAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        case 13: _t->complexAnimation((*reinterpret_cast< std::add_pointer_t<TransformWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<AnimationCallback>>(_a[7]))); break;
        case 14: _t->complexAnimation((*reinterpret_cast< std::add_pointer_t<TransformWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6]))); break;
        case 15: _t->complexAnimation((*reinterpret_cast< std::add_pointer_t<TransformWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[5]))); break;
        case 16: _t->complexAnimation((*reinterpret_cast< std::add_pointer_t<TransformWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[4]))); break;
        case 17: _t->complexAnimation((*reinterpret_cast< std::add_pointer_t<TransformWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3]))); break;
        case 18: _t->complexAnimation((*reinterpret_cast< std::add_pointer_t<TransformWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 19: _t->complexAnimation((*reinterpret_cast< std::add_pointer_t<TransformWidget*>>(_a[1]))); break;
        case 20: _t->bounceAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<AnimationCallback>>(_a[8]))); break;
        case 21: _t->bounceAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[7]))); break;
        case 22: _t->bounceAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[6]))); break;
        case 23: _t->bounceAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        case 24: _t->bounceAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 25: _t->bounceAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[3]))); break;
        case 26: _t->bounceAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[2]))); break;
        case 27: _t->bounceAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        case 28: _t->swingAnimation((*reinterpret_cast< std::add_pointer_t<TransformWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<AnimationCallback>>(_a[5]))); break;
        case 29: _t->swingAnimation((*reinterpret_cast< std::add_pointer_t<TransformWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 30: _t->swingAnimation((*reinterpret_cast< std::add_pointer_t<TransformWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3]))); break;
        case 31: _t->pathAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPainterPath&>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<AnimationCallback>>(_a[4]))); break;
        case 32: _t->pathAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPainterPath&>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 33: _t->pathAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPainterPath&>>(_a[2]))); break;
        case 34: _t->sequenceAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<QPoint>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<AnimationCallback>>(_a[4]))); break;
        case 35: _t->sequenceAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<QPoint>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 36: _t->sequenceAnimation((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<QPoint>>>(_a[2]))); break;
        case 37: _t->flipAnimation((*reinterpret_cast< std::add_pointer_t<FlipWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<AnimationCallback>>(_a[7]))); break;
        case 38: _t->flipAnimation((*reinterpret_cast< std::add_pointer_t<FlipWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6]))); break;
        case 39: _t->flipAnimation((*reinterpret_cast< std::add_pointer_t<FlipWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[5]))); break;
        case 40: _t->flipAnimation((*reinterpret_cast< std::add_pointer_t<FlipWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[4]))); break;
        case 41: _t->flipAnimation((*reinterpret_cast< std::add_pointer_t<FlipWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3]))); break;
        case 42: _t->flipAnimation((*reinterpret_cast< std::add_pointer_t<FlipWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 43: _t->flipAnimation((*reinterpret_cast< std::add_pointer_t<FlipWidget*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< TransformWidget* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< TransformWidget* >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< TransformWidget* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< TransformWidget* >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< TransformWidget* >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< TransformWidget* >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< TransformWidget* >(); break;
            }
            break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 23:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 24:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 25:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 27:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< TransformWidget* >(); break;
            }
            break;
        case 29:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< TransformWidget* >(); break;
            }
            break;
        case 30:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< TransformWidget* >(); break;
            }
            break;
        case 31:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 32:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 33:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 34:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QPoint> >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 35:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QPoint> >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 36:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QPoint> >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 37:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FlipWidget* >(); break;
            }
            break;
        case 38:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FlipWidget* >(); break;
            }
            break;
        case 39:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FlipWidget* >(); break;
            }
            break;
        case 40:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FlipWidget* >(); break;
            }
            break;
        case 41:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FlipWidget* >(); break;
            }
            break;
        case 42:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FlipWidget* >(); break;
            }
            break;
        case 43:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< FlipWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *AnimationDemo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnimationDemo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13AnimationDemoE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AnimationDemo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    }
    return _id;
}
QT_WARNING_POP
