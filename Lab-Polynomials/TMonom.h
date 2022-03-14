#pragma once
struct TMonom
{
	double coef;
	int x, y, z;

	TMonom()
	{
		this->coef = 0;
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	TMonom(double coef, int x, int y, int z)
	{
		this->coef = coef;
		this->x = x;
		this->y = y;
		this->z = z;
	}

	bool operator==(const TMonom& m)
	{
		return x == m.x && y == m.y && z == m.z;
	}
	bool operator!=(const TMonom& m)
	{
		if (*this == m)return 0;
		else return 1;
	}
	
	bool operator>(const TMonom& m)
	{
		if (x > m.x) return true;
		else if (x == m.x && y > m.y) return true;
		else if (x == m.x && y == m.y && z > m.z) return true;
		return false;
	}

	bool operator<(const TMonom& m)
	{
		if (x < m.x) return true;
		else if (x == m.x && y < m.y) return true;
		else if (x == m.x && y == m.y && z < m.z) return true;
		return false;
	}
	bool EqualCoef(const TMonom& m)
	{
		return x == m.x && y == m.y && z == m.z && coef == m.coef;
	}
	friend istream& operator>>(istream& in, TMonom& m)
	{
		int pxyz;
		cout << "коэффициент = ";
		in >> m.coef;
		cout << endl << " степени XYZ = ";
		in >> pxyz;
		m.x = pxyz / 100;
		m.y = pxyz / 10 % 10;
		m.z = pxyz % 10;
		return in;
	}
	friend ostream& operator<<(ostream& out, const TMonom& m)
	{
		out << m.coef << "(x^" << m.x << ")" << "(y^" << m.y << ")" << "(z^" << m.z << ")";
		return out;
	}
};