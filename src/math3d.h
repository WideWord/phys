#include "memory.h"
#include <cmath>


class vec3
{
public:
    inline vec3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
    float x, y, z;

    inline vec3 operator+(const vec3& other) {
        return vec3(x + other.x, y + other.y, z + other.z);
    }

    inline vec3 operator-(const vec3& other) {
        return vec3(x - other.x, y - other.y, z - other.z);
    }

    inline vec3 operator*(float other) {
        return vec3(x * other, y * other, z * other);
    }

    inline vec3 operator/(float other) {
        return vec3(x / other, y / other, z / other);
    }

    inline void operator+=(vec3 other) {
        x += other.x;
        y += other.y;
        z += other.z;
    }

    inline void operator-=(vec3 other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
    }

    inline void operator*=(float other) {
        x *= other;
        y *= other;
        z *= other;
    }

    inline void operator/=(float other) {
        x /= other;
        y /= other;
        z /= other;
    }

    inline float operator*(vec3 other) {
        return x * other.x + y * other.y + z * other.z;
    }

    inline vec3 cross(vec3 b) {
        return vec3(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x);
    }
    
    inline vec3 operator-() {
		return vec3(-x, -y, -z);
	}
};

class quat {
public:
    vec3 v;
    float w;
    float& x;
    float& y;
    float& z;

    inline quat(float x = 0, float y = 0, float z = 0, float w = 1)
        : v(x, y, z), w(w), x(v.x), y(v.y), z(v.z) {}

    inline quat(const vec3& cv, float w = 1) : v(cv), w(w), x(v.x), y(v.y), z(v.z) {}

    inline quat operator*(quat other)
    {
        return quat(v.cross(other.v) + v * other.w + other.v * w, w * other.w - v * other.v);
    }

    inline void operator*= (quat other)
    {
        vec3 vx(v);
        v = vx.cross(other.v) + vx * other.w + other.v * w;
        w = w * other.w - vx * other.v;

    }
    
    inline quat normalize () {
		float t = sqrt(x*x+y*y+z*z+w*w);
		return quat(x / t, y / t, z / t , w / t );
	}
	
	

	static inline quat euler(vec3 v) {
		float c1 = cosf(v.x);
		float s1 = sinf(v.x);
		float c2 = cosf(v.y);
		float s2 = sinf(v.y);
		float c3 = cosf(v.z);
		float s3 = sinf(v.z);
		quat res;
		float w = sqrt(1.0 + c1 * c2 + c1*c3 - s1 * s2 * s3 + c2*c3) / 2.0;
		float w4 = (4.0 * w);
		res.x = (c2 * s3 + c1 * s3 + s1 * s2 * c3) / w4 ;
		res.y = (s1 * c2 + s1 * c3 + c1 * s2 * s3) / w4 ;
		res.z = (-s1 * s3 + c1 * s2 * c3 +s2) / w4 ;
		res.w = w;
		return res;		
	}
};


class mat4 {
private:
    float* mtx;
public:

	static inline mat4 perspective(float fovy, float aspect, float znear, float zfar)
	{
		float f = 1 / tanf(fovy * 3.14 / 360),
		A = (zfar + znear) / (znear - zfar),
		B = (2 * zfar * znear) / (znear - zfar);
		mat4 M;
		M[ 0] = f / aspect; M[ 1] = 0; M[ 2] = 0; M[ 3] = 0;
		M[ 4] = 0; M[ 5] = f; M[ 6] = 0; M[ 7] = 0;
		M[ 8] = 0; M[ 9] = 0; M[10] = A; M[11] = B;
		M[12] = 0; M[13] = 0; M[14] = -1; M[15] = 0;
		return std::move(M);
	}
	
	static inline mat4 translation(vec3 vec) {
		mat4 mtx;
		mtx[ 0] = 1; mtx[ 1] = 0; mtx[ 2] = 0; mtx[ 3] = vec.x;
        mtx[ 4] = 0; mtx[ 5] = 1; mtx[ 6] = 0; mtx[ 7] = vec.y;
        mtx[ 8] = 0; mtx[ 9] = 0; mtx[10] = 1; mtx[11] = vec.z;
        mtx[12] = 0; mtx[13] = 0; mtx[14] = 0; mtx[15] = 1;
		return mtx;
	}
	
	static inline mat4 rotation(quat q) {
		q.normalize();
		mat4 mtx;
		mtx[0] = q.w;	mtx[1] = q.z;	mtx[2] = -q.y;	mtx[3] = q.x;
		mtx[4] = -q.z;	mtx[5] = q.w;	mtx[6] = q.x;	mtx[7] = q.y;
		mtx[8] = q.y;	mtx[9]=-q.x;	mtx[10]=q.w; mtx[11]=q.z;
		mtx[12]=-q.x;	mtx[13]=-q.y;	mtx[14]=-q.z;	mtx[15]=q.w;

		mat4 m;


		m[0] = q.w;	m[1] = q.z;	m[2] = -q.y;	m[3] = q.x;
		m[4] = -q.z;	m[5] = q.w;	m[6] = q.x;	m[7] = -q.y;
		m[8] = q.y;	m[9]=-q.x;	m[10]=q.w; m[11]=-q.z;
		m[12]=q.x;	m[13]=q.y;	m[14]=q.z;	m[15]=q.w;

		mtx *= m;
		return mtx;
	}

    inline mat4()
    {
        mtx = new float[16];
    }

    inline ~mat4()
    {
        delete mtx;
    }

    inline mat4(const mat4& other) {
        mtx = new float[16];
        memcpy(mtx, other.mtx, sizeof(float) * 16);
    }



	inline float* ptr() {
		return mtx;
	}

    inline mat4(mat4&& other)
    {
        mtx = new float[16];
        memcpy(mtx, other.mtx, sizeof(float) * 16);
    }

    inline float& operator[] (int id)
    {
        return mtx[id];
    }

    inline mat4 operator*(mat4 other)
    {

        mat4 M;
        M[ 0] = mtx[ 0] * other[ 0] + mtx[ 1] * other[ 4] + mtx[ 2] * other[ 8] + mtx[ 3] * other[12];
        M[ 1] = mtx[ 0] * other[ 1] + mtx[ 1] * other[ 5] + mtx[ 2] * other[ 9] + mtx[ 3] * other[13];
        M[ 2] = mtx[ 0] * other[ 2] + mtx[ 1] * other[ 6] + mtx[ 2] * other[10] + mtx[ 3] * other[14];
        M[ 3] = mtx[ 0] * other[ 3] + mtx[ 1] * other[ 7] + mtx[ 2] * other[11] + mtx[ 3] * other[15];
        M[ 4] = mtx[ 4] * other[ 0] + mtx[ 5] * other[ 4] + mtx[ 6] * other[ 8] + mtx[ 7] * other[12];
        M[ 5] = mtx[ 4] * other[ 1] + mtx[ 5] * other[ 5] + mtx[ 6] * other[ 9] + mtx[ 7] * other[13];
        M[ 6] = mtx[ 4] * other[ 2] + mtx[ 5] * other[ 6] + mtx[ 6] * other[10] + mtx[ 7] * other[14];
        M[ 7] = mtx[ 4] * other[ 3] + mtx[ 5] * other[ 7] + mtx[ 6] * other[11] + mtx[ 7] * other[15];
        M[ 8] = mtx[ 8] * other[ 0] + mtx[ 9] * other[ 4] + mtx[10] * other[ 8] + mtx[11] * other[12];
        M[ 9] = mtx[ 8] * other[ 1] + mtx[ 9] * other[ 5] + mtx[10] * other[ 9] + mtx[11] * other[13];
        M[10] = mtx[ 8] * other[ 2] + mtx[ 9] * other[ 6] + mtx[10] * other[10] + mtx[11] * other[14];
        M[11] = mtx[ 8] * other[ 3] + mtx[ 9] * other[ 7] + mtx[10] * other[11] + mtx[11] * other[15];
        M[12] = mtx[12] * other[ 0] + mtx[13] * other[ 4] + mtx[14] * other[ 8] + mtx[15] * other[12];
        M[13] = mtx[12] * other[ 1] + mtx[13] * other[ 5] + mtx[14] * other[ 9] + mtx[15] * other[13];
        M[14] = mtx[12] * other[ 2] + mtx[13] * other[ 6] + mtx[14] * other[10] + mtx[15] * other[14];
        M[15] = mtx[12] * other[ 3] + mtx[13] * other[ 7] + mtx[14] * other[11] + mtx[15] * other[15];

        return M;
    }

    inline void operator*=(mat4 B) {
        float* A = new float[16];
        memcpy(A, mtx, sizeof(float) * 16);

        mtx[ 0] = A[ 0] * B[ 0] + A[ 1] * B[ 4] + A[ 2] * B[ 8] + A[ 3] * B[12];
        mtx[ 1] = A[ 0] * B[ 1] + A[ 1] * B[ 5] + A[ 2] * B[ 9] + A[ 3] * B[13];
        mtx[ 2] = A[ 0] * B[ 2] + A[ 1] * B[ 6] + A[ 2] * B[10] + A[ 3] * B[14];
        mtx[ 3] = A[ 0] * B[ 3] + A[ 1] * B[ 7] + A[ 2] * B[11] + A[ 3] * B[15];
        mtx[ 4] = A[ 4] * B[ 0] + A[ 5] * B[ 4] + A[ 6] * B[ 8] + A[ 7] * B[12];
        mtx[ 5] = A[ 4] * B[ 1] + A[ 5] * B[ 5] + A[ 6] * B[ 9] + A[ 7] * B[13];
        mtx[ 6] = A[ 4] * B[ 2] + A[ 5] * B[ 6] + A[ 6] * B[10] + A[ 7] * B[14];
        mtx[ 7] = A[ 4] * B[ 3] + A[ 5] * B[ 7] + A[ 6] * B[11] + A[ 7] * B[15];
        mtx[ 8] = A[ 8] * B[ 0] + A[ 9] * B[ 4] + A[10] * B[ 8] + A[11] * B[12];
        mtx[ 9] = A[ 8] * B[ 1] + A[ 9] * B[ 5] + A[10] * B[ 9] + A[11] * B[13];
        mtx[10] = A[ 8] * B[ 2] + A[ 9] * B[ 6] + A[10] * B[10] + A[11] * B[14];
        mtx[11] = A[ 8] * B[ 3] + A[ 9] * B[ 7] + A[10] * B[11] + A[11] * B[15];
        mtx[12] = A[12] * B[ 0] + A[13] * B[ 4] + A[14] * B[ 8] + A[15] * B[12];
        mtx[13] = A[12] * B[ 1] + A[13] * B[ 5] + A[14] * B[ 9] + A[15] * B[13];
        mtx[14] = A[12] * B[ 2] + A[13] * B[ 6] + A[14] * B[10] + A[15] * B[14];
        mtx[15] = A[12] * B[ 3] + A[13] * B[ 7] + A[14] * B[11] + A[15] * B[15];

        delete A;
    }
    
    inline float* operator*() {
		return mtx;
	}
};

class vec2
{
public:
    inline vec2(float x = 0, float y = 0) : x(x), y(y) {}
    float x, y;

    inline vec2 operator+(const vec2& other) {
        return vec2(x + other.x, y + other.y);
    }

    inline vec2 operator-(const vec2& other) {
        return vec2(x - other.x, y - other.y);
    }

    inline vec2 operator*(float other) {
        return vec2(x * other, y * other);
    }

    inline vec2 operator/(float other) {
        return vec2(x / other, y / other);
    }

    inline void operator+=(vec2 other) {
        x += other.x;
        y += other.y;
    }

    inline void operator-=(vec2 other) {
        x -= other.x;
        y -= other.y;
    }

    inline void operator*=(float other) {
        x *= other;
        y *= other;
    }

    inline void operator/=(float other) {
        x /= other;
        y /= other;
    }

    inline float operator*(vec2 other) {
        return x * other.x + y * other.y;
    }
};





