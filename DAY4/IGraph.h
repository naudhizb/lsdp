// IGraph.h
#pragma once

struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}
};
