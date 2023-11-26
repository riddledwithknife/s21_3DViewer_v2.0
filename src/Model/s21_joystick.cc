#include "s21_joystick.h"

#include <QMouseEvent>
#include <QPainter>

void s21::JoyStick::paintEvent(QPaintEvent *event) {
  Q_UNUSED(event);

  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(Qt::NoPen);
  painter.setBrush(Qt::gray);

  painter.drawEllipse(circle_position, circle_radius, circle_radius);
}

void s21::JoyStick::mouseMoveEvent(QMouseEvent *event) {
  double value = pow(event->pos().x() - 56, 2) + pow(event->pos().y() - 56, 2);
  double radius = 50 * 50;

  if (value < radius) {
    circle_position = event->pos();
    update();
  }
}

void s21::JoyStick::mouseReleaseEvent(QMouseEvent *event) {
  (void)event;
  circle_position = circle_start_position;
  update();
}
