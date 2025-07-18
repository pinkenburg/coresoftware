// Tell emacs that this is a C++ source
//  -*- C++ -*-.
#ifndef CALOTOWERSTATUS_H
#define CALOTOWERSTATUS_H

#include "CaloTowerDefs.h"

#include <calobase/TowerInfoContainer.h>  // for TowerInfoContainer, TowerIn...

#include <fun4all/SubsysReco.h>

#include <iostream>
#include <string>

class CDBTTree;
class PHCompositeNode;
class TowerInfoContainer;

class CaloTowerStatus : public SubsysReco
{
 public:
  CaloTowerStatus(const std::string &name = "CaloTowerStatus");

  ~CaloTowerStatus() override;

  int InitRun(PHCompositeNode *topNode) override;
  int process_event(PHCompositeNode *topNode) override;
  void CreateNodeTree(PHCompositeNode *topNode);

  void set_detector_type(CaloTowerDefs::DetectorSystem dettype)
  {
    m_dettype = dettype;
    return;
  }
  void set_inputNodePrefix(const std::string &name)
  {
    m_inputNodePrefix = name;
    return;
  }
  void set_badChi2_const_threshold(float threshold)
  {
    badChi2_treshold_const = threshold;
    return;
  }
  void set_badChi2_quadratic_threshold(float threshold)
  {
    badChi2_treshold_quadratic = threshold;
    return;
  }
  void set_fraction_badChi2_threshold(float threshold)
  {
    fraction_badChi2_threshold = threshold;
    return;
  }
  void set_badChi2_max_threshold(float threshold)
  {
    badChi2_treshold_max = threshold;
    return;
  }
  void set_z_score_threshold(float threshold)
  {
    z_score_threshold = threshold;
    return;
  }
  void set_time_cut(float threshold)
  {
    time_cut = threshold;
    return;
  }
  void set_directURL_hotMap(const std::string &str)
  {
    m_directURL_hotMap = str;
    use_directURL_hotMap = true;
    return;
  }
  void set_directURL_time(const std::string &str)
  {
    m_directURL_time = str;
    use_directURL_time = true;
    return;
  }
  void set_directURL_chi2(const std::string &str)
  {
    m_directURL_chi2 = str;
    use_directURL_chi2 = true;
    return;
  }
  void set_doAbortNoHotMap(bool status = true)
  {
    m_doAbortNoHotMap = status;
    return;
  }
  void set_isSim(bool isSim = true)
  {
    m_isSim = isSim;
    return;
  }

 private:
  TowerInfoContainer *m_raw_towers{nullptr};

  CDBTTree *m_cdbttree_chi2{nullptr};
  CDBTTree *m_cdbttree_time{nullptr};
  CDBTTree *m_cdbttree_hotMap{nullptr};

  bool m_doHotChi2{true};
  bool m_doTime{true};
  bool m_doHotMap{true};
  bool m_doAbortNoHotMap{false};

  CaloTowerDefs::DetectorSystem m_dettype{CaloTowerDefs::DETECTOR_INVALID};

  std::string m_detector;
  std::string m_fieldname_time;
  std::string m_calibName_time;
  std::string m_fieldname_chi2;
  std::string m_calibName_chi2;
  std::string m_fieldname_hotMap;
  std::string m_fieldname_z_score;
  std::string m_calibName_hotMap;
  std::string m_inputNodePrefix{"TOWERS_"};

  std::string m_directURL_time;
  std::string m_directURL_hotMap;
  std::string m_directURL_chi2;
  bool use_directURL_time{false};
  bool use_directURL_hotMap{false};
  bool use_directURL_chi2{false};
  bool m_isSim{false};

  float badChi2_treshold_const = {1e4};
  float badChi2_treshold_quadratic = {1./100};
  float badChi2_treshold_max = {1e8};
  float fraction_badChi2_threshold = {0.01};
  float z_score_threshold = {5};
  float z_score_threshold_default = {5};
  float time_cut = 2;  // number of samples from the mean time for the channel in the run
};

#endif  // CALOTOWERBUILDER_H
