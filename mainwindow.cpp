#include "mainwindow.h"

#include <QPainter>
#include <QStyle>
#include <QTimer>

#include "./ui_mainwindow.h"
#include "dwmapi.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  qDebug() << qApp->style()->name();

  ui->centralwidget->setContentsMargins(0, 0, 0, 0);
  ui->verticalLayout->setContentsMargins(0, 0, 0, 0);
  this->setFixedSize(512 * this->logicalDpiX() / 96,
                     360 * this->logicalDpiY() / 96);
  setWindowFlags(Qt::Window | Qt::WindowTitleHint |
                 Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
  //  connect(ui->pushButton, &QPushButton::released, this,
  //          [] { qApp->aboutQt(); });
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::showEvent(QShowEvent *eve) {
  HWND hwnd = reinterpret_cast<HWND>(this->winId());
  MARGINS margins = {-1};
  DwmExtendFrameIntoClientArea(hwnd, &margins);
  COLORREF param = RGB(0x22, 0x22, 0x22);
  DwmSetWindowAttribute(hwnd, DWMWA_CAPTION_COLOR, &param, sizeof(param));
}

void MainWindow::paintEvent(QPaintEvent *evt) {
  QPainter p(this);
  p.fillRect(this->rect(), QColor(0xff, 0xff, 0xff));
}
