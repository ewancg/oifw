#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QShowEvent>
#include <QTimer>

#include "dwmapi.h"

class EventFilter : public QObject {
  Q_OBJECT
 protected slots:
  bool eventFilter(QObject *watched, QEvent *event) {
    switch (event->type()) {
      case QEvent::Show: {
        if (!event->spontaneous()) {
          auto window = qobject_cast<QWidget *>(watched);
          if (window && window->isWindow()) {
            //             window->setAttribute(Qt::WA_TranslucentBackground,
            //             true);
            //             // window->setAttribute(Qt::WA_NoSystemBackground,
            //             true);
            //             // window->setAttribute(Qt::WA_OpaquePaintEvent,
            //             false);

            //            BOOL dark = true;
            //            DwmSetWindowAttribute(hwnd,
            //            DWMWA_USE_IMMERSIVE_DARK_MODE, &dark,

            //                                  sizeof(dark));
          }
        }
        return false;
      }
      default:
        return false;
    }
  }
};

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   protected slots:
    void showEvent(QShowEvent *eve) override;

    void paintEvent(QPaintEvent *evt) override;

   private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
