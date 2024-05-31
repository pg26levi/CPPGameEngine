#include "Engine/Public/EngineTypes.h"

Matrix4 Matrix4::Translate(const Matrix4& inMat, const glm::vec3& inVec)
{

	Matrix4 outMat = inMat;

	outMat.m[0][3] = inVec.x;
	outMat.m[1][3] = inVec.y;
	outMat.m[2][3] = inVec.z;
	outMat.m[3][3] = 1.0f;

	return outMat;

}