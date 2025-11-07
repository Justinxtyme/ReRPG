#pragma once

#include "ResourceData.h"
#include "component.h"

inline ResourceComponent UnrealResToEcs(const FResourceComponent &Res)
{
	const ResourceComponent Resources(Res.HP, Res.SP, Res.MP, Res.MaxHP, Res.MaxSP, Res.MaxMP);
	return Resources;
}

inline FResourceComponent EcsToUnrealRes(const ResourceComponent &Res)
{
	FResourceComponent Ures;
	
	Ures.HP = Res.hp;
	Ures.SP = Res.sp;
	Ures.MP = Res.mp;
	Ures.MaxHP = Res.max_hp;
	Ures.MaxSP = Res.max_sp;
	Ures.MaxMP = Res.max_mp;
	
	return Ures;
}

inline void EcsToUnrealRes2(const ResourceComponent &Res, UResourcesComponent &Ures)
{
	
	Ures.HP = static_cast<double>(Res.hp);
	Ures.SP = static_cast<double>(Res.sp);
	Ures.MP = static_cast<double>(Res.mp);
	Ures.MaxHP = static_cast<double>(Res.max_hp);
	Ures.MaxSP = static_cast<double>(Res.max_sp);
	Ures.MaxMP = static_cast<double>(Res.max_mp);
	
	//return Ures;
}

inline ResourceComponent UnrealRes2ToEcs(const UResourcesComponent &Res)
{
	const ResourceComponent Resources(Res.HP, Res.SP, Res.MP, Res.MaxHP, Res.MaxSP, Res.MaxMP);
	return Resources;
}