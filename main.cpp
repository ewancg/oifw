#include <QtPlugin>
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin);
Q_IMPORT_PLUGIN(QWindowsVistaStylePlugin);
#include <QApplication>

#include "mainwindow.h"
// #include "windows.h"

int main(int argc, char *argv[]) {
  qputenv("QT_QPA_PLATFORM", "windows:darkmode=1");
  QApplication a(argc, argv);
  //  EventFilter filter;

  QGuiApplication::setHighDpiScaleFactorRoundingPolicy(
      Qt::HighDpiScaleFactorRoundingPolicy::Floor);

  //  qApp->installEventFilter(&filter);
  a.setStyle("windowsvista");

  MainWindow w;
  w.show();
  return a.exec();
}
