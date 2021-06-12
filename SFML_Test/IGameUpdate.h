#pragma once
class IGameUpdate
{
	virtual void CheckInput() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};

