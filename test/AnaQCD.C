
#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TH2F.h"
#include "TH2F.h"

void AnaQCD(){

// make sure you first do
//
 gSystem->Load("libFWCoreFWLite");
 AutoLibraryLoader::enable();


 //style stuff
 gROOT->SetStyle("Plain");


// open the file
//
 TFile f("test.root");


// book histograms
//

TH1F * h1;
h1 = new TH1F("Particle Multiplicity","Particle Multipicity" ,50, 0., 2000.);
h1->GetYaxis()->SetTitle("Number of events");
h1->GetYaxis()->CenterTitle(1);
h1->GetXaxis()->SetTitle("Number of particles");
h1->GetXaxis()->CenterTitle();
TH1F * h2;
h2 = new TH1F("Process ID","Process ID" ,200, 0., 200.);
h2->GetYaxis()->SetTitle("Number of events");
h2->GetYaxis()->CenterTitle(1);
h2->GetXaxis()->SetTitle("Process ID");
h2->GetXaxis()->CenterTitle();
TH1F * h3;
h3 = new TH1F("Pt hat","Pt hat" ,50, 0., 500.);
h3->GetYaxis()->SetTitle("Number of events");
h3->GetYaxis()->CenterTitle(1);
h3->GetXaxis()->SetTitle("Pt hat (GeV)");
h3->GetXaxis()->CenterTitle();


TTree* events = (TTree*) (f.Get("Events"));
TBranch* MCBranch = events->GetBranch("edmHepMCProduct_source__PROD.obj");

edm::HepMCProduct prod;
MCBranch->SetAddress(&prod);

int nev = events->GetEntries();
for (int ev = 0; ev < nev ;  ++ev){

  MCBranch->GetEntry(ev);
   
  cout << "Number of particles for event " << ev << " = " << prod.getHepMCData().particles_size() << endl;  
  h1->Fill(prod.getHepMCData().particles_size());
  cout << "ProcessID of this event = " << prod.getHepMCData().signal_process_id() << endl;
  h2->Fill(prod.getHepMCData().signal_process_id());
  cout << "Pt hat of this event = " << prod.getHepMCData().event_scale()<< endl;
  h3->Fill(prod.getHepMCData().event_scale());
  
  
  /*
  for ( HepMC::GenEvent::particle_const_iterator p = prod.getHepMCData().particles_begin();
  	  p != prod.getHepMCData().particles_end(); ++p ) {
	  
	  Double_t mom = ((*p)->momentum()).perp();
	  if (abs((*p)->pdg_id()) == 13){ 
	    h4->Fill(mom);	// fill the pt of the muon in a histogram  	    
	  }
	  	
  } 
  */	  
   
   
 
   }
  
  
 
  TFile OutFile("validation.root","RECREATE") ;

  h1->Write(); 
  h2->Write(); 
  h3->Write(); 
 
  OutFile.Write() ;
  OutFile.Close() ;

 

}
