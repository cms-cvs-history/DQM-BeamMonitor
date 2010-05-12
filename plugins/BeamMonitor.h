#ifndef BeamMonitor_H
#define BeamMonitor_H

/** \class BeamMonitor
 * *
 *  $Date: 2010/04/13 17:07:51 $
 *  $Revision: 1.24 $
 *  \author  Geng-yuan Jeng/UC Riverside
 *           Francisco Yumiceva/FNAL
 *   
 */
// C++
#include <string>
// CMS
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/MonitorElement.h"
#include "RecoVertex/BeamSpotProducer/interface/BSTrkParameters.h"
#include "RecoVertex/BeamSpotProducer/interface/BeamFitter.h"
#include <fstream>


//
// class declaration
//

class BeamMonitor : public edm::EDAnalyzer {
 public:
  BeamMonitor( const edm::ParameterSet& );
  ~BeamMonitor();

 protected:
   
  // BeginJob
  void beginJob();

  // BeginRun
  void beginRun(const edm::Run& r, const edm::EventSetup& c);
  
  void analyze(const edm::Event& e, const edm::EventSetup& c) ;
  
  void beginLuminosityBlock(const edm::LuminosityBlock& lumiSeg, 
			    const edm::EventSetup& context) ;
  
  void endLuminosityBlock(const edm::LuminosityBlock& lumiSeg, 
			  const edm::EventSetup& c);
  // EndRun
  void endRun(const edm::Run& r, const edm::EventSetup& c);
  // Endjob
  void endJob(const edm::LuminosityBlock& lumiSeg, const edm::EventSetup& c);
  
 private:

  void FitAndFill(const edm::LuminosityBlock& lumiSeg,int&,int&,int&);
  void scrollTH1(TH1 *, time_t);
  bool testScroll(time_t &, time_t &);

  edm::ParameterSet parameters_;
  std::string monitorName_;
  edm::InputTag bsSrc_; // beam spot
  edm::InputTag tracksLabel_;
  edm::InputTag pvSrc_; // primary vertex

  int fitNLumi_;
  int fitPVNLumi_;
  int resetFitNLumi_;
  int resetPVNLumi_;
  int intervalInSec_;
  bool debug_;
  bool onlineMode_;
  
  DQMStore* dbe_;
  BeamFitter * theBeamFitter;
  
  int countEvt_;       //counter
  int countLumi_;      //counter
  int beginLumiOfBSFit_;
  int endLumiOfBSFit_;
  int beginLumiOfPVFit_;
  int endLumiOfPVFit_;
  int lastlumi_; // previous LS processed
  int nextlumi_; // next LS of Fit
  std::time_t refBStime[2];
  std::time_t refPVtime[2];
  unsigned int nthBSTrk_;
  int nFitElements_;
  int nFits_;
  double deltaSigCut_;
  unsigned int min_Ntrks_;
  double maxZ_;
  unsigned int minNrVertices_;
  double minVtxNdf_;
  double minVtxWgt_;

  bool resetHistos_;
  // ----------member data ---------------------------
  
  //   std::vector<BSTrkParameters> fBSvector;
  reco::BeamSpot refBS;
  reco::BeamSpot preBS;

  // MonitorElements:
  MonitorElement * h_nTrk_lumi;
  MonitorElement * h_d0_phi0;
  MonitorElement * h_sigmaX0_lumi;
  MonitorElement * h_sigmaX0_time;
  MonitorElement * h_sigmaY0_lumi;
  MonitorElement * h_sigmaY0_time;
  MonitorElement * h_sigmaZ0_lumi;
  MonitorElement * h_sigmaZ0_time;
  MonitorElement * h_trk_z0;
  MonitorElement * h_vx_vy;
  MonitorElement * h_vx_dz;
  MonitorElement * h_vy_dz;
  MonitorElement * h_trkPt;
  MonitorElement * h_trkVz;
  MonitorElement * fitResults;
  MonitorElement * h_x0;
  MonitorElement * h_y0;
  MonitorElement * h_z0;
  MonitorElement * h_sigmaX0;
  MonitorElement * h_sigmaY0;
  MonitorElement * h_sigmaZ0;
  MonitorElement * h_nVtx;
  MonitorElement * h_PVx[2];
  MonitorElement * h_PVy[2];
  MonitorElement * h_PVz[2];
  MonitorElement * h_PVxz;
  MonitorElement * h_PVyz;
  MonitorElement * pvResults;
  std::map<TString, MonitorElement*> hs;

  // Summary:
  Float_t reportSummary_;
  Float_t summarySum_;
  Float_t summaryContent_[3];
  MonitorElement * reportSummary;
  MonitorElement * reportSummaryContents[3];
  MonitorElement * reportSummaryMap;
  MonitorElement * cutFlowTable;
  // variables for beam fit

  //
  std::time_t tmpTime;
  std::time_t refTime;
  edm::TimeValue_t ftimestamp;
  int lastNZbin; // last non zero bin of time histos
};

#endif
