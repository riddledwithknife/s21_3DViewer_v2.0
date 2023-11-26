#include "../Model/s21_transformation.h"

#include <gtest/gtest.h>

TEST(Transformation, ScaleNormalBehaviourDecrease) {
  std::vector<double> test_vector_d = {0.000000, 1.000000, 1.000000};
  s21::Transformation transformation(test_vector_d);

  transformation.Scale(90);

  std::vector<double> scaled_vector = {0.000000, 0.900000, 0.900000};

  EXPECT_TRUE(transformation.GetVector() == scaled_vector);
}

TEST(Transformation, ScaleNormalBehaviourIncrease) {
  std::vector<double> test_vector_d = {0.000000, 1.000000, 1.000000};
  s21::Transformation transformation(test_vector_d);

  transformation.Scale(110);

  std::vector<double> scaled_vector = {0.000000, 1.100000, 1.100000};

  EXPECT_TRUE(transformation.GetVector() == scaled_vector);
}

TEST(Transformation, MoveXNormalBehaviour) {
  std::vector<double> test_vector_d = {0.000000, 1.000000, 1.000000};
  s21::Transformation transformation(test_vector_d);

  transformation.MoveX(200);

  std::vector<double> moved_vector = {2.000000, 1.000000, 1.000000};

  EXPECT_TRUE(transformation.GetVector() == moved_vector);
}

TEST(Transformation, MoveYNormalBehaviour) {
  std::vector<double> test_vector_d = {0.000000, 1.000000, 1.000000};
  s21::Transformation transformation(test_vector_d);

  transformation.MoveY(200);

  std::vector<double> moved_vector = {0.000000, 3.000000, 1.000000};

  EXPECT_TRUE(transformation.GetVector() == moved_vector);
}

TEST(Transformation, MoveZNormalBehaviour) {
  std::vector<double> test_vector_d = {0.000000, 1.000000, 1.000000};
  s21::Transformation transformation(test_vector_d);

  transformation.MoveZ(200);

  std::vector<double> moved_vector = {0.000000, 1.000000, 3.000000};

  EXPECT_TRUE(transformation.GetVector() == moved_vector);
}

TEST(Transformation, RotateXNormalBehaviour) {
  std::vector<double> test_vector_d = {0.000000, 1.000000, 1.000000};
  s21::Transformation transformation(test_vector_d);

  transformation.RotateX(200);

  std::vector<double> rotated_vector = {0.000000, 0.493151, -1.325444};

  for (size_t i = 0; i < rotated_vector.size(); ++i) {
    EXPECT_NEAR(transformation.GetVector()[i], rotated_vector[i], 1e-6);
  }
}

TEST(Transformation, RotateYNormalBehaviour) {
  std::vector<double> test_vector_d = {0.000000, 1.000000, 1.000000};
  s21::Transformation transformation(test_vector_d);

  transformation.RotateY(200);

  std::vector<double> rotated_vector = {0.909297, 1.000000, -0.416147};

  for (size_t i = 0; i < rotated_vector.size(); ++i) {
    EXPECT_NEAR(transformation.GetVector()[i], rotated_vector[i], 1e-6);
  }
}