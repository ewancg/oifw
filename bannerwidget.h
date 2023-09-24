#ifndef BANNERWIDGET_H
#define BANNERWIDGET_H

#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>

class BannerWidget : public QWidget
{
  Q_OBJECT
 public:
  explicit BannerWidget(QWidget *parent = nullptr);

 signals:
 private:
  QHBoxLayout *m_layout;
  QVBoxLayout *m_sublayout;
  QSpacerItem *m_spacer;
  QLabel *m_label_icon, *m_label_title, *m_label_subtitle;
 protected slots:
  void resizeEvent(QResizeEvent *evt) override;

  void paintEvent(QPaintEvent *evt) override;
};

#endif // BANNERWIDGET_H
