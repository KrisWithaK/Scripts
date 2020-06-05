#pragma once


struct Vec2 {

	Vec2() = default;
	Vec2(float x_in, float y_in);

	Vec2 operator + (const Vec2 rhs) const;
	Vec2& operator += (const Vec2 rhs);
	Vec2 operator * (const float rhs) const;
	Vec2& operator *= (const float rhs);


};