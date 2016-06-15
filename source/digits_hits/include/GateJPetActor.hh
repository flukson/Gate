/*----------------------
  Copyright (C): OpenGATE Collaboration

  This software is distributed under the terms
  of the GNU Lesser General  Public Licence (LGPL)
  See GATE/LICENSE.txt for further details
  ----------------------*/

#include "GateConfiguration.h"
#ifdef G4ANALYSIS_USE_ROOT

#ifndef GATEJPETACTOR_HH
#define GATEJPETACTOR_HH

#include "TROOT.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TTree.h"
#include "TBranch.h"
#include "TString.h"

#include "GateVActor.hh"
#include "GateJPetActorMessenger.hh"

struct iaea_header_type;
struct iaea_record_type;

class G4EmCalculator;

//====================================================================
class GateJPetActor : public GateVActor
{
 public:

  virtual ~GateJPetActor();

  //====================================================================
  // This macro initialize the CreatePrototype and CreateInstance
  FCT_FOR_AUTO_CREATOR_ACTOR(GateJPetActor)

  //====================================================================
  // Constructs the sensor
  virtual void Construct();

  //====================================================================
  // Callbacks
  virtual void UserSteppingAction(const GateVVolume *, const G4Step*);
  virtual void PreUserTrackingAction(const GateVVolume *, const G4Track*);
  virtual void BeginOfEventAction(const G4Event * e);

  //=======================================================
  /// Saves the data collected to the file
  virtual void SaveData();
  virtual void ResetData();

  void SetIsXPositionEnabled(bool b){EnableXPosition = b;}
  void SetIsYPositionEnabled(bool b){EnableYPosition = b;}
  void SetIsZPositionEnabled(bool b){EnableZPosition = b;}
  void SetIsEkineEnabled(bool b){EnableEkine = b;}
  void SetIsXDirectionEnabled(bool b){EnableXDirection = b;}
  void SetIsYDirectionEnabled(bool b){EnableYDirection = b;}
  void SetIsZDirectionEnabled(bool b){EnableZDirection = b;}
  void SetIsParticleNameEnabled(bool b){EnablePartName = b;}
  void SetIsProdVolumeEnabled(bool b){EnableProdVol = b;}
  void SetIsProdProcessEnabled(bool b){EnableProdProcess = b;}
  void SetIsWeightEnabled(bool b){EnableWeight = b;}
  void SetIsTimeEnabled(bool b){EnableTime = b;}
  void SetIsLocalTimeEnabled(bool b){EnableLocalTime = b;}
  void SetIsMassEnabled(bool b){EnableMass = b;}
  void SetIsSecStored(bool b){EnableSec = b;}
  void SetIsAllStep(bool b){EnableAllStep = b;}
  //_______________________________________________
  void SetIsChargeEnabled(bool b){EnableCharge = b;}
  void SetIsElectronicDEDXEnabled(bool b) {EnableElectronicDEDX = b;}
  void SetIsTotalDEDXEnabled(bool b) {EnableTotalDEDX = b;}
  //_______________________________________________
  
  void SetUseVolumeFrame(bool b){mUseVolFrame=b;}
  bool GetUseVolumeFrame(){return mUseVolFrame;}

  void SetStoreOutgoingParticles(bool b){mStoreOutPart=b;}
  bool GetStoreOutgoingParticles(){return mStoreOutPart;}

  void SetMaxFileSize(double size){mFileSize=size;}
  double GetMaxFileSize(){return mFileSize ;}

  void SetIsPrimaryEnergyEnabled(bool b){bEnablePrimaryEnergy = b;}
  void SetIsEmissionPointEnabled(bool b){bEnableEmissionPoint = b;}
  void SetEnableCoordFrame(){bEnableCoordFrame = true;}
  bool GetEnableCoordFrame(){return bEnableCoordFrame;}
  void SetCoordFrame(G4String nameOfFrame){bCoordFrame=nameOfFrame;}
  G4String GetCoordFrame(){return bCoordFrame ;}
  void SetIsSpotIDEnabled(){bEnableSpotID = true;}
  bool GetIsSpotIDEnabled(){return bEnableSpotID;}
  void SetSpotIDFromSource(G4String nameOfSource){bSpotIDFromSource = nameOfSource;}
  G4String GetSpotIDFromSource(){return bSpotIDFromSource;}
  void SetEnabledCompact(bool b){bEnableCompact = b;}
  void SetEnablePDGCode(bool b){bEnablePDGCode = b;}

protected:
  GateJPetActor(G4String name, G4int depth=0);

  TString mFileType;
  G4int mNevent;

  TFile * pFile;
  TTree * pListeVar;
  
  bool EnableCharge;
  bool EnableElectronicDEDX;
  bool EnableTotalDEDX;
  bool EnableXPosition;
  bool EnableYPosition;
  bool EnableZPosition;
  bool EnableEkine;
  bool EnableXDirection;
  bool EnableYDirection;
  bool EnableZDirection;
  bool EnablePartName;
  bool EnableProdVol;
  bool EnableProdProcess;
  bool EnableWeight;
  bool EnableTime;
  bool EnableLocalTime;
  bool EnableMass;
  bool EnableSec;
  bool EnableAllStep;
  bool mUseVolFrame;
  bool mStoreOutPart;

  bool bEnableCoordFrame;
  G4String bCoordFrame;
  bool bEnablePrimaryEnergy;
  float bPrimaryEnergy;
  bool bEnableEmissionPoint;
  float bEmissionPointX,bEmissionPointY,bEmissionPointZ;
  bool bEnableSpotID;
  G4String bSpotIDFromSource;
  int bSpotID;
  bool bEnableCompact;
  bool bEnablePDGCode;
  long int bPDGCode;

  double mFileSize;

  long int mNumberOfTrack;

  bool mIsFistStep;

  Char_t  pname[256];
  
  G4int c;
  float elecDEDX;
  float totalDEDX;
  float stepLength;
  float edep;
  
  float x;
  float y;
  float z;
  float dx;
  float dy;
  float dz;
  float e;
  float ekPost;
  float ekPre;
  float w;
  float t;//t is either time or local time.
  G4int m;
  Char_t vol[256];

  Char_t creator_process[256];
  Char_t pro_step[256];

  int trackid;
  int parentid;
  int eventid;
  int runid;
 

  G4EmCalculator * emcalc;
  GateJPetActorMessenger* pMessenger;

  iaea_record_type *pIAEARecordType;
  iaea_header_type *pIAEAheader;
};

MAKE_AUTO_CREATOR_ACTOR(JPetActor,GateJPetActor)


#endif /* end #define GATESOURCEACTOR_HH */
#endif