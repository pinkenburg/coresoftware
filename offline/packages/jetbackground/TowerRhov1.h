#ifndef JETBACKGROUND_TOWERRHOV1_H
#define JETBACKGROUND_TOWERRHOV1_H

//===========================================================
/// \file TowerRhov1.h
/// \brief updated TowerRho class with method and sigma
/// \author Tanner Mengel
//===========================================================

#include "TowerRho.h"

class TowerRhov1 : public TowerRho
{
 public:
  TowerRhov1();
  ~TowerRhov1() override = default;

  void identify(std::ostream &os = std::cout) const override;
  void Reset() override {}  // new in v1
  int isValid() const override { return 1; }

  // setters
  void set_rho(float rho) override { m_tower_rho = rho; }
  void set_sigma(float sigma) override { m_tower_sigma = sigma; }
  void set_method(TowerRho::Method method) override;

  // getters
  float get_rho() override { return m_tower_rho; }
  float get_sigma() override { return m_tower_sigma; }
  TowerRho::Method get_method() override { return m_rho_method_type; }

  // static method to string conversion
  static std::string get_method_string(TowerRho::Method method);  // new in v1

 private:
  float m_tower_rho{0};                                        // momentum density
  float m_tower_sigma{0};                                      // sigma of momentum density
  TowerRho::Method m_rho_method_type{TowerRho::Method::NONE};  // method of rho calculation

  ClassDefOverride(TowerRhov1, 1);
};

#endif  // JETBACKGROUND_TOWERRHOV1_H
