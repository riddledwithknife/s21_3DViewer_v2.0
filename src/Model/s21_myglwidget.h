#ifndef S21_MYGLWIDGET_H
#define S21_MYGLWIDGET_H

#include <QOpenGLWidget>

#include "s21_settings.h"

namespace s21 {
class MyGLWidget : public QOpenGLWidget {
  Q_OBJECT

 public:
  explicit MyGLWidget(QWidget *parent = nullptr) : QOpenGLWidget(parent) {}

 protected:
  void initializeGL() override;

  void paintGL() override;

  void setVertices() const;

  void setEdges();

 public:
  std::vector<double> vector_v_ = {};
  std::vector<unsigned> vector_f_ = {};
  Settings settings;
};
}  // namespace s21

#endif  // S21_MYGLWIDGET_H
