#ifndef LIFEFORM_H_
#define LIFEFORM_H_

#ifdef _WIN32
#include "windows.h"
#endif //_WIN32W
#include "../system/graphic/StaticObject.h"

class LifeForm: public Object {
private:
	int m_lastAttackTime;
	float m_health;
public:
	enum LifeFormType {
		player = 0, monster
	};
	enum LifeFormState {
		alive = 0, smitten, dying, died
	};
	LifeForm(float x, float y, int w, int h);
	virtual void process(int deltaTime);
	virtual void draw();

	std::string Id;
	std::string Name;
	int Level;
	float Strength;
	float Agility;
	float Vitality;
	float TargetX, TargetY;
	LifeFormState State;
	void setHealth(float value);
	virtual float getStrength();
	virtual float getAgility();
	virtual float getVitality();
	const float getHealth();
	const float MaxHealth();
	const float MaxSpeed();
	const float ChanceToEvade();
	const bool Attack();
	const float Damage();
	const int AttackDelay();
	const float ReloadSpeedMod();
	const float WeaponRetForceMod();
	const float HealthRegen();
	LifeForm::LifeFormType Type;
	virtual StaticObject* getCorpse();
	bool Poisoned;
	int Frozen;
};

#endif /* LIFEFORM_H_ */
