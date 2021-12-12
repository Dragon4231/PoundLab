#pragma once
class Score
{
private:
	int shilling;
	int pound;
	double penny;
	void recount();
public:
	Score(int a, int b, double p);
	Score();
	Score(int a, int b, double p, char operat);
	void setdPound(int p);
	void setShilling(int sh);
	void setPenny(double p);
	void PrintInfo();
	Score operator + (const Score& p) const;
	Score operator - () const;
	Score operator - (const Score& p) const;
	friend void operator += (Score& p, Score& l) ;
	friend void operator -= (Score& p, Score& l);
	bool operator>=(const Score& p) const;
	bool operator <= (const Score& p) const;
	bool operator > (const Score& p) const;
	bool operator < (const Score& p) const;
	bool operator != (const Score& p) const;
	bool operator ==(const Score& p);
};

