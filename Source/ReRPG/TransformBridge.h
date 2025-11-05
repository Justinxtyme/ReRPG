// // TransformBridge.h
// #pragma once
// #include "TransformData.h"
// #include "TransformComponent.h"
//
// inline TransformComponent UnrealTransToECS(const FCTransformDater& Data)
// {
// 	return {
// 		glm::vec3(Data.Position.X, Data.Position.Y, Data.Position.Z),
// 		glm::quat(Data.Rotation.W, Data.Rotation.X, Data.Rotation.Y, Data.Rotation.Z),
// 		glm::vec3(Data.Scale.X, Data.Scale.Y, Data.Scale.Z)
// 	};
// }
//
// inline FCTransformDater EcsToUnreal(const TransformComponent& Comp)
// {
// 	FCTransformDater Data;
// 	Data.Position = FVector(Comp.Position.x, Comp.Position.y, Comp.Position.z);
// 	Data.Rotation = FQuat(Comp.Rotation.x, Comp.Rotation.y, Comp.Rotation.z, Comp.Rotation.w);
// 	Data.Scale    = FVector(Comp.Scale.x, Comp.Scale.y, Comp.Scale.z);
// 	return Data;
// }