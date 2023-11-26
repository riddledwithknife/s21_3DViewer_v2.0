#ifndef S21_JOYSTICK_H
#define S21_JOYSTICK_H

#include <QMouseEvent>
#include <QPainter>
#include <QWidget>

namespace s21 {
class JoyStick : public QWidget {
 public:
  explicit JoyStick(QWidget *parent = nullptr) : QWidget(parent) {}

 protected:
  void paintEvent(QPaintEvent *event) override;

  void mouseMoveEvent(QMouseEvent *event) override;

  void mouseReleaseEvent(QMouseEvent *event) override;

 private:
  QPoint circle_start_position = {56, 56};
  QPoint circle_position = {56, 56};
  int circle_radius = 10;
};
}  // namespace s21

#endif  // S21_JOYSTICK_H
