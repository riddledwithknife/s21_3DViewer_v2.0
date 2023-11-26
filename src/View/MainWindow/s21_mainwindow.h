#ifndef S21_MAINWINDOW_H
#define S21_MAINWINDOW_H

#include <QMainWindow>

#include "Model/QtGifImage/gifimage/qgifimage.h"
#include "Model/s21_joystick.h"
#include "Model/s21_myglwidget.h"

extern "C" {
#include "Model/QtGifImage/gifimage/qgifimage.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class s21_MainWindow;
class MainWindowObserverInterface;
class Observer;
}  // namespace Ui
QT_END_NAMESPACE

class Ui::MainWindowObserverInterface {
 public:
  virtual ~MainWindowObserverInterface() = default;

  virtual void BackgroundColorChange() = 0;
  virtual void ProjectionChange() = 0;
  virtual void VertexChange() = 0;
  virtual void EdgeChange() = 0;
  virtual void ModelTransformed() = 0;
  virtual void ModelReset() = 0;
  virtual void ScreenshotTaken() = 0;
  virtual void GifMade() = 0;
};

class Ui::Observer : Ui::MainWindowObserverInterface {
 public:
  void BackgroundColorChange() override { number_with_app_interactions_ += 1; }

  void ProjectionChange() override { number_with_app_interactions_ += 1; }

  void VertexChange() override { number_with_app_interactions_ += 1; }

  void EdgeChange() override { number_with_app_interactions_ += 1; }

  void ModelTransformed() override { number_with_app_interactions_ += 1; }

  void ModelReset() override { number_with_app_interactions_ += 1; }

  void ScreenshotTaken() override { number_with_app_interactions_ += 1; }

  void GifMade() override { number_with_app_interactions_ += 1; }

  int GetNumberOfAppInteractions() const {
    return number_with_app_interactions_;
  }

 private:
  int number_with_app_interactions_ = 0;
};

class s21_MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  s21_MainWindow(const s21_MainWindow &) = delete;
  s21_MainWindow(s21_MainWindow &&) = delete;
  void operator=(const s21_MainWindow &) = delete;

  static s21_MainWindow &GetMainWindow() {
    static s21_MainWindow instance;
    return instance;
  }

  void AttachObserver(Ui::Observer *observer) {
    observers_.push_back(observer);
  }

 private slots:
  void on_BackgroundColor_clicked();

  void on_ProjectionButton_clicked();

  void on_VertexButton_clicked();

  void on_EdgeButton_clicked();

  void on_LittleProjection_clicked();

  void on_VertexColor_clicked();

  void on_VertexSize_textChanged();

  void on_TopVertex_clicked();

  void on_BottomVertex_clicked();

  void on_EdgeColor_clicked();

  void on_EdgeThickness_textChanged();

  void on_LittleEdge_clicked();

  void on_Open_clicked();

  void on_Increase_clicked();

  void on_Decrease_clicked();

  void on_Reset_clicked();

  void on_ShowMenu_clicked();

  void on_Screenshot_clicked();

  void on_Gif_clicked();

  void saveGif();

  void mouseMoveEvent(QMouseEvent *cursor_position) override;

  void mousePressEvent(QMouseEvent *event) override;

  void keyPressEvent(QKeyEvent *event) override;

  void mouseReleaseEvent(QMouseEvent *cursor_position) override;

  void keyReleaseEvent(QKeyEvent *event) override;

  void wheelEvent(QWheelEvent *event) override;

  void updateUi();

 private:
  explicit s21_MainWindow(QWidget *parent = nullptr);
  ~s21_MainWindow();

  std::vector<Ui::Observer *> observers_;

  Ui::s21_MainWindow *ui_;
  s21::JoyStick *joy_stick_;
  s21::MyGLWidget *model_;

  QGifImage *gif_;
  QTimer *timer_;
  QPoint click_pos_;

  int frames_;
  bool left_button_pressed_;
  bool right_button_pressed_;
  bool z_pressed_;
};

#endif  // S21_MAINWINDOW_H
