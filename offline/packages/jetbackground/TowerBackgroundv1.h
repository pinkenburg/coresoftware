#ifndef JETBACKGROUND_TOWERBACKGROUNDV1_H
#define JETBACKGROUND_TOWERBACKGROUNDV1_H

#include "TowerBackground.h"

#include <iostream>
#include <vector>

class TowerBackgroundv1 : public TowerBackground
{
 public:
  TowerBackgroundv1();
  ~TowerBackgroundv1() override = default;

  void identify(std::ostream &os = std::cout) const override;
  void Reset() override {}
  int isValid() const override { return 1; }

  void set_UE(int layer, const std::vector<float> &UE) override { _UE[layer] = UE; }
  void set_v2(float v2) override { _v2 = v2; }
  void set_Psi2(float Psi2) override { _Psi2 = Psi2; }
  void set_nStripsUsedForFlow(int nStrips) override { _nStrips = nStrips; }
  void set_nTowersUsedForBkg(int nTowers) override { _nTowers = nTowers; }
  void set_flow_failure_flag(bool b) override {_flow_failure_flag = b;}

  std::vector<float> get_UE(int layer) const override { return _UE[layer]; }
  float get_v2() const override { return _v2; }
  float get_Psi2() const override { return _Psi2; }
  int get_nStripsUsedForFlow() const override { return _nStrips; }
  bool get_flow_failure_flag() const override { return _flow_failure_flag; }

 private:
  std::vector<std::vector<float> > _UE;
  float _v2{0};
  float _Psi2{0};
  int _nStrips{0};
  int _nTowers{0};
  bool _flow_failure_flag{false};

  ClassDefOverride(TowerBackgroundv1, 2);
};

#endif
