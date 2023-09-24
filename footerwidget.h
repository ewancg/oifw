#ifndef FOOTERWIDGET_H
#define FOOTERWIDGET_H

#include <QWidget>

class FooterWidget : public QWidget
{
  Q_OBJECT
 public:
  explicit FooterWidget(QWidget *parent = nullptr);

 signals:
 protected slots:

  void paintEvent(QPaintEvent *evt) override;
};

#endif // FOOTERWIDGET_H
