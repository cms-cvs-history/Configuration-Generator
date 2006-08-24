#include <iostream>

#include "Configuration/Generator/test/MCAnalyzer.h"
 
#include "SimDataFormats/HepMCProduct/interface/HepMCProduct.h"
 
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/Handle.h"
 
#include "TFile.h"
#include "TH1.h"
 
#include "FWCore/Framework/interface/MakerMacros.h"
 
using namespace edm;
using namespace std;

 
MCAnalyzer::MCAnalyzer( const ParameterSet& pset )
   : fOutputFileName( pset.getUntrackedParameter<string>("HistOutFile",std::string("MCAnalysis.root")) ),
     fOutputFile(0), fHist2muMass(0), fHistmuPt(0), fHistmuEta(0), fHistmuPhi(0)
{
}

void MCAnalyzer::beginJob( const EventSetup& )
{
 
   fOutputFile   = new TFile( fOutputFileName.c_str(), "RECREATE" ) ;
   fHist2muMass  = new TH1D(  "Hist2muMass", "Dimuon invariant mass", 100,  0., 150. ) ;
   fHistmuPt  = new TH1D ( "HistmuPt", "Muon Pt spectrum", 100,  0., 100.)  ;
   fHistmuEta  = new TH1D ( "HistmuEta", "Muon eta spectrum", 20,  -5., 5.)  ;
   fHistmuPhi  = new TH1D ( "HistmuPhi", "Muon phi spectrum", 20,  -3.2, 3.2)  ;
    
  
}
 
void MCAnalyzer::analyze( const Event& e, const EventSetup& )
{
   
   Handle< HepMCProduct > EvtHandle ;
   
   e.getByLabel( "source", EvtHandle ) ;
   
   const HepMC::GenEvent* Evt = EvtHandle->GetEvent() ;
   
 
   HepMC::GenVertex* ProcessVtx = 0 ;
	 
   // find the hard scattering vertex with outgoing Z boson
   
   for ( HepMC::GenEvent::vertex_const_iterator
         vit=Evt->vertices_begin(); vit!=Evt->vertices_end(); vit++ )
   {
      for ( HepMC::GenVertex::particles_out_const_iterator
            pout=(*vit)->particles_out_const_begin();
	    pout!=(*vit)->particles_out_const_end(); pout++ )
      {
         if ( abs((*pout)->pdg_id()) == 23 ) 
         {
	    if ( (*pout)->end_vertex() != 0 )
	    {
	       ProcessVtx = (*pout)->end_vertex() ;
	       break ;
	    }
         }
      }
      if ( ProcessVtx != 0 )
      {
        // cout << " Hard Scattering vertex found ! " << endl ;
	 break ;
      }
   }
   
   if ( ProcessVtx == 0 ) 
   {
      cout << " There is no Z-boson in this event ! " << endl ;
      return ;
   }
      
   
   // store stable descendants of the Z
   //   
   vector<HepMC::GenParticle*> StableDesc ;
   
   for ( HepMC::GenVertex::particle_iterator
         des=ProcessVtx->particles_begin(HepMC::descendants);
	 des!=ProcessVtx->particles_end(HepMC::descendants); des++ )
   {
      if ( (*des)->status() == 1 ) StableDesc.push_back(*des) ;
   }
   
   HepLorentzVector Mom2part ;
  
         
   // browse the array of stable descendants
   // and do 2-mu inv.mass
   //
   for ( unsigned int i=0; i<StableDesc.size(); i++ )
   {
      // skip other than mu
      //
      if ( abs(StableDesc[i]->pdg_id()) == 13 ) { 
      
      for ( unsigned int j=i+1; j<StableDesc.size(); j++ )
      {
         // skip other than mu
	 //
	 if ( abs(StableDesc[j]->pdg_id()) == 13 ) {
	 //
	 // skip same charge combo's
	 //
	 if ( (StableDesc[i]->pdg_id()*StableDesc[j]->pdg_id()) > 0 ) {
	 
	 Mom2part = StableDesc[i]->momentum() + StableDesc[j]->momentum() ;	 
	 fHist2muMass->Fill( Mom2part.m() ) ;
	 fHistmuPt->Fill(StableDesc[i]->momentum().perp());
	 fHistmuPt->Fill(StableDesc[j]->momentum().perp());
	 fHistmuEta->Fill(StableDesc[i]->momentum().eta());
	 fHistmuEta->Fill(StableDesc[j]->momentum().eta());
	 fHistmuPhi->Fill(StableDesc[i]->momentum().phi());
         fHistmuPhi->Fill(StableDesc[j]->momentum().phi());
	}
	} 
      }
   }
   
   }
}

void MCAnalyzer::endJob()
{
       
   fOutputFile->Write() ;
   fOutputFile->Close() ;
   
}
 
DEFINE_FWK_MODULE(MCAnalyzer)
