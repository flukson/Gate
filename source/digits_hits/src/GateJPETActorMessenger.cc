#include "../include/GateJPETActorMessenger.hh"
#ifdef G4ANALYSIS_USE_ROOT

#include "G4UIcmdWithABool.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithAnInteger.hh"

#include "GateJPETActor.hh"

GateJPETActorMessenger::GateJPETActorMessenger(GateJPETActor* sensor) : GateActorMessenger(sensor),pActor(sensor)
{
	 BuildCommands(baseName+sensor->GetObjectName());
}

GateJPETActorMessenger::~GateJPETActorMessenger()
{
	delete pEnableXPositionCmd;
	delete pEnableYPositionCmd;
	delete pEnableZPositionCmd;
	delete pEnableParticleNameCmd;
	delete pEnableParticleCmd;
	delete pEnableTrackIDCmd;
	delete pEnableEventIDCmd;
	delete pEnableParentIDCmd;
	delete pEnableRunIDCmd;
	delete pEnableEkinCmd;
	delete pEnableInteractionTimeCmd;
	delete pEnableProcessNameCmd;
	delete pEnableEmissionPointCmd;
	delete pEnablePrimaryEnergyCmd;
}

void GateJPETActorMessenger::BuildCommands(G4String base)
{
	G4String guidance;
	G4String bb;

	bb = base+"/enableXPosition";
	pEnableXPositionCmd = new G4UIcmdWithABool(bb,this);
	guidance = "Save position of particles along X axis in the phase space file.";
	pEnableXPositionCmd->SetGuidance(guidance);
	pEnableXPositionCmd->SetParameterName("State",false);

	bb = base+"/enableYPosition";
	pEnableYPositionCmd = new G4UIcmdWithABool(bb,this);
	guidance = "Save position of particles along Y axis in the phase space file.";
	pEnableYPositionCmd->SetGuidance(guidance);
	pEnableYPositionCmd->SetParameterName("State",false);

	bb = base+"/enableZPosition";
	pEnableZPositionCmd = new G4UIcmdWithABool(bb,this);
	guidance = "Save position of particles along Z axis in the phase space file.";
	pEnableZPositionCmd->SetGuidance(guidance);
	pEnableZPositionCmd->SetParameterName("State",false);

	bb = base+"/enableParticleName";
	pEnableParticleNameCmd = new G4UIcmdWithABool(bb,this);
	guidance = "Save the name of particles in the phase space file.";
	pEnableParticleNameCmd->SetGuidance(guidance);
	pEnableParticleNameCmd->SetParameterName("State",false);

	bb = base+"/enableParticle";
	pEnableParticleCmd =  new G4UIcmdWithAString(bb,this);
	guidance = "Save data only for choosed particle.";
	pEnableParticleCmd->SetGuidance(guidance);
	pEnableParticleCmd->SetParameterName("Particle Name",false);

	bb = base+"/enableTrackID";
	pEnableTrackIDCmd =  new G4UIcmdWithABool(bb,this);
	guidance = "Save track ID";
	pEnableTrackIDCmd->SetGuidance(guidance);
	pEnableTrackIDCmd->SetParameterName("State",false);

	bb = base+"/enableEventID";
	pEnableEventIDCmd =  new G4UIcmdWithABool(bb,this);
	guidance = "Save event ID";
	pEnableEventIDCmd->SetGuidance(guidance);
	pEnableEventIDCmd->SetParameterName("State",false);

	bb = base+"/enableParentID";
	pEnableParentIDCmd =  new G4UIcmdWithABool(bb,this);
	guidance = "Save parent ID";
	pEnableParentIDCmd->SetGuidance(guidance);
	pEnableParentIDCmd->SetParameterName("State",false);

	bb = base+"/enableRunID";
	pEnableRunIDCmd =  new G4UIcmdWithABool(bb,this);
	guidance = "Save run ID";
	pEnableRunIDCmd->SetGuidance(guidance);
	pEnableRunIDCmd->SetParameterName("State",false);

	bb = base+"/enableEkin";
	pEnableEkinCmd =  new G4UIcmdWithABool(bb,this);
	guidance = "Save particle kinetic energy";
	pEnableEkinCmd->SetGuidance(guidance);
	pEnableEkinCmd->SetParameterName("State",false);

	bb = base+"/enableInteractionTime";
	pEnableInteractionTimeCmd = new G4UIcmdWithABool(bb,this);
	guidance = "Save particle interaction time";
	pEnableInteractionTimeCmd->SetGuidance(guidance);
	pEnableInteractionTimeCmd->SetParameterName("State",false);

	bb = base+"/enableProcessName";
	pEnableProcessNameCmd = new G4UIcmdWithABool(bb,this);
	guidance = "Save process name";
	pEnableProcessNameCmd->SetGuidance(guidance);
	pEnableProcessNameCmd->SetParameterName("State",false);

	bb = base+"/enableEmissionPoint";
	pEnableEmissionPointCmd = new G4UIcmdWithABool(bb,this);
	guidance = "Save particle's emission point.";
	pEnableEmissionPointCmd->SetGuidance(guidance);
	pEnableEmissionPointCmd->SetParameterName("State",false);

	bb = base+"/enablePrimaryEnergy";
	pEnablePrimaryEnergyCmd = new G4UIcmdWithABool(bb,this);
	guidance = "Save particle's primary energy";
	pEnablePrimaryEnergyCmd->SetGuidance(guidance);
	pEnablePrimaryEnergyCmd->SetParameterName("State",false);
}

void GateJPETActorMessenger::SetNewValue(G4UIcommand* command, G4String param)
{
	if(command == pEnableXPositionCmd)
		pActor->SetXPositionEnabled(pEnableXPositionCmd->GetNewBoolValue(param));

	if(command == pEnableYPositionCmd)
		pActor->SetYPositionEnabled(pEnableYPositionCmd->GetNewBoolValue(param));

	if(command == pEnableZPositionCmd)
		pActor->SetZPositionEnabled(pEnableZPositionCmd->GetNewBoolValue(param));

	if(command == pEnableParticleNameCmd)
		pActor->SetParticleNameEnabled(pEnableParticleNameCmd->GetNewBoolValue(param));

	if(command ==pEnableParticleCmd)
		pActor->SetParticleEnabled(param);

	if(command == pEnableTrackIDCmd)
		pActor->SetTrackIDEnabled(pEnableTrackIDCmd->GetNewBoolValue(param));

	if(command == pEnableEventIDCmd)
		pActor->SetEventIDEnabled(pEnableEventIDCmd->GetNewBoolValue(param));

	if(command == pEnableParentIDCmd)
		pActor->SetParentIDEnabled(pEnableParentIDCmd->GetNewBoolValue(param));

	if(command == pEnableRunIDCmd)
		pActor->SetRunIDEnabled(pEnableRunIDCmd->GetNewBoolValue(param));

	if(command == pEnableEkinCmd)
		pActor->SetEkinEnabled(pEnableEkinCmd->GetNewBoolValue(param));

	if(command == pEnableInteractionTimeCmd)
		pActor->SetInteractionTimeEnabled(pEnableInteractionTimeCmd->GetNewBoolValue(param));

	if(command == pEnableProcessNameCmd)
		pActor->SetProcessNameEnabled(pEnableProcessNameCmd->GetNewBoolValue(param));

	if(command == pEnableEmissionPointCmd)
		pActor->SetEmissionPointEnabled(pEnableEmissionPointCmd->GetNewBoolValue(param));

	if(command == pEnablePrimaryEnergyCmd)
		pActor->SetPrimaryEnergy(pEnablePrimaryEnergyCmd->GetNewBoolValue(param));

	GateActorMessenger::SetNewValue(command ,param );
}
#endif
