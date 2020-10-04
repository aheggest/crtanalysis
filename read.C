//local includes
#include "TreeManager.h"

//ROOT includes
#include <TGeoManager.h>
#include <TPolyMarker3D.h>
#include <TEveManager.h>
#include <TEveEventManager.h>
#include <TEveElement.h>
#include <TEveUtil.h>
#include <TEveGeoNode.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TEveBoxSet.h>
#include <TBranch.h>
#include <TEveViewer.h>
#include <TGLViewer.h>
#include <TEveTrans.h>
#include <TEveScene.h>
#include <TEveBrowser.h>
#include <TH3F.h>
#include <TObjArray.h>
#include <THashTable.h>
#include <TPaveText.h>
#include <TLegend.h>

//C++ includes
#include <string>
#include <iostream>
#include <list>
#include <algorithm>
#include <set>
#include <cmath>
#include <climits>

using namespace std;

void OverlayHistograms(){

  //WestFebs full range
  TFile *f1 = new TFile("~/Downloads/research/analysis/crtanalysis/ROOTfiles/spectra/old/rootplots/outfileWestFullLogy.root");
  TH1F* h1 = (TH1F*)f1->FindObjectAny("havg");
  h1->SetLineColor(kRed);
  h1->SetTitle("West FEBs full range shape");
  h1->DrawClone("hist");

  TFile *f2 = new TFile("~/Downloads/research/analysis/crtanalysis/ROOTfiles/spectra/new/rootplots/outfileWestFullrangeMaxchanLogy.root");
  TH1F* h2 = (TH1F*)f2->FindObjectAny("havg");
  h2->SetLineColor(kBlue);
  h2->SetTitle("West FEBs full range shape");
  h2->DrawClone("histsame");

  auto legend12 = new TLegend(0.75,0.7,0.95,0.95);
  legend12->AddEntry(h1,"All channels","lc");
  legend12->AddEntry(h2,"MaxChan only","lc");
  legend12->Draw();

  //WestFebs dynamic range
  new TCanvas;
  TFile *f3 = new TFile("~/Downloads/research/analysis/crtanalysis/ROOTfiles/spectra/old/rootplots/outfileWestDynamicNology.root");
  TH1F* h3 = (TH1F*)f3->FindObjectAny("havg");
  h3->SetLineColor(kRed);
  h3->SetTitle("West FEBs dynamic range shape");
  h3->DrawClone("hist");

  TFile *f4 = new TFile("~/Downloads/research/analysis/crtanalysis/ROOTfiles/spectra/new/rootplots/outfileWestDynamicrangeMaxchanNology.root");
  TH1F* h4 = (TH1F*)f4->FindObjectAny("havg");
  h4->SetLineColor(kBlue);
  h4->SetTitle("West FEBs dynamic range shape");
  h4->DrawClone("histsame");

  auto legend34 = new TLegend(0.75,0.7,0.95,0.95);
  legend34->AddEntry(h3,"All channels","lc");
  legend34->AddEntry(h4,"MaxChan only","lc");
  legend34->Draw();

  //NorthFebs full range
  new TCanvas;
  TFile *f5 = new TFile("~/Downloads/research/analysis/crtanalysis/ROOTfiles/spectra/old/rootplots/outfileNorthFullLogy.root");
  TH1F* h5 = (TH1F*)f5->FindObjectAny("havg");
  h5->SetLineColor(kRed);
  h5->SetTitle("North FEBs full range spectra");
  h5->DrawClone("hist");

  TFile *f6 = new TFile("~/Downloads/research/analysis/crtanalysis/ROOTfiles/spectra/new/rootplots/outfileWestFullrangeMaxchanLogy.root");
  TH1F* h6 = (TH1F*)f6->FindObjectAny("havg");
  h6->SetLineColor(kBlue);
  h6->SetTitle("North FEBs full range spectra");
  h6->DrawClone("histsame");

  auto legend56 = new TLegend(0.75,0.7,0.95,0.95);
  legend56->AddEntry(h1,"All channels","lc");
  legend56->AddEntry(h2,"MaxChan only","lc");
  legend56->Draw();

  //North Febs Dynamic range
  new TCanvas;
  TFile *f7 = new TFile("~/Downloads/research/analysis/crtanalysis/ROOTfiles/spectra/old/rootplots/outfileNorthDynamicNology.root");
  TH1F* h7 = (TH1F*)f7->FindObjectAny("havg");
  h7->SetLineColor(kRed);
  h7->SetTitle("North FEBs dynamic range shape");
  h7->GetYaxis()->SetRangeUser(0,0.035);
  h7->DrawClone("hist");

  TFile *f8 = new TFile("~/Downloads/research/analysis/crtanalysis/ROOTfiles/spectra/new/rootplots/outfileNorthDynamicrangeMaxchanNology.root");
  TH1F* h8 = (TH1F*)f8->FindObjectAny("havg");
  h8->SetLineColor(kBlue);
  h8->SetTitle("North FEBs dynamic range shape");
  h8->GetYaxis()->SetRangeUser(0,0.035);
  h8->DrawClone("histsame");

  auto legend78 = new TLegend(0.75,0.7,0.95,0.95);
  legend78->AddEntry(h7,"All channels","lc");
  legend78->AddEntry(h8,"MaxChan only","lc");
  legend78->Draw();
}
