#pragma once
#include <string>
enum MinerName
{
	Miner_Bob,
	Elsa
};
inline std::string GetNameOfEntity(int n)
{
	switch (n)
	{
	case Miner_Bob:
		return "Miner_Bob";
	case Elsa:
		return "Elsa";
	default:
		return "Unknown!";
	}
}