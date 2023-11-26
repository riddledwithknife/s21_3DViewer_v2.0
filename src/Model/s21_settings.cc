#include "s21_settings.h"

#include <QColor>
#include <QSettings>

void s21::Settings::SaveFileSettings() {
  QSettings settingsFile("s21", "3DViewer");

  settingsFile.setValue("backgroundColor", background_color.name());
  settingsFile.setValue("projection", projection);

  settingsFile.setValue("vertexColor", vertex_color.name());
  settingsFile.setValue("vertexSize", vertex_size);
  settingsFile.setValue("vertexType", vertex_type);

  settingsFile.setValue("edgeColor", edge_color.name());
  settingsFile.setValue("edgeThickness", edge_thickness);
  settingsFile.setValue("edgeType", edge_type);
}

void s21::Settings::LoadFileSettings() {
  QSettings settingsFile("s21", "3DViewer");

  background_color =
      settingsFile.value("backgroundColor", QColor(30, 30, 30)).toString();
  projection = settingsFile.value("projection", "Parallel").toString();

  vertex_color =
      settingsFile.value("vertexColor", QColor(255, 255, 255)).toString();
  vertex_size = settingsFile.value("vertexSize", 10).toInt();
  vertex_type = settingsFile.value("vertexType", "Circle").toString();

  edge_color =
      settingsFile.value("edgeColor", QColor(255, 255, 255)).toString();
  edge_thickness = settingsFile.value("edgeThickness", 5).toInt();
  edge_type = settingsFile.value("edgeType", "Solid").toString();
}

void s21::Settings::ClearFileSettings() {
  QSettings settingsFile("s21", "3DViewer");

  settingsFile.clear();
}