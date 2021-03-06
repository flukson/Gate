/**
 *  @copyright Copyright 2016 The J-PET Gate Authors. All rights reserved.
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  @fileGateJPETOrtoPositroniumDecayModel.hh
 */

#ifndef GATEJPETORTOPOSITRONIUMDECAYMODEL_HH
#define GATEJPETORTOPOSITRONIUMDECAYMODEL_HH

#include "GateGammaSourceModel.hh"
#include "TRandom3.h"

/**Author: Mateusz Bała
 * Email: bala.mateusz@gmail.com
 * Theorem author: Daria Kamińska
 * About class: Provide generation of 3 gamma from orto Positronium decay
 * */
class GateJPETOrtoPositroniumDecayModel : public GateGammaSourceModel
{
	public:
		GateJPETOrtoPositroniumDecayModel();
		virtual ~GateJPETOrtoPositroniumDecayModel();
		virtual void GetGammaParticles(std::vector<G4PrimaryParticle*>& particles);
	private:
		Double_t calculate_mQED(Double_t mass_e, Double_t w1, Double_t w2, Double_t w3);
	private:
		TRandom3 m_random_gen;


};

#endif
