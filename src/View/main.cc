#include <QApplication>

#include "./MainWindow/s21_mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21_MainWindow &w = s21_MainWindow::GetMainWindow();

  Ui::Observer observer;
  w.AttachObserver(&observer);

  w.setWindowTitle("3DViewer");
  w.show();

  return a.exec();
}
