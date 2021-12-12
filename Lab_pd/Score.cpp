#include "Score.h"
#include <iostream>
#include <Math.h>
using namespace std;

void Score::recount()
{
	double all = (double)shilling * 12 + (double)pound * 20 * 12 + penny;
	pound = all / 240;
	all = all - (double)pound * 240;
	shilling = all / 12;
	all = all - (double)shilling * 12;
	penny = all;
	/* if (penny >= 12) {
		shilling += penny / 12;
		int t = penny / 12;
		penny = penny - (t * 12);
	}
	if (shilling >= 20) {
		pound += shilling / 20;
		shilling = shilling % 20;
	} */
}


Score::Score(int a, int b, double p)
{
	if (b > 20 || p > 12 ) throw exception("error:value isn't correct");
	pound = a;
	shilling = b;
	penny = p;
	/*
	setdPound(a);
	setShilling(b);
	setPenny(p); */
}

Score::Score()
{
	pound = 0;
	shilling = 0;
	penny = 0;
}

Score::Score(int a, int b, double p, char operat)
{
	pound = a;
	shilling = b;
	penny = p;
	/* setdPound(a);
	setShilling(b);
	setPenny(p); */
	recount();
}

void Score::setdPound(int p)
{
	pound = p;
	recount();
}

void Score::setShilling(int sh)
{
	shilling = sh;
	recount();
}

void Score::setPenny(double p)
{
	penny = p;
	recount();
}

void Score::PrintInfo()
{
	cout << pound << "pd." << shilling << "sh." << penny << "p." << endl;
}

Score Score::operator+(const Score& p) const
{
	return Score(pound + p.pound, shilling + p.shilling, penny + p.penny, '+');
}

Score Score::operator-() const
{
	return Score(-pound, -shilling, -penny);
}

Score Score::operator-(const Score& p) const
{
	double all = (double)shilling * 12 + (double)pound * 20 * 12 + penny;
	double all1 = (double)p.shilling * 12 + (double)p.pound * 20 * 12 + p.penny;
	all = all - all1;
	int shilling;
	int pound;
	double penny;
	pound = all / 240;
	all = all - (double)pound * 240;
	shilling = all / 12;
	all = all - (double)shilling * 12;
	penny = all;
	return Score(pound,shilling,penny);
}
bool Score::operator>=(const Score& p) const
{
	double all = (double)shilling * 12 + (double)pound * 20 * 12 + penny;
	double all1 = (double)p.shilling * 12 + (double)p.pound * 20 * 12 + p.penny;
	if ( (all - all1) >= 0 ) return true;
	else return false;
}

bool Score::operator<=(const Score& p) const
{
	double all = (double)shilling * 12 + (double)pound * 20 * 12 + penny;
	double all1 = (double)p.shilling * 12 + (double)p.pound * 20 * 12 + p.penny;
	if ((all1 - all) >= 0) return true;
	else return false;
}

bool Score::operator>(const Score& p) const
{
	double all = (double)shilling * 12 + (double)pound * 20 * 12 + penny;
	double all1 = (double)p.shilling * 12 + (double)p.pound * 20 * 12 + p.penny;
	if ((all - all1) > 0) return true;
	else return false;
}

bool Score::operator<(const Score& p) const
{
	double all = (double)shilling * 12 + (double)pound * 20 * 12 + penny;
	double all1 = (double)p.shilling * 12 + (double)p.pound * 20 * 12 + p.penny;
	if ((all1 - all) > 0) return true;
	else return false;
}

bool Score::operator!=(const Score& p) const
{
	double all = (double)shilling * 12 + (double)pound * 20 * 12 + penny;
	double all1 = (double)p.shilling * 12 + (double)p.pound * 20 * 12 + p.penny;
	if ( all1 != all ) return true;
	else return false;
}

bool Score::operator==(const Score& p)
{
	double all = (double)shilling * 12 + (double)pound * 20 * 12 + penny;
	double all1 = (double)p.shilling * 12 + (double)p.pound * 20 * 12 + p.penny;
	if ( all == all1 ) return true;
	else return false;
}


void operator+=(Score& p, Score& l) 
{
	p.pound += l.pound;
	p.shilling += l.shilling;
	p.penny += l.penny;
	p.recount();
}

void operator-=(Score& p, Score& l)
{
	double all = (double)l.shilling * 12 + (double)l.pound * 20 * 12 + l.penny;
	double all1 = (double)p.shilling * 12 + (double)p.pound * 20 * 12 + p.penny;
	all = all1 - all;
	p.pound = all / 240;
	all = all - (double)p.pound * 240;
	p.shilling = all / 12;
	all = all - (double)p.shilling * 12;
	p.penny = all;
}
