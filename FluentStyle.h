#ifndef FLUENTSTYLE_H
#define FLUENTSTYLE_H

#include <QCommonStyle>
#include <QObject>
#include <QWidget>

class FluentStyle : public QCommonStyle
{
public:
    FluentStyle();

protected slots:
    void drawPrimitive(PrimitiveElement elem,
                       const QStyleOption *option,
                       QPainter *painter,
                       const QWidget *widget) const override;
};

#endif // FLUENTSTYLE_H
