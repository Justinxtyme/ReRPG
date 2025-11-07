#include "Progression.h"


int32 UProgressionComponent::GetLevelFromXP(int32 XP) const
{
	for (const FLevelThreshold& Entry : ProgressionData->LevelEntries)
	{
		if (XP >= Entry.XPMin && XP <= Entry.XPMax)
		{
			return Entry.Level;
		}
	}
	return Level; // fallback: no change
}

/*
  * Binary search version if i decide on high lvl cap (100's to 1000's)
 
int32 UProgressionComponent::GetLevelFromXP(int32 XP) const
{
  int32 Low = 0;
  int32 High = ProgressionData->LevelEntries.Num() - 1;

  while (Low <= High)
  {
	  int32 Mid = (Low + High) / 2;
	  const FLevelThreshold& Entry = ProgressionData->LevelEntries[Mid];

	  if (XP >= Entry.XPMin && XP <= Entry.XPMax)
	  {
		  return Entry.Level;
	  }
	  else if (XP < Entry.XPMin)
	  {
		  High = Mid - 1;
	  }
	  else // XP > Entry.XPMax
	  {
		  Low = Mid + 1;
	  }
  }

  return CurrentLevel; // fallback
}
*/
