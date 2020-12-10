#pragma once
#include "Spell.h"
#include "GameObject.h"

class Champion : public GameObject {

public:

	Champion()
		: Q(Spell(SpellSlot::Q)),
		W(Spell(SpellSlot::W)),
		E(Spell(SpellSlot::E)),
		R(Spell(SpellSlot::R)),
		D(Spell(SpellSlot::D)),
		F(Spell(SpellSlot::F)) {
	}

	void    LoadFromMem(DWORD_PTR base, HANDLE hProcess);
	float   GetBasicAttackDamage();
	Spell*  GetSummonerSpell(SummonerSpellType type);

public:
	float   currentHealth;

	Spell   Q, W, E, R, D, F;

private:
	// Prealocated buffer
	DWORD   spellSlotPtrs[6];
};