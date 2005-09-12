#include "precompiled.h"

// TODO: organise things better, rather than sticking them in Misc

#include "Messages.h"

#include "Vector3D.h"
#include "Game.h"

void AtlasMessage::Position::GetWorldSpace(CVector3D& vec) const
{
	switch (type)
	{
	case 0:
		vec.Set(type0.x, type0.y, type0.z);
		break;

	case 1:
		vec = g_Game->GetView()->GetCamera()->GetWorldCoordinates(type1.x, type1.y);
		break;

	default:
		debug_warn("Invalid Position type");
		vec.Set(0.f, 0.f, 0.f);
	}
}
