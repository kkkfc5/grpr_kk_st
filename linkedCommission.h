#pragma once

#ifndef LINKEDCOMMISSION_H
#define LINKEDCOMMISSION_H

#include "linkedList.h"
#include "Commission.h"

class linkedCommission : public Linked<Commission> {
public:
	void addByPrice (Commission d);
	void addByPriority(Commission d);

	void delNode(int comisID);

	bool hasCommissionID(int searchID);

	void setPriority(int comisID, int priority);
	void setProgress(int comisID, int progress);
	void setFinished(int comisID);
	
	void sortPrice(char filterFinished);
	void sortPriority(char filterFinished);


	void printPrice(char filterFinished);
	void printPriority(char filterFinished);


	void saveFile();
};

#endif