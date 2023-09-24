#include "bannerwidget.h"

#include <QPainter>

BannerWidget::BannerWidget(QWidget *parent) : QWidget{parent} {
  //  m_layout = new QHBoxLayout;
  //  m_layout->setSpacing(24 * this->devicePixelRatio());
  //  m_layout->setContentsMargins(
  //      8 * this->devicePixelRatio(), 8 * this->devicePixelRatio(),
  //      8 * this->devicePixelRatio(), 8 * this->devicePixelRatio());

  //  m_label_icon = new QLabel;
  //  m_label_icon->setPixmap(QString(":/icon.png"));
  //  m_label_icon->setScaledContents(true);

  //  QPalette text_palette = this->palette();
  //  text_palette.setColor(this->foregroundRole(), Qt::white);

  //  QFont text_font = this->font();
  //  text_font.setPointSize(20);

  //  m_label_title = new QLabel("Title");
  //  m_label_title->setAlignment(Qt::AlignLeft | Qt::AlignTop);
  //  m_label_title->setPalette(text_palette);
  //  m_label_title->setFont(text_font);
  //  text_font.setPointSize(11);

  //  m_label_subtitle = new QLabel("Subtitle");
  //  m_label_subtitle->setAlignment(Qt::AlignLeft | Qt::AlignTop);
  //  m_label_subtitle->setPalette(text_palette);
  //  m_label_subtitle->setFont(text_font);

  //  m_sublayout = new QVBoxLayout;
  //  m_spacer =
  //      new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
  //  m_sublayout->setContentsMargins(0, 0, 0, 0);
  //  //  m_sublayout->setSpacing(4 * this->devicePixelRatio());
  //  m_sublayout->addWidget(m_label_title);
  //  m_sublayout->addWidget(m_label_subtitle);
  //  m_sublayout->addSpacerItem(m_spacer);

  //  m_layout->addWidget(m_label_icon);
  //  m_layout->addLayout(m_sublayout);

  //  this->setLayout(m_layout);
}

void BannerWidget::resizeEvent(QResizeEvent *evt) {
  //  const auto size = this->height() - (16 * this->devicePixelRatio());
  //  m_label_icon->setFixedSize(size, size);
}

void BannerWidget::paintEvent(QPaintEvent *evt) {
  QPainter p(this);
  p.fillRect(this->rect(), QColor(0x22, 0x22, 0x22));
}
