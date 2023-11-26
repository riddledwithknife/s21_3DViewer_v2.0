#ifndef S21_SETTINGS_H
#define S21_SETTINGS_H

#include <QColor>
#include <QString>

namespace s21 {
class Settings {
 public:
  Settings() { LoadFileSettings(); }

  void SaveFileSettings();

  void LoadFileSettings();

  void ClearFileSettings();

  QColor background_color;
  QString projection;

  QColor vertex_color;
  int vertex_size;
  QString vertex_type;

  QColor edge_color;
  int edge_thickness;
  QString edge_type;
};
}  // namespace s21

#endif  // S21_SETTINGS_H
