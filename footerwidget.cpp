#include "footerwidget.h"

#include <QPainter>

FooterWidget::FooterWidget(QWidget *parent)
    : QWidget{parent}
{
  
}

void FooterWidget::paintEvent(QPaintEvent *evt) {
  QPainter p(this);
  static QColor fill_color = QColor(0xf0, 0xf0, 0xf0);
  static QColor border_top_color = QColor(0xa0, 0xa0, 0xa0);
  static QColor border_bottom_color = QColor(0xff, 0xff, 0xff);
  p.fillRect(this->rect(), border_top_color);
  p.fillRect(this->rect().adjusted(0, 1, 0, 0), fill_color);
}
