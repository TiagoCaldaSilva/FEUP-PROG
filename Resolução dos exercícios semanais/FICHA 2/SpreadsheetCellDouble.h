#pragma once
#include "SpreadsheetCell.h"

//19.a_b
//class SpreadsheetCellDouble: public SpreadsheetCell
//{
//public:
//	SpreadsheetCellDouble() { cell = 0; };
//	virtual ~SpreadsheetCellDouble() {};
//	virtual void set(const std::string& inString);
//	virtual std::string getString() const;
//private:
//	double cell;
//};
//19.c
//class SpreadsheetCellDouble : public SpreadsheetCell
//{
//public:
//	SpreadsheetCellDouble() { cell = 0; };
//	virtual ~SpreadsheetCellDouble() {};
//	virtual void set(const double& n) { cell = n; };
//	virtual double getCell() const {return cell;};
//private:
//	double cell;
//};