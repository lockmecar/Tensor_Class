#pragma once
#include "tensor.h"

class Layer
{
public:
	virtual void printNeurones() = 0;
	virtual std::vector<float> getNeurones() = 0;
	virtual void setNeurones(std::vector<float>) = 0;

private:
	std::vector<float> listNeurones;
	
};

class InLayer : Layer
{
public:
	InLayer(Ten3D A);
	void printNeurones() override;
	std::vector<float> getNeurones() override;
	void setNeurones(std::vector<float>) override;

private:
	int size;
	std::vector<float> listNeurones;
};


class OutLayer : Layer
{
public:
	void printNeurones() override;
	std::vector<float> getNeurones() override;
	void setNeurones(std::vector<float>) override;

private:
	std::vector<float> listNeurones;
};


class HideLayer : Layer
{
public:
	void printNeurones() override;
	std::vector<float> getNeurones() override;
	void setNeurones(std::vector<float>) override;

private:
	std::vector<float> listNeurones;
};