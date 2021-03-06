/////////////////////////////////////////////////////////////////////////////////
/// Copyright (C), 2017-2017, xizaixuan. All rights reserved.
/// \brief   数学常量及算法
/// \author  xizaixuan
/// \date    2017-08
/////////////////////////////////////////////////////////////////////////////////
#ifndef _MathUtil_H_
#define _MathUtil_H_

#include <math.h>
#include "float2.h"
#include "float3.h"
#include "float4.h"
#include "Matrix.h"
#include <limits>

namespace MathUtil
{
	const float epsilon = std::numeric_limits<float>::epsilon();
	const float maxValue = FLT_MAX;
	const float minValue = FLT_MIN;
	const float pi = ((float)3.141592654f);

	float AngelToRadian(float ang);
	float RadianToAngel(float rads);

	/// brief 求向量长度
	float Length(const float2& v);
	float Length(const float3& v);
	float Length(const float4& v);

	/// brief 单位化
	float2 Normalize(float2 v);
	float3 Normalize(float3 v);
	float4 Normalize(float4 v);

	/// brief 求两向量的叉积
	float2 Cross(const float2& a, const float2& b);
	float3 Cross(const float3& a, const float3& b);

	/// brief 比较两个浮点数是否相等
	bool IsEqual(float a, float b);

	Matrix Inverse(Matrix mat);

	float4 Homogenous(float4& value);

	template<typename T>
	static T Clamp(const T& x, const T& low, const T& high)
	{
		return x < low ? low : (x > high ? high : x);
	}
}

#endif
